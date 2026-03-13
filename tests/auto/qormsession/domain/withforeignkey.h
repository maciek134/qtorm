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
#include "withnotnull.h"

class WithForeignKey: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(WithNotNull* data READ data WRITE setData NOTIFY dataChanged)

    Q_ORM_PROPERTY(data FOREIGN_KEY)

public:
    Q_INVOKABLE WithForeignKey(QObject* parent = nullptr);

    [[nodiscard]] int id() const { return m_id; }
    void setId(int id)
    {
        if (m_id != id)
        {
            m_id = id;
            emit idChanged();
        }
    }

    [[nodiscard]] WithNotNull* data() const { return m_data; }
    void setData(WithNotNull* data)
    {
        if (m_data != data)
        {
            m_data = data;
            emit dataChanged();
        }
    }

signals:
    void idChanged();
    void dataChanged();

private:
    int m_id{0};
    WithNotNull* m_data{nullptr};
};
