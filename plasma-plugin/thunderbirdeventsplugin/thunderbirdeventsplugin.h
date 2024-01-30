/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#pragma once

#include <CalendarEvents/CalendarEventsPlugin>
#include <KCalendarCore/Calendar>

namespace Akonadi
{
class ETMCalendar;
}

class ThunderbirdDataSource;
class ThunderbirdEventsPlugin : public CalendarEvents::CalendarEventsPlugin, public KCalendarCore::Calendar::CalendarObserver
{
    Q_OBJECT
    Q_INTERFACES(CalendarEvents::CalendarEventsPlugin)
    Q_PLUGIN_METADATA(IID "org.kde.CalendarEventsPlugin" FILE "thunderbirdeventsplugin.json")

public:
    explicit ThunderbirdEventsPlugin(QObject *parent = nullptr);
    explicit ThunderbirdEventsPlugin(ThunderbirdDataSource *factory, QObject *parent = nullptr);
    ~ThunderbirdEventsPlugin() override;

    // CalendarEvents::CalendarEventsPlugin
    void loadEventsForDateRange(const QDate &startDate, const QDate &endDate) override;

    // KCalendarCore::Calendar::CalendarObserver
    void calendarIncidenceChanged(const KCalendarCore::Incidence::Ptr &incidence) override;
    void calendarIncidenceAdded(const KCalendarCore::Incidence::Ptr &incidence) override;
    // Handle removal before it really happens otherwise we would not be able
    // to lookup corresponding Akonadi ID in ETMCalendar
    void calendarIncidenceAboutToBeDeleted(const KCalendarCore::Incidence::Ptr &incidence) override;

private:
    ThunderbirdDataSource *const mDataSource;
    QDate mStart;
    QDate mEnd;
};
