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
    auto group = config->group("ThunderbirdCalendarPlasmaIntegrationPlugin");
    QList<QString> enabledCalendarIds = group.readEntry(QStringLiteral("enabledCalendarIds"), QList<QString>());
    QList<QString> previouslySeenCalendarIds = group.readEntry(QStringLiteral("previouslySeenCalendarIds"), QList<QString>());

    qWarning() << QStringLiteral("ThunderbirdCalendarsModel enabledCalendarIds") << enabledCalendarIds;
    qWarning() << QStringLiteral("ThunderbirdCalendarsModel previouslySeenCalendarIds") << previouslySeenCalendarIds;

    // check if a calendar which was previously enabled by the user
    // has been removed. If yes, update the persistent config
    bool atLeastOneCalendarIdWasEnabledButHasNowBeenRemoved = false; 
    for (int i = 0; i < enabledCalendarIds.length(); ++i) {
        bool found = false;
        for (int j = 0; j < calendars.length(); ++j) {
            if (enabledCalendarIds.at(i) == calendars.at(j).id) {
                found = true;
                break;
            }    
        }
        
        if (!found) {
            atLeastOneCalendarIdWasEnabledButHasNowBeenRemoved = true;
            enabledCalendarIds.removeAll(enabledCalendarIds.at(i));
        }
    }

    // auto-enable new calendars that we receive first time from thunderbird. 
    bool atLeastOneCalendarReveivedFromThunderbirdIsNew = false;
    for (int i = 0; i < calendars.length(); ++i) {
        if (!previouslySeenCalendarIds.contains(calendars.at(i).id)) {
            atLeastOneCalendarReveivedFromThunderbirdIsNew = true;
            enabledCalendarIds.append(calendars.at(i).id);
        }
    }

    // if a stale calendarId was found or a new calendar is auto-enabled in config, then update config
    if (atLeastOneCalendarIdWasEnabledButHasNowBeenRemoved || atLeastOneCalendarReveivedFromThunderbirdIsNew) {
        qWarning() << QStringLiteral("ThunderbirdCalendarsModel WRITING enabledCalendarIds") << enabledCalendarIds;
        group.writeEntry("enabledCalendarIds", enabledCalendarIds);
    }

    // mark all calendars received from thunderbird as previously seen
    QList<QString> calendarIdsFromThunderbird;
    for (const ThunderbirdCalendar& cal : calendars) {
        calendarIdsFromThunderbird << cal.id;
    }
    previouslySeenCalendarIds = calendarIdsFromThunderbird;
    group.writeEntry("previouslySeenCalendarIds", previouslySeenCalendarIds);
    qWarning() << QStringLiteral("ThunderbirdCalendarsModel WRITING previouslySeenCalendarIds") << previouslySeenCalendarIds;

    // locally stored enabled calendar IDs
    mEnabledCalendarIds = QSet<QString>(enabledCalendarIds.begin(), enabledCalendarIds.end());
    qWarning() << QStringLiteral("ThunderbirdCalendarsModel USING mEnabledCalendarIds") << mEnabledCalendarIds;

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
            {QStringLiteral("checked"), mEnabledCalendarIds.contains(calendar.id)},
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
        selectionHasBeenChanged = !mEnabledCalendarIds.contains(calendarId);
        mEnabledCalendarIds.insert(calendarId);
    } else {
        selectionHasBeenChanged = mEnabledCalendarIds.remove(calendarId);
    }

//     if (selectionHasBeenChanged) {
//         Q_EMIT dataChanged();
    // }

    qWarning() << "ThunderbirdCalendarsModel::setChecked new list" << mEnabledCalendarIds.values();
}

void ThunderbirdCalendarsModel::saveConfig()
{   
    qWarning() << "ThunderbirdCalendarsModel::saveConfig()";

    auto config = KSharedConfig::openConfig();
    auto group = config->group("ThunderbirdCalendarPlasmaIntegrationPlugin");
    auto savedList = group.readEntry("enabledCalendarIds", QList<QString>());
    auto currentList = mEnabledCalendarIds.values();
    std::sort(savedList.begin(), savedList.end());
    std::sort(currentList.begin(), currentList.end());

    qWarning() << "ThunderbirdCalendarsModel::saveConfig() old:" << savedList;
    qWarning() << "ThunderbirdCalendarsModel::saveConfig() new:" << currentList;

    if (currentList != savedList) {
        group.writeEntry("enabledCalendarIds", currentList);
        SettingsChangeNotifier::self()->notifySettingsChanged();
    }
}
