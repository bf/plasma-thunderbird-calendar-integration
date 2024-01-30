/*
 * SPDX-FileCopyrightText: 2016 Daniel Vrátil <dvratil@kde.org>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#pragma once

#include <QSet>
#include <QSortFilterProxyModel>

#include <QDBusArgument>
#include <QList>
#include <QString>
#include <QVariantMap>
#include <QDebug>
#include <QString>
#include <QStandardItemModel>

struct ThunderbirdCalendar {
    // sss
    QString id;
    QString name;
    QString color;
};

typedef QList<ThunderbirdCalendar> ThunderbirdCalendars;


inline QDebug operator<<(QDebug debug, const ThunderbirdCalendar &calendar) {
    debug.nospace() << "ThunderbirdCalendar(id=" << calendar.id
                    << ", name=" << calendar.name
                    << ", color=" << calendar.color << ")";
    return debug.space();
}

inline QDBusArgument &operator<<(QDBusArgument &argument, const ThunderbirdCalendar &calendar)
{
    argument.beginStructure();
    argument << calendar.id;
    argument << calendar.name;
    argument << calendar.color;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator>>(const QDBusArgument &argument, ThunderbirdCalendar &calendar)
{
    argument.beginStructure();
    argument >> calendar.id;
    argument >> calendar.name;
    argument >> calendar.color;
    argument.endStructure();
    return argument;
}

Q_DECLARE_METATYPE(ThunderbirdCalendar);
Q_DECLARE_METATYPE(ThunderbirdCalendars);


// namespace Akonadi
// {
// class EntityTreeModel;
// }

class ThunderbirdCalendarsModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    enum Roles {
        DataRole = Qt::UserRole + 1,
    };

    explicit ThunderbirdCalendarsModel(QObject *parent = nullptr);
    ~ThunderbirdCalendarsModel() override;

    QHash<int, QByteArray> roleNames() const override;

public Q_SLOTS:
    void setChecked(QString calendarId, bool checked);
    void saveConfig();

private:
    QStandardItemModel *mEtm = nullptr;
    ThunderbirdCalendars mCalendars;
    QSet<QString> mEnabledCalendars;
};
