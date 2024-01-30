/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#include "thunderbirdeventsplugin.h"
// #include "akonadipimdatasource.h"
// #include "eventdatavisitor.h"
#include "thunderbirdeventsplugin_debug.h"
#include "settingschangenotifier.h"

#include <KCoreConfigSkeleton>
#include <KSharedConfig>

#include <QDBusConnection>
#include <QDebug>
#include <QDBusMessage>
#include <QDBusInterface>
#include <QDBusReply>
#include <iostream>
#include <QDBusMetaType>
#include <QStandardItemModel>
#include <QDateTime>
#include <QMultiHash>



ThunderbirdEventsPlugin::ThunderbirdEventsPlugin(QObject *parent) {
    connect(SettingsChangeNotifier::self(), &SettingsChangeNotifier::settingsChanged, this, &ThunderbirdEventsPlugin::onSettingsChanged);
    qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "PIM Events Plugin activated";
    onSettingsChanged();
}

void ThunderbirdEventsPlugin::onSettingsChanged()
{
    const auto config = KSharedConfig::openConfig();
    const auto group = config->group("ThunderbirdCalendarPlasmaIntegrationPlugin");
    const QList<QString> calendars = group.readEntry(QStringLiteral("enabledCalendarIds"), QList<QString>());
    
    qWarning() << "ThunderbirdEventsPlugin::onSettingsChanged" << calendars;

    mThunderbirdCalendarIds = calendars;
}

ThunderbirdEventsPlugin::~ThunderbirdEventsPlugin()
{
    qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "Thunderbird Calendar Plugin deactivated";
}

void ThunderbirdEventsPlugin::loadEventsForDateRange(const QDate &startDate, const QDate &endDate)
{
    qWarning() << QStringLiteral("loadEventsForDateRange args") << startDate << endDate;

    QString format = QStringLiteral("yyyyMMdd");
    int intStartDate = startDate.toString(format).toInt();
    int intEndDate = endDate.toString(format).toInt();

    qWarning() << QStringLiteral("loadEventsForDateRange int") << intStartDate << intEndDate;

    QDBusInterface interface(QStringLiteral("org.kde.plasma.thunderbird_integration"), 
                         QStringLiteral("/org/kde/plasma/thunderbird_integration"), 
                         QStringLiteral("org.kde.plasma.thunderbird_integration"),
                         QDBusConnection::sessionBus());
    
    qDBusRegisterMetaType<ThunderbirdCalendarEvent>();
    qDBusRegisterMetaType<ThunderbirdCalendarEvents>();

    qWarning() << QStringLiteral("before dbus");
    QDBusReply<ThunderbirdCalendarEvents> reply = interface.call(QStringLiteral("GetEventsInDateRangeFromCalendars"), mThunderbirdCalendarIds, intStartDate, intEndDate);

    if (!reply.isValid()) {
       qWarning() << QStringLiteral("D-Bus call failed:") << reply.error().message();
       return;
    } 

    qWarning() << QStringLiteral("D-Bus reply:") << reply.value();
    
    QMultiHash<QDate, CalendarEvents::EventData>* eventsByDate = new QMultiHash<QDate, CalendarEvents::EventData>();

    QString formatOfThunderbirdTimestamp = QStringLiteral("yyyyMMddThhmmss");
    for (const ThunderbirdCalendarEvent &entry : reply.value()) {
        CalendarEvents::EventData* newEvent = new CalendarEvents::EventData();

        newEvent->setEventType(CalendarEvents::EventData::EventType::Event);
        newEvent->setTitle(entry.title);
        newEvent->setUid(QStringLiteral("ThunderbirdCalendarEvent-") + entry.id);
        newEvent->setEventColor(entry.color);

        QDateTime startDateTime = QDateTime::fromString(entry.startTime, formatOfThunderbirdTimestamp);
        newEvent->setStartDateTime(startDateTime);

        QDateTime endDateTime = QDateTime::fromString(entry.endTime, formatOfThunderbirdTimestamp);
        newEvent->setEndDateTime(endDateTime);

        // qWarning() << "newEvent: " << newEvent->title() << " " << newEvent->eventColor() <<  " == " << entry.color;

        eventsByDate->insert(startDateTime.date(), *newEvent);
    }

    Q_EMIT dataReady(*eventsByDate);
}
