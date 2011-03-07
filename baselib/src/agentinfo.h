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

#ifndef __AGENTINFO_H__
#define __AGENTINFO_H__

#include "baselib_export.h"
#include <QString>
#include <QVariant>
#include <QMap>

/*! \brief Store Agent information
 */
class BASELIB_EXPORT AgentInfo
{
    public:
        AgentInfo(const QString &, const QString &); //! constructor
        bool updateConfig(const QVariantMap &);  //! update config members
        bool updateStatus(const QVariantMap &);  //! update status members
        bool updateQueue(const QVariantMap &);
        const QString & ipbxid() const;  //! IPBX this agent belongs to
        const QString & id() const;  //! reference id of this agent on the server
        const QString & context() const;  //! context this agent belongs to
        const QString & agentNumber() const;  //! agent number
        const QString & fullname() const;  //! agent fullname

        //! agent statuses
        const QString & status() const {
                return m_status;
        };  //! access to the status values of this agent
        const QVariantMap & properties() const;
        //! current communications of this agent
        const QVariantMap & comms() const { return m_comms; };
        const QList<QString> queuelist() const { return m_comms.keys(); };

    private:
        QString m_ipbxid;
        QString m_id;
        QString m_context;
        QString m_agentname;
        QString m_agentnumber;
        QString m_fullname;

        // XXXX to add
        // is this agent connected to a phone and which one ?
        // how much and which queues it is in are in pause/unpause/...
        // the phonenumber it is related to (connected or not)
        // is the agent busy or not (AGENT_ONCALL usw ...)
        QString m_status;
        QVariantMap m_comms;
        QVariantMap m_properties;
};

#endif