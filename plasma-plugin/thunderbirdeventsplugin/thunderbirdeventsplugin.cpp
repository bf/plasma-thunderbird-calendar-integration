/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#include "thunderbirdeventsplugin.h"
#include "akonadipimdatasource.h"
#include "eventdatavisitor.h"
#include "thunderbirdeventsplugin_debug.h"


ThunderbirdEventsPlugin::ThunderbirdEventsPlugin(QObject *parent)
    : ThunderbirdEventsPlugin(new AkonadiPimDataSource(), parent)
{
    static_cast<AkonadiPimDataSource *>(mDataSource)->setParent(this);
}

ThunderbirdEventsPlugin::ThunderbirdEventsPlugin(ThunderbirdDataSource *dataSource, QObject *parent)
    : CalendarEvents::CalendarEventsPlugin(parent)
    , mDataSource(dataSource)
{
    qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "PIM Events Plugin activated";

    dataSource->calendar()->registerObserver(this);
}

ThunderbirdEventsPlugin::~ThunderbirdEventsPlugin()
{
    qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "PIM Events Plugin deactivated";
}

void ThunderbirdEventsPlugin::loadEventsForDateRange(const QDate &startDate, const QDate &endDate)
{
    mStart = startDate;
    mEnd = endDate;

    int eventsCount = 0;
    int eventDataCount = 0;
    {
        EventDataVisitor visitor(mDataSource, startDate, endDate);
        const KCalendarCore::Event::List events = mDataSource->calendar()->events(startDate, endDate);
        eventsCount = events.count();
        if (visitor.act(events)) {
            eventDataCount = visitor.results().count();
            Q_EMIT dataReady(visitor.results());
        }
    }

    int todosCount = 0;
    int todoDataCount = 0;
    {
        EventDataVisitor visitor(mDataSource, startDate, endDate);
        const KCalendarCore::Todo::List todos = mDataSource->calendar()->todos(startDate, endDate);
        todosCount = todos.count();
        if (visitor.act(todos)) {
            todoDataCount = visitor.results().count();
            Q_EMIT dataReady(visitor.results());
        }
    }
    qCDebug(THUNDERBIRDEVENTSPLUGIN_LOG) << "Range:" << startDate.toString(Qt::ISODate) << "-" << endDate.toString(Qt::ISODate) << "Events:" << eventsCount
                                 << "EventData:" << eventDataCount << "Todos:" << todosCount << "TodoData:" << todoDataCount;
}

void ThunderbirdEventsPlugin::calendarIncidenceAdded(const KCalendarCore::Incidence::Ptr &incidence)
{
    if (!mStart.isValid() || !mEnd.isValid()) {
        // Don't bother with changes that happen before the applet starts populating data
        return;
    }
    EventDataVisitor visitor(mDataSource, mStart, mEnd);
    if (visitor.act(incidence)) {
        Q_EMIT dataReady(visitor.results());
    }
}

void ThunderbirdEventsPlugin::calendarIncidenceChanged(const KCalendarCore::Incidence::Ptr &incidence)
{
    if (!mStart.isValid() || !mEnd.isValid()) {
        return;
    }
    EventDataVisitor visitor(mDataSource, mStart, mEnd);
    if (visitor.act(incidence)) {
        for (const auto &ed : visitor.results()) {
            Q_EMIT eventModified(ed);
        }
    }
}

void ThunderbirdEventsPlugin::calendarIncidenceAboutToBeDeleted(const KCalendarCore::Incidence::Ptr &incidence)
{
    if (!mStart.isValid() || !mEnd.isValid()) {
        return;
    }
    EventDataIdVisitor visitor(mDataSource, mStart, mEnd);
    if (visitor.act(incidence)) {
        for (const QString &uid : visitor.results()) {
            Q_EMIT eventRemoved(uid);
        }
    }
}
