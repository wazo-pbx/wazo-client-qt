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

#ifndef __PARKINGPANEL_H__
#define __PARKINGPANEL_H__

#include <QtGui>
#include "xlet.h"
#include "xletinterface.h"

#include "baseengine.h"
#include "extendedtablewidget.h"
#include "parkinginfo.h"
class PeerChannel;

/*! \brief Displays the parking slots.
 */
class XletParking : public XLet
{
    Q_OBJECT

    public:
        XletParking(QWidget *parent=0);

    protected:
        void timerEvent(QTimerEvent *);  //!< receive timer events

    public slots:
        void setGuiOptions(const QVariantMap &) {};
        void parkingEvent(const QString &, const QString &, const QString &, const QVariant &);
    private slots:
        void itemClicked(QTableWidgetItem *);
        void itemDoubleClicked(QTableWidgetItem *);
    private:
        ExtendedTableWidget *m_table;  //!< Table
        int m_timerid;  //!< id of the timer
        int m_deltasec;  //!< timer period
        QList<PeerChannel *> m_mychannels;  //!< "my channels" list for transfer menu
};

class XLetParkingPlugin : public QObject, XLetInterface
{
    Q_OBJECT
    Q_INTERFACES(XLetInterface)

    public:
        XLet *newXLetInstance(QWidget *parent=0);
};


#endif