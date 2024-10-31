// Copyright (C) 2024 David Reondo <kde@david-redondo.de>
// Copyright (C) 2024 David Edmundson <davidedmundson@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QWAYLANDTOPLEVELICONV1_P_H
#define QWAYLANDTOPLEVELICONV1_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "wayland-xdg-shell-client-protocol.h"
#include <qwayland-xdg-toplevel-icon-v1.h>

#include <QList>

QT_BEGIN_NAMESPACE

class QIcon;

namespace QtWaylandClient {

class QWaylandDisplay;

class QWaylandXdgToplevelIconManagerV1 : public QtWayland::xdg_toplevel_icon_manager_v1
{
public:
    QWaylandXdgToplevelIconManagerV1(QWaylandDisplay *display, wl_registry *registry, uint32_t id,
                                     int version);
    ~QWaylandXdgToplevelIconManagerV1() override;
    void setIcon(const QIcon &icon, ::xdg_toplevel *window);

protected:
    void xdg_toplevel_icon_manager_v1_icon_size(int32_t size) override;
    void xdg_toplevel_icon_manager_v1_done() override;

private:
    QList<int> mPreferredSizes;
    QWaylandDisplay *mDisplay;
};
} // namespace QtWaylandClient

QT_END_NAMESPACE

#endif
