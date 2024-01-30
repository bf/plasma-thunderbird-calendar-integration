/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#include <QQmlExtensionPlugin>
#include <QtQml>

#include "thunderbirdcalendarsmodel.h"


class ThunderbirdCalendarsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri) override
    {
        qmlRegisterType<ThunderbirdCalendarsModel>(uri, 1, 0, "ThunderbirdCalendarsModel");
    }
};

#include "thunderbirdcalendarsplugin.moc"
