/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#include "thunderbirdcalendarsmodel.h"
#include "thunderbirdeventsplugin_debug.h"
#include "settingschangenotifier.h"

#include <Akonadi/CollectionFetchScope>
#include <Akonadi/EntityDisplayAttribute>
#include <Akonadi/EntityTreeModel>
#include <Akonadi/Monitor>

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

// #include "abstractbrowserplugin.h"
// #include "connection.h"


ThunderbirdCalendarsModel::ThunderbirdCalendarsModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{

    // // otherwise when logging out, session manager will ask the host to quit
    // // (it's a "regular X app" after all) and then the browser will complain
    // qunsetenv("SESSION_MANAGER");
    // QApplication a(argc, argv);
    // // otherwise will close when download job finishes
    // a.setQuitOnLastWindowClosed(false);
    // a.setQuitLockEnabled(false);
    // // applicationName etc will be set in Settings once the browser identifies to us

    // qInstallMessageHandler(msgHandler);

    // KCrash::initialize();

    // NOTE if you add a new plugin here, make sure to adjust the
    // "DEFAULT_EXTENSION_SETTINGS" in constants.js or else it won't
    // even bother loading your shiny new plugin!

    // PluginManager::self().addPlugin(&Settings::self());
    // PluginManager::self().addPlugin(new KDEConnectPlugin(&a));
    // PluginManager::self().addPlugin(new DownloadPlugin(&a));
    // PluginManager::self().addPlugin(new TabsRunnerPlugin(&a));
    // PluginManager::self().addPlugin(new HistoryRunnerPlugin(&a));
    // PluginManager::self().addPlugin(new MPrisPlugin(&a));
    // PluginManager::self().addPlugin(new PurposePlugin(&a));

    // // TODO make this prettier, also prevent unloading them at any cost
    // PluginManager::self().loadPlugin(&Settings::self());

    // QString serviceName = QStringLiteral("org.kde.plasma.thunderbird_integration");
    // if (!QDBusConnection::sessionBus().registerService(serviceName)) {
    //     // // now try appending PID in case multiple hosts are running
    //     // serviceName.append(QLatin1String("-")).append(QString::number(QCoreApplication::applicationPid()));
    //     // if (!QDBusConnection::sessionBus().registerService(serviceName)) {
    //         qWarning() << "Failed to register DBus service name" << serviceName;
    //     // }
    // }


    // QDBusConnection dbus = QDBusConnection::sessionBus();
    // dbus.connect(QStringLiteral("org.kde.plasma.thunderbird_integration"),
    //              QStringLiteral("/GetCalendars"),
    //              QStringLiteral("org.kde.plasma.thunderbird_integration"),
    //              QStringLiteral("GetCalendars"),
    //              this,
    //              SLOT(onResourceScoresChanged(QString, QString, QString, double, unsigned int, unsigned int)));

    // QDBusInterface dbusInterface(QStringLiteral("org.kde.plasma.thunderbird_integration"), QStringLiteral("/GetCalendars"), QStringLiteral("org.kde.plasma.thunderbird_integration"), QDBusConnection::sessionBus());

    // if (dbusInterface.isValid()) {
    //     // Call a method on the interface
    //     QDBusReply<QString> reply = dbusInterface.call(QStringLiteral("GetCalendars"), QStringLiteral("all"));

    //     if (reply.isValid()) {
    //         // Successfully received a response
    //         std::cout << "Response: " << reply.value().toStdString() << std::endl;
    //     } else {
    //         // Error occurred in calling the method
    //         std::cerr << "Error: " << reply.error().message().toStdString() << std::endl;
    //     }
    // } else {
    //     std::cerr << "Failed to create D-Bus interface." << std::endl;
    // }


    // QJsonObject data;  
    // data[QStringLiteral("test")] = QStringLiteral("123");
    // Connection::self()->sendData(data);
    // a.exec();

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


    // auto cr = new Akonadi::Monitor(this);
    // cr->setMimeTypeMonitored(KCalendarCore::Event::eventMimeType());
    // cr->setMimeTypeMonitored(KCalendarCore::Todo::todoMimeType());
    // cr->setTypeMonitored(Akonadi::Monitor::Collections);
    // cr->collectionFetchScope().setListFilter(Akonadi::CollectionFetchScope::Enabled);

    // mEtm = new Akonadi::EntityTreeModel(cr, this);
    // mEtm->setItemPopulationStrategy(Akonadi::EntityTreeModel::NoItemPopulation);
    // mEtm->setListFilter(Akonadi::CollectionFetchScope::Enabled);
    // connect(mEtm, &Akonadi::EntityTreeModel::collectionTreeFetched, this, [this]() {
    //     sort(0, Qt::AscendingOrder);
    // });

    // load settings
    auto config = KSharedConfig::openConfig();
    auto group = config->group("ThunderbirdEventsPlugin");
    const auto enabledCalendarIds = group.readEntry(QStringLiteral("calendars"), QList<QString>());
    mEnabledCalendars = QSet<QString>(enabledCalendarIds.begin(), enabledCalendarIds.end());

    qDebug() << QStringLiteral("calendars.length():") << calendars.length();
    mEtm = new QStandardItemModel(this);
    // mEtm->setRowCount(calendars.length());
    // mEtm->setColumnCount(3);
    
    for (int i = 0; i < calendars.length(); ++i) {
        ThunderbirdCalendar calendar = calendars.at(i);

        QStandardItem* rowItem = new QStandardItem(calendar.name);
        rowItem->setSelectable(false);
        rowItem->setFlags(Qt::NoItemFlags);
        rowItem->setData(
            QVariantMap{{QStringLiteral("id"), calendar.id},
               {QStringLiteral("name"), calendar.name},
               // {QStringLiteral("enabled"), true},
               {QStringLiteral("checked"), mEnabledCalendars.contains(calendar.id)},
               {QStringLiteral("color"), calendar.color}
                // ,
                // {QStringLiteral("iconName"), QStringLiteral("")}
            }
        ,DataRole);
        // QList<QStandardItem *> columns;

        // QStandardItem* checkbox = new QStandardItem(true);
        // checkbox->setCheckable(true);
        // // checkbox->setCheckState(mEnabledCalendars.contains(calendar.id) ? Qt::Checked : Qt::Unchecked);
        // checkbox->setCheckState(Qt::Checked);
        // // checkbox->setData(QVariantMap{{QStringLiteral("id"), calendar.id},
        // //                {QStringLiteral("name"), calendar.name},
        // //                {QStringLiteral("enabled"), true},
        // //                {QStringLiteral("checked"), false},{QStringLiteral("iconName"), QStringLiteral("")}}, 
        // //     DataRole);

        // columns.append(checkbox);
        // QStandardItem* name = new QStandardItem(calendar.name);
        // name->setData(
        //         QVariantMap{{QStringLiteral("id"), calendar.id},
        //                {QStringLiteral("name"), calendar.name},
        //                {QStringLiteral("enabled"), true},
        //                {QStringLiteral("checked"), false},{QStringLiteral("iconName"), QStringLiteral("")}}
        // ,DataRole);
        // columns.append(name);
        // columns.append(new QStandardItem(calendar.id));

        mEtm->appendRow(rowItem);
        // mEtm->appendRow(checkbox);
    }

    setSourceModel(mEtm);

}

ThunderbirdCalendarsModel::~ThunderbirdCalendarsModel() = default;

QHash<int, QByteArray> ThunderbirdCalendarsModel::roleNames() const
{
    return {{DataRole, "data"}};
}

// QVariant ThunderbirdCalendarsModel::data(const QModelIndex &index, int role) const
// { 
//     qWarning() << QStringLiteral("ThunderbirdCalendarsModel.data called") << index;

//     if (role == Qt::DisplayRole) {
//         qWarning() << QStringLiteral("ThunderbirdCalendarsModel.data role == Qt::DisplayRole");
//         return QSortFilterProxyModel::data(index, role);
//     }

//     if (role != DataRole) {
//         qWarning() << QStringLiteral("ThunderbirdCalendarsModel.data role != DataRole");
//         return {};
//     }

//     // const auto &col = QSortFilterProxyModel::data(index, Akonadi::EntityTreeModel::CollectionRole).value<Akonadi::Collection>();
//     // if (!col.isValid()) {
//     //     return {};
//     // }
//     // const auto mts = col.contentMimeTypes();
//     // const bool enabled = mts.contains(KCalendarCore::Event::eventMimeType()) || mts.contains(KCalendarCore::Todo::todoMimeType());

//     // auto attr = col.attribute<Akonadi::EntityDisplayAttribute>();
//     // const QString icon = attr ? attr->iconName() : QString();

//     // m.QModelIndex
//     qWarning() << QStringLiteral("ThunderbirdCalendarsModel.data row") << index.row();

//     if (index.row()< 0) {
//         qWarning() << QStringLiteral("ThunderbirdCalendarsModel returning");
//         return {};
//     }

//     return {};

//     ThunderbirdCalendar calendar = mCalendars.at(index.row());

//     return QVariantMap{{QStringLiteral("id"), calendar.id},
//                        {QStringLiteral("name"), calendar.name},
//                        {QStringLiteral("enabled"), true},
//                        {QStringLiteral("checked"), mEnabledCalendars.contains(calendar.id)},
//                        {QStringLiteral("iconName"), QStringLiteral("")}};
// }

void ThunderbirdCalendarsModel::setChecked(QString calendarId, bool checked)
{   
    bool selectionHasBeenChanged = false;
    if (checked) {
        selectionHasBeenChanged = !mEnabledCalendars.contains(calendarId);
        mEnabledCalendars.insert(calendarId);
    } else {
        selectionHasBeenChanged = mEnabledCalendars.remove(calendarId);
    }

    if (selectionHasBeenChanged) {
        // update the model
        // Q_EMIT dataChanged(idx, idx);
    }


    // bool done = false;
    // if (checked) {
    //     done = !mEnabledCalendars.contains(collectionId);
    //     mEnabledCalendars.insert(collectionId);
    // } else {
    //     done = mEnabledCalendars.remove(collectionId);
    // }
    // if (done) {
    //     const QModelIndex idx = Akonadi::EntityTreeModel::modelIndexForCollection(this, Akonadi::Collection(collectionId));
    //     Q_EMIT dataChanged(idx, idx);
    // }
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
