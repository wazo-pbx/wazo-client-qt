/* XiVO Client
 * Copyright (C) 2007-2011, Proformatique
 *
 * This file is part of XiVO Client.
 *
 * XiVO Client is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version, with a Section 7 Additional
 * Permission as follows:
 *   This notice constitutes a grant of such permission as is necessary
 *   to combine or link this software, or a modified version of it, with
 *   the OpenSSL project's "OpenSSL" library, or a derivative work of it,
 *   and to copy, modify, and distribute the resulting work. This is an
 *   extension of the special permission given by Trolltech to link the
 *   Qt code with the OpenSSL library (see
 *   <http://doc.trolltech.com/4.4/gpl.html>). The OpenSSL library is
 *   licensed under a dual license: the OpenSSL License and the original
 *   SSLeay license.
 *
 * XiVO Client is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with XiVO Client.  If not, see <http://www.gnu.org/licenses/>.
 */

/* $Revision$
 * $Date$
 */

#ifndef __GROUPINFO_H__
#define __GROUPINFO_H__

#include "baselib_export.h"
#include <QString>
#include <QVariant>
#include <QMap>
#include "xinfo.h"

/*! \brief Store Group information
 */
class BASELIB_EXPORT GroupInfo : public XInfo
{
    public:
        GroupInfo(const QString &, const QString &);  //! constructor
        bool updateConfig(const QVariantMap &);  //! update config members
        bool updateStatus(const QVariantMap &);  //! update status members
        bool updateAgent(const QVariantMap &);  //! update attribute members
        const QString & context() const;  //! context this group belongs to
        const QString & groupNumber() const { return m_groupnumber; };  //! group number
        const QString & groupName() const  { return m_groupname; };  //! group name
        const QVariantMap & properties() const;  //! group properties
        const QStringList & xincalls() const { return m_xincalls; };  //! incoming channel calls

    private:
        QString m_context;
        QString m_groupname;
        QString m_groupnumber;
        QStringList m_xincalls;
        QVariantMap m_properties;
};

#endif
