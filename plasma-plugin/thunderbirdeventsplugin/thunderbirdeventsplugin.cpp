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



ThunderbirdEventsPlugin::ThunderbirdEventsPlugin(QObject *parent)
    // : ThunderbirdEventsPlugin(new AkonadiPimDataSource(), parent)
{
    // static_cast<AkonadiPimDataSource *>(mDataSource)->setParent(this);

    connect(SettingsChangeNotifier::self(), &SettingsChangeNotifier::settingsChanged, this, &ThunderbirdEventsPlugin::onSettingsChanged);

    qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "PIM Events Plugin activated";
    onSettingsChanged();
}

void ThunderbirdEventsPlugin::onSettingsChanged()
{
    const auto config = KSharedConfig::openConfig();
    const auto group = config->group("ThunderbirdEventsPlugin");
    const QList<QString> calendars = group.readEntry(QStringLiteral("calendars"), QList<QString>());
    
    qWarning() << "onSettingsChanged" << calendars;

    mThunderbirdCalendarIds = calendars;
}

// ThunderbirdEventsPlugin::ThunderbirdEventsPlugin(ThunderbirdDataSource *dataSource, QObject *parent)
//     : CalendarEvents::CalendarEventsPlugin(parent)
//     , mDataSource(dataSource)
// {
//     qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "PIM Events Plugin activated";

//     dataSource->calendar()->registerObserver(this);
// }

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
    QDBusReply<ThunderbirdCalendarEvents> reply = interface.call(QStringLiteral("GetEventsInDateRange"), intStartDate, intEndDate);

    if (!reply.isValid()) {
       qWarning() << QStringLiteral("D-Bus call failed:") << reply.error().message();
       return;
    } 

    qWarning() << QStringLiteral("D-Bus reply:") << reply.value();
    
    QMultiHash<QDate, CalendarEvents::EventData>* eventsByDate = new QMultiHash<QDate, CalendarEvents::EventData>();

    // const KCalendarCore::Event::List arrEvents;
    for (const ThunderbirdCalendarEvent &entry : reply.value()) {
        CalendarEvents::EventData* newEvent = new CalendarEvents::EventData();

        newEvent->setEventType(CalendarEvents::EventData::EventType::Event);
        newEvent->setTitle(entry.title);
        newEvent->setUid(QStringLiteral("ThunderbirdCalendarEvent-") + entry.id);
        newEvent->setEventColor(entry.color);

        // "D-Bus reply:" (ThunderbirdCalendarEvent(id="A8FDA75F-B8C4-4B73-A8D8-8EDC9000AC52", title="Apotheke", calendarId="33f02baa-1529-486a-9423-5ad9e4393b45", color="#FFCC00", startTime="20240109T150000", endTime="20240110T160000"
        QDateTime startDateTime = QDateTime::fromString(entry.startTime, QStringLiteral("yyyyMMddThhmmss"));
        newEvent->setStartDateTime(startDateTime);

        QDateTime endDateTime = QDateTime::fromString(entry.endTime, QStringLiteral("yyyyMMddThhmmss"));
        newEvent->setEndDateTime(endDateTime);

        eventsByDate->insert(startDateTime.date(), *newEvent);
    }

    Q_EMIT dataReady(*eventsByDate);

    // mStart = startDate;
    // mEnd = endDate;

    // int eventsCount = 0;
    // int eventDataCount = 0;
    // {
    //     EventDataVisitor visitor(mDataSource, startDate, endDate);
    //     const KCalendarCore::Event::List events = mDataSource->calendar()->events(startDate, endDate);
    //     eventsCount = events.count();
    //     if (visitor.act(events)) {
    //         eventDataCount = visitor.results().count();
    //         Q_EMIT dataReady(visitor.results());
    //     }
    // }

    // int todosCount = 0;
    // int todoDataCount = 0;
    // {
    //     EventDataVisitor visitor(mDataSource, startDate, endDate);
    //     const KCalendarCore::Todo::List todos = mDataSource->calendar()->todos(startDate, endDate);
    //     todosCount = todos.count();
    //     if (visitor.act(todos)) {
    //         todoDataCount = visitor.results().count();
    //         Q_EMIT dataReady(visitor.results());
    //     }
    // }
    // qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "Range:" << startDate.toString(Qt::ISODate) << "-" << endDate.toString(Qt::ISODate) << "Events:" << eventsCount
    //                              << "EventData:" << eventDataCount << "Todos:" << todosCount << "TodoData:" << todoDataCount;
}

// void ThunderbirdEventsPlugin::calendarIncidenceAdded(const KCalendarCore::Incidence::Ptr &incidence)
// {
//     if (!mStart.isValid() || !mEnd.isValid()) {
//         // Don't bother with changes that happen before the applet starts populating data
//         return;
//     }
//     EventDataVisitor visitor(mDataSource, mStart, mEnd);
//     if (visitor.act(incidence)) {
//         Q_EMIT dataReady(visitor.results());
//     }
// }

// void ThunderbirdEventsPlugin::calendarIncidenceChanged(const KCalendarCore::Incidence::Ptr &incidence)
// {
//     if (!mStart.isValid() || !mEnd.isValid()) {
//         return;
//     }
//     EventDataVisitor visitor(mDataSource, mStart, mEnd);
//     if (visitor.act(incidence)) {
//         for (const auto &ed : visitor.results()) {
//             Q_EMIT eventModified(ed);
//         }
//     }
// }

// void ThunderbirdEventsPlugin::calendarIncidenceAboutToBeDeleted(const KCalendarCore::Incidence::Ptr &incidence)
// {
//     if (!mStart.isValid() || !mEnd.isValid()) {
//         return;
//     }
//     EventDataIdVisitor visitor(mDataSource, mStart, mEnd);
//     if (visitor.act(incidence)) {
//         for (const QString &uid : visitor.results()) {
//             Q_EMIT eventRemoved(uid);
//         }
//     }
// }
