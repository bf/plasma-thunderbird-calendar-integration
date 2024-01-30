#!/usr/bin/env python

import sys
import json
import struct
import threading
import queue
import dbus
import dbus.service
import dbus.mainloop.glib
from gi.repository import GLib

import logging
import os


# Encode a message for transmission
def encodeMessage(messageContent):
    encodedContent = json.dumps(messageContent, separators=(',', ':')).encode('utf-8')
    encodedLength = struct.pack('@I', len(encodedContent))
    return {'length': encodedLength, 'content': encodedContent}

# Send an encoded message to stdout
def sendMessage(stdout, encodedMessage):
    stdout.buffer.write(encodedMessage['length'])
    stdout.buffer.write(encodedMessage['content'])
    stdout.buffer.flush()

# thread to listen on stdin
def stdin_listener(stdin, queue, logging):
    logging.debug("STDIN Listener Thread Started")

    # Read a message from stdin and decode it.
    def getMessage():
        rawLength = stdin.buffer.read(4)
        if len(rawLength) == 0:
            sys.exit(0)
        messageLength = struct.unpack('@I', rawLength)[0]
        message = stdin.buffer.read(messageLength).decode('utf-8')

        logging.debug("getMessage %s", message)
        return json.loads(message)

    while True:        
        receivedMessage = getMessage()
        logging.debug("receivedMessage %s", receivedMessage)
        queue.put(receivedMessage)



def dbus_listener(stdout, queue_search_results, logging):
    global calendarsFromThunderbird
    logging.debug("D-Bus Listener Thread Started")

    class ThunderbirdService(dbus.service.Object):
        def __init__(self, bus_name, object_path):
            dbus.service.Object.__init__(self, bus_name, object_path)

        @dbus.service.method('org.kde.plasma.thunderbird_integration', in_signature='', out_signature='s')
        def HelloWorld(self):
            logging.debug("HelloWorld method called")
            return "Hello, World!"

        @dbus.service.method('org.kde.plasma.thunderbird_integration', in_signature='', out_signature='a(sss)')
        def GetCalendars(self):
            global calendarsFromThunderbird
            logging.debug("GetCalendars called")
            logging.debug("GetCalendars returning %s", calendarsFromThunderbird)
            return calendarsFromThunderbird

        @dbus.service.method('org.kde.plasma.thunderbird_integration', in_signature='ii', out_signature='a(ssssss)')
        def GetEventsInDateRange(self, from_date, to_date):
            logging.debug("GetEventsInDateRange from from: %s  to: %s", from_date, to_date)

            logging.debug("GetEventsInDateRange set event")
            sendMessage(stdout, encodeMessage({ "action": "search", "from": from_date, "to": to_date }))
            
            lastSearchResultFromThunderbird = queue_search_results.get()
            logging.debug("GetEventsInDateRange proceed after event!")
            logging.debug("GetEventsInDateRange lastSearchResultFromThunderbird %s", lastSearchResultFromThunderbird)

            return lastSearchResultFromThunderbird

        @dbus.service.method('org.kde.plasma.thunderbird_integration', in_signature='a(s)ii', out_signature='a(ssssss)')
        def GetEventsInDateRangeFromCalendars(self, arr_calendar_ids, from_date, to_date):
            logging.debug("GetEventsInDateRangeFromCalendars from calendars: %s from: %s  to: %s", arr_calendar_ids, from_date, to_date)

            logging.debug("GetEventsInDateRangeFromCalendars set event")
            sendMessage(sys.stdout, encodeMessage({ "action": "search", "arr_calendar_ids": arr_calendar_ids, "from": from_date, "to": to_date }))
            
            lastSearchResultFromThunderbird = queue_search_results.get()
            logging.debug("GetEventsInDateRangeFromCalendars proceed after event!")
            logging.debug("GetEventsInDateRangeFromCalendars lastSearchResultFromThunderbird %s", lastSearchResultFromThunderbird)

            return lastSearchResultFromThunderbird


    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
    session_bus = dbus.SessionBus()
    bus_name = dbus.service.BusName('org.kde.plasma.thunderbird_integration', session_bus)

    obj = ThunderbirdService(bus_name, '/org/kde/plasma/thunderbird_integration')

    loop = GLib.MainLoop()
    loop.run()


if __name__ == "__main__":
    logging.basicConfig(filename="/tmp/thunderbird-host-app.log", filemode="w", level=logging.DEBUG)


    # queue incoming messages received from thunderbird
    queue_thunderbird_incoming = queue.Queue()

    # queue for incoming search results
    queue_search_results = queue.Queue(maxsize=1)

    # global variable that holds the calendars
    calendarsFromThunderbird = None

    # Thread for listening to stdin
    stdin_thread = threading.Thread(target=stdin_listener, args=(sys.stdin, queue_thunderbird_incoming, logging))
    stdin_thread.start()

    # Thread for listening to D-Bus messages
    dbus_thread = threading.Thread(target=dbus_listener, args=(sys.stdout, queue_search_results, logging))
    dbus_thread.start()

    while True:
        try:
            messageFromThunderbird = queue_thunderbird_incoming.get_nowait()
            logging.debug("messageFromThunderbird %s", messageFromThunderbird)

            if messageFromThunderbird == "ping":
                sendMessage(sys.stdout, encodeMessage("pong4"))
            elif "calendars" in messageFromThunderbird:
                logging.debug("received calendars %s", messageFromThunderbird["calendars"])
                calendarsFromThunderbird = messageFromThunderbird["calendars"]
            elif "events" in messageFromThunderbird:
                logging.debug("received events %s", messageFromThunderbird["events"])
                queue_search_results.put(messageFromThunderbird["events"])
            else:
                logging.debug("!!! received wrong message %s", messageFromThunderbird)
        except queue.Empty:
            pass

