/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#include "thunderbirdcalendarsmodel.h"
#include "thunderbirdeventsplugin_debug.h"
#include "settingschangenotifier.h"

// #include <Akonadi/CollectionFetchScope>
// #include <Akonadi/EntityDisplayAttribute>
// #include <Akonadi/EntityTreeModel>
// #include <Akonadi/Monitor>

#include <KCalendarCore/Event>
#include <KCalendarCore/Todo>

#include <KConfigGroup>
#include <KSharedConfig>


/*
    SPDX-FileCopyrightText: 2017 Kai Uwe Broulik <kde@privat.broulik.de>
    SPDX-FileCopyrightText: 2017 David Edmundson <davidedmundson@kde.org>

    SPDX-License-Identifier: MIT
*/

// #include <QApplication>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusMessage>
#include <QDBusInterface>
#include <QDBusReply>
#include <iostream>
#include <QDBusMetaType>
#include <QStandardItemModel>

#include <KCrash>

ThunderbirdCalendarsModel::ThunderbirdCalendarsModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    qDBusRegisterMetaType<ThunderbirdCalendar>();
    qDBusRegisterMetaType<ThunderbirdCalendars>();

    QDBusInterface interface(QStringLiteral("org.kde.plasma.thunderbird_integration"), 
                         QStringLiteral("/org/kde/plasma/thunderbird_integration"), 
                         QStringLiteral("org.kde.plasma.thunderbird_integration"),
                         QDBusConnection::sessionBus());
    
    qWarning() << QStringLiteral("before dbus");
    QDBusReply<ThunderbirdCalendars> reply = interface.call(QStringLiteral("GetCalendars"));

    if (!reply.isValid()) {
       qWarning() << QStringLiteral("D-Bus call failed:") << reply.error().message();
       return;
    } 


    qWarning() << QStringLiteral("D-Bus reply:") << reply.value();

    ThunderbirdCalendars calendars = reply.value();
    qDebug() << QStringLiteral("calendars:") << calendars;

    // store as member
    mCalendars = calendars;

    setSortRole(Qt::DisplayRole);
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setSortLocaleAware(true);
    setDynamicSortFilter(true);

    // load settings
    auto config = KSharedConfig::openConfig();
    auto group = config->group("ThunderbirdEventsPlugin");
    const auto enabledCalendarIds = group.readEntry(QStringLiteral("calendars"), QList<QString>());
    mEnabledCalendars = QSet<QString>(enabledCalendarIds.begin(), enabledCalendarIds.end());

    qDebug() << QStringLiteral("calendars.length():") << calendars.length();
    mEtm = new QStandardItemModel(this);
    
    for (int i = 0; i < calendars.length(); ++i) {
        ThunderbirdCalendar calendar = calendars.at(i);

        QStandardItem* rowItem = new QStandardItem(calendar.name);
        rowItem->setSelectable(false);
        rowItem->setFlags(Qt::NoItemFlags);
        rowItem->setData(QVariantMap{
            {QStringLiteral("id"), calendar.id},
            {QStringLiteral("name"), calendar.name},
            {QStringLiteral("checked"), mEnabledCalendars.contains(calendar.id)},
            {QStringLiteral("color"), calendar.color}
        }, DataRole);

        mEtm->appendRow(rowItem);
    }

    setSourceModel(mEtm);
}

ThunderbirdCalendarsModel::~ThunderbirdCalendarsModel() = default;

QHash<int, QByteArray> ThunderbirdCalendarsModel::roleNames() const
{
    return {{DataRole, "data"}};
}


void ThunderbirdCalendarsModel::setChecked(QString calendarId, bool checked)
{   
    bool selectionHasBeenChanged = false;
    if (checked) {
        selectionHasBeenChanged = !mEnabledCalendars.contains(calendarId);
        mEnabledCalendars.insert(calendarId);
    } else {
        selectionHasBeenChanged = mEnabledCalendars.remove(calendarId);
    }
}

void ThunderbirdCalendarsModel::saveConfig()
{
    auto config = KSharedConfig::openConfig();
    auto group = config->group("ThunderbirdEventsPlugin");
    auto savedList = group.readEntry("calendars", QList<QString>());
    auto currentList = mEnabledCalendars.values();
    std::sort(savedList.begin(), savedList.end());
    std::sort(currentList.begin(), currentList.end());

    if (currentList != savedList) {
        group.writeEntry("calendars", currentList);
        SettingsChangeNotifier::self()->notifySettingsChanged();
    }
}
