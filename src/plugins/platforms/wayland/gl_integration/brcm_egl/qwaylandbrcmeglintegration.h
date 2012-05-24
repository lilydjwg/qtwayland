/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of the Qt Toolkit.
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

#ifndef QWAYLANDBRCMEGLINTEGRATION_H
#define QWAYLANDBRCMEGLINTEGRATION_H

#include "gl_integration/qwaylandglintegration.h"

#include <EGL/egl.h>
#include <EGL/eglext.h>

#define EGL_EGLEXT_PROTOTYPES
#include <EGL/eglext_brcm.h>

class QWaylandWindow;
class QWindow;

struct wl_brcm;

class QWaylandBrcmEglIntegration : public QWaylandGLIntegration
{
public:
    QWaylandBrcmEglIntegration(struct wl_display *waylandDisplay);
    ~QWaylandBrcmEglIntegration();

    void initialize();

    bool supportsThreadedOpenGL() const { return true; }

    QWaylandWindow *createEglWindow(QWindow *window);
    QPlatformOpenGLContext *createPlatformOpenGLContext(const QSurfaceFormat &glFormat, QPlatformOpenGLContext *share) const;

    EGLDisplay eglDisplay() const;

    struct wl_brcm *waylandBrcm() const;

    PFNEGLFLUSHBRCMPROC eglFlushBRCM;
    PFNEGLCREATEGLOBALIMAGEBRCMPROC eglCreateGlobalImageBRCM;
    PFNEGLDESTROYGLOBALIMAGEBRCMPROC eglDestroyGlobalImageBRCM;

private:
    static void wlDisplayHandleGlobal(wl_display *display, uint32_t id, const char *interface, uint32_t version, void *data);

    struct wl_display *m_waylandDisplay;
    struct wl_brcm *m_waylandBrcm;

    EGLDisplay m_eglDisplay;
};

#endif // QWAYLANDBRCMEGLINTEGRATION_H
