/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#pragma once

#include <CalendarEvents/CalendarEventsPlugin>
// #include <CalendarEvents/EventData>
// see details at https://github.com/KDE/kdeclarative/blob/3339e0f0e3f4016b5d1f3b6d63a0c290f09d6541/src/calendarevents/calendareventsplugin.h

#include <KCalendarCore/Calendar>

#include <QDBusArgument>
#include <QDebug>
#include <QString>

// namespace Akonadi
// {
// class ETMCalendar;
// }


struct ThunderbirdCalendarEvent {
    // sss
    QString id;
    QString title;
    QString calendarId;
    QString color;
    QString startTime;
    QString endTime;
};

typedef QList<ThunderbirdCalendarEvent> ThunderbirdCalendarEvents;


inline QDebug operator<<(QDebug debug, const ThunderbirdCalendarEvent &myEvent) {
    debug.nospace() << "ThunderbirdCalendarEvent(id=" << myEvent.id
                    << ", title=" << myEvent.title
                    << ", calendarId=" << myEvent.calendarId
                    << ", color=" << myEvent.color
                    << ", startTime=" << myEvent.startTime
                    << ", endTime=" << myEvent.endTime << ")";
    return debug.space();
}

inline QDBusArgument &operator<<(QDBusArgument &argument, const ThunderbirdCalendarEvent &myEvent)
{
    argument.beginStructure();
    argument << myEvent.id;
    argument << myEvent.title;
    argument << myEvent.calendarId;
    argument << myEvent.color;
    argument << myEvent.startTime;
    argument << myEvent.endTime;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator>>(const QDBusArgument &argument, ThunderbirdCalendarEvent &myEvent)
{
    argument.beginStructure();
    argument >> myEvent.id;
    argument >> myEvent.title;
    argument >> myEvent.calendarId;
    argument >> myEvent.color;
    argument >> myEvent.startTime;
    argument >> myEvent.endTime;
    argument.endStructure();
    return argument;
}

Q_DECLARE_METATYPE(ThunderbirdCalendarEvent);
Q_DECLARE_METATYPE(ThunderbirdCalendarEvents);



// class ThunderbirdDataSource;
class ThunderbirdEventsPlugin : public CalendarEvents::CalendarEventsPlugin
    //, public KCalendarCore::Calendar::CalendarObserver
{
    Q_OBJECT
    Q_INTERFACES(CalendarEvents::CalendarEventsPlugin)
    Q_PLUGIN_METADATA(IID "org.kde.CalendarEventsPlugin" FILE "thunderbirdeventsplugin.json")

public:
    explicit ThunderbirdEventsPlugin(QObject *parent = nullptr);
    // explicit ThunderbirdEventsPlugin(ThunderbirdDataSource *factory, QObject *parent = nullptr);
    ~ThunderbirdEventsPlugin() override;

    // CalendarEvents::CalendarEventsPlugin
    void loadEventsForDateRange(const QDate &startDate, const QDate &endDate) override;

    // // KCalendarCore::Calendar::CalendarObserver
    // void calendarIncidenceChanged(const KCalendarCore::Incidence::Ptr &incidence) override;
    // void calendarIncidenceAdded(const KCalendarCore::Incidence::Ptr &incidence) override;
    // // Handle removal before it really happens otherwise we would not be able
    // // to lookup corresponding Akonadi ID in ETMCalendar
    // void calendarIncidenceAboutToBeDeleted(const KCalendarCore::Incidence::Ptr &incidence) override;

private Q_SLOTS:
    void onSettingsChanged();
    
private:
    // ThunderbirdDataSource *const mDataSource;
    QList<QString> mThunderbirdCalendarIds;
    QDate mStart;
    QDate mEnd;
};
