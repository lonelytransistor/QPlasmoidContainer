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

#define _QEVENTSIZE1 MAXN(sizeof(QActionEvent), sizeof(QChildEvent), sizeof(QCloseEvent), sizeof(QDragLeaveEvent), sizeof(QDropEvent), sizeof(QDynamicPropertyChangeEvent), sizeof(QEnterEvent), sizeof(QExposeEvent), sizeof(QFileOpenEvent), sizeof(QFocusEvent), sizeof(QGestureEvent), sizeof(QGraphicsSceneEvent), sizeof(QHelpEvent))
#define _QEVENTSIZE2 MAXN(sizeof(QHideEvent), sizeof(QIconDragEvent), sizeof(QInputEvent), sizeof(QInputMethodEvent), sizeof(QInputMethodQueryEvent), sizeof(QMoveEvent), sizeof(QPaintEvent), sizeof(QPlatformSurfaceEvent), sizeof(QResizeEvent), sizeof(QScrollEvent), sizeof(QScrollPrepareEvent))
#define _QEVENTSIZE3 MAXN(sizeof(QShortcutEvent), sizeof(QShowEvent), sizeof(QStateMachine::SignalEvent), sizeof(QStateMachine::WrappedEvent), sizeof(QStatusTipEvent), sizeof(QTimerEvent), sizeof(QWhatsThisClickedEvent), sizeof(QWindowStateChangeEvent))
#define QEVENTSIZE MAX3(_QEVENTSIZE1, _QEVENTSIZE2, _QEVENTSIZE3)

#define STREAMER_MAGIC_NUMBER "lonelytransistor"
#define STREAMER_SERVER_NAME ":com.github.lonelytransistor.applet.server"

struct UUID {
    UUID& operator=(const UUID& r) = default;
    bool operator<(const UUID& r) const {
        for (unsigned int ix=0; ix<sizeof(uuid); ix++)
            if (uuid[ix] < r.uuid[ix])
                return true;
        return false;
    }
    bool operator>(const UUID& r) const {
        for (unsigned int ix=0; ix<sizeof(uuid); ix++)
            if (uuid[ix] > r.uuid[ix])
                return true;
        return false;
    }
    UUID() {};
    UUID(const char* r) {
        if (r != nullptr) {
            memcpy(uuid, r, MAX(sizeof(uuid), strlen(r)));
        }
    }
    UUID& operator=(QString& r) {
        memcpy(uuid, r.toStdString().c_str(), sizeof(uuid));
        return *this;
    }
    bool operator==(const UUID& r) {
        return memcmp(uuid, r.uuid, sizeof(uuid)) == 0;
    }
    operator bool() {
        return uuid[0] != 0;
    }
    operator QString() {
        return toString();
    }
    void toChar(char* ch) {
        memcpy(ch, uuid, sizeof(uuid));
    }
    QString toString() {
        return QString::fromLocal8Bit(uuid, sizeof(uuid));
    }
    char uuid[36] = {0};
};
struct QSPacket {
    char magicNumber[sizeof(STREAMER_MAGIC_NUMBER)];
    char uuid[36];
    char cmd;
    char data[MAX(255, QEVENTSIZE)];
};
enum QSPacketCommand {
    CMD_CREATE = 1,
    CMD_RESIZE,
    CMD_WINDOW,
    CMD_EVENT,
    CMD_INVALID,

    CMD_UPDATE = 'U'
};
class QSPacketReader {
public:
    QSPacketReader() {
        memset(m_data, 0, sizeof(m_data));
    }
    ~QSPacketReader() {}
    bool append(char ch, QSPacket* p) {
        m_data[m_ix++] = ch;
        if (scanBuffer()) {
            memcpy(p, m_data, sizeof(QSPacket));
            memcpy(m_data, &m_data[sizeof(QSPacket)], sizeof(m_data)-sizeof(QSPacket));
            m_ix = 0;
            return true;
        } else if (!m_magicNumberFound && ch==CMD_UPDATE) {
            p->cmd = CMD_UPDATE;
            m_ix = 0;
            return true;
        }
        return false;
    }

private:
    bool scanBuffer() {
        if (m_magicNumberFound) {
            if (m_ix >= sizeof(m_data)/2) {
                m_magicNumberFound = false;
                return true;
            } else {
                return false;
            }
        }
        for (long unsigned int ix=0; ix<sizeof(m_data); ix++) {
            if (strncmp(&m_data[ix], STREAMER_MAGIC_NUMBER, sizeof(STREAMER_MAGIC_NUMBER) == 0)) {
                memcpy(m_data, &m_data[ix], sizeof(m_data)-ix);
                m_magicNumberFound = true;
                return false;
            }
        }
        return false;
    }

    long unsigned int m_ix = 0;
    char m_data[sizeof(QSPacket)*2];
    bool m_magicNumberFound = false;
};
