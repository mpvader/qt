/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include <QImage>
#include <QFileInfo>
#include <QStringList>
#include <QSize>

QT_FORWARD_DECLARE_CLASS(QSvgRenderer)
QT_FORWARD_DECLARE_CLASS(QPaintEvent)
QT_FORWARD_DECLARE_CLASS(QEngine)

class Shower : public QWidget
{
    Q_OBJECT
public:
    Shower(const QString &file,
           const QString &engine);

    QSize sizeHint() const;
protected:
    void paintEvent(QPaintEvent *e);
private:
    QEngine *engine;
    QSvgRenderer *renderer;
    QImage buffer;
    QStringList qpsScript;
    QFileInfo qps;
    QString baseDataDir;
};

#endif
