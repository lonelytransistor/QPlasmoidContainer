#pragma once

#include <QActionEvent>
#include <QChildEvent>
#include <QCloseEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QDynamicPropertyChangeEvent>
#include <QEnterEvent>
#include <QExposeEvent>
#include <QFileOpenEvent>
#include <QFocusEvent>
#include <QGestureEvent>
#include <QGraphicsSceneEvent>
#include <QHelpEvent>
#include <QHideEvent>
#include <QIconDragEvent>
#include <QInputEvent>
#include <QInputMethodEvent>
#include <QInputMethodQueryEvent>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QPlatformSurfaceEvent>
#include <QResizeEvent>
#include <QScrollEvent>
#include <QScrollPrepareEvent>
#include <QShortcutEvent>
#include <QShowEvent>
#include <QStateMachine>
#include <QStatusTipEvent>
#include <QTimerEvent>
#include <QWhatsThisClickedEvent>
#include <QWindowStateChangeEvent>

#include "Macros.h"

#define QEVENTSIZE MAXN(sizeof(QActionEvent), sizeof(QChildEvent), sizeof(QCloseEvent), sizeof(QDragLeaveEvent), sizeof(QDropEvent), sizeof(QDynamicPropertyChangeEvent), sizeof(QEnterEvent), sizeof(QExposeEvent), sizeof(QFileOpenEvent), sizeof(QFocusEvent), sizeof(QGestureEvent), sizeof(QGraphicsSceneEvent), sizeof(QHelpEvent), sizeof(QHideEvent), sizeof(QIconDragEvent), sizeof(QInputEvent), sizeof(QInputMethodEvent), sizeof(QInputMethodQueryEvent), sizeof(QMoveEvent), sizeof(QPaintEvent), sizeof(QPlatformSurfaceEvent), sizeof(QResizeEvent), sizeof(QScrollEvent), sizeof(QScrollPrepareEvent), sizeof(QShortcutEvent), sizeof(QShowEvent), sizeof(QStateMachine::SignalEvent), sizeof(QStateMachine::WrappedEvent), sizeof(QStatusTipEvent), sizeof(QTimerEvent), sizeof(QWhatsThisClickedEvent), sizeof(QWindowStateChangeEvent));

#define STREAMER_MAGIC_NUMBER "lonelytransistor"
#define STREAMER_SERVER_NAME ":com.github.lonelytransistor.applet.server"
