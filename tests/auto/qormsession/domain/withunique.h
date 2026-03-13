/*
 * Copyright (C) 2019-2021 Dmitriy Purgin <dmitriy.purgin@sequality.at>
 * Copyright (C) 2019-2021 sequality software engineering e.U. <office@sequality.at>
 * Copyright (C) 2026 Maciej Sopyło <me@klh.io>
 *
 * This file is part of QtOrm library.
 *
 * QtOrm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QtOrm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with QtOrm.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>
#include <QVariant>

#include <QtOrm/qormglobal.h>

class WithUnique: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString single READ single WRITE setSingle NOTIFY singleChanged)
    Q_PROPERTY(QString multiOne READ multiOne WRITE setMultiOne NOTIFY multiOneChanged)
    Q_PROPERTY(QString multiTwo READ multiTwo WRITE setMultiTwo NOTIFY multiTwoChanged)

    Q_ORM_PROPERTY(single UNIQUE)
    Q_ORM_PROPERTY(multiOne UNIQUE multi)
    Q_ORM_PROPERTY(multiTwo UNIQUE multi)

public:
    Q_INVOKABLE WithUnique(QObject* parent = nullptr);

    [[nodiscard]] int id() const { return m_id; }
    void setId(int id)
    {
        if (m_id != id)
        {
            m_id = id;
            emit idChanged();
        }
    }

    [[nodiscard]] QString single() const { return m_single; }
    void setSingle(QString single)
    {
        if (m_single != single)
        {
            m_single = single;
            emit singleChanged();
        }
    }

    [[nodiscard]] QString multiOne() const { return m_multiOne; }
    void setMultiOne(QString multiOne)
    {
        if (m_multiOne != multiOne)
        {
            m_multiOne = multiOne;
            emit multiOneChanged();
        }
    }

    [[nodiscard]] QString multiTwo() const { return m_multiTwo; }
    void setMultiTwo(QString multiTwo)
    {
        if (m_multiTwo != multiTwo)
        {
            m_multiTwo = multiTwo;
            emit multiTwoChanged();
        }
    }
signals:
    void idChanged();
    void singleChanged();
    void multiOneChanged();
    void multiTwoChanged();

private:
    int m_id{0};
    QString m_single;
    QString m_multiOne;
    QString m_multiTwo;
};
