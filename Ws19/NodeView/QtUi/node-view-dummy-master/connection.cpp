#include "connection.h"

#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>

#include "connectionsocket.h"

Connection::Connection(ConnectionSocket *fromSocket, ConnectionSocket *toSocket)
{
    _fromSocket = fromSocket;
    _toSocket = toSocket;

    if (_fromSocket != nullptr)
    {
        _fromSocket->addConnection(this);
    }

    if (_toSocket != nullptr)
    {
        _toSocket->addConnection(this);
    }

    setColor(Qt::white);
}

Connection::~Connection()
{
    if (_fromSocket != nullptr)
        _fromSocket->removeConnection();

    if (_toSocket != nullptr)
        _toSocket->removeConnection();
}

ConnectionSocket* Connection::fromSocket() const
{
    return _fromSocket;
}

ConnectionSocket* Connection::toSocket() const
{
    return _toSocket;
}

void Connection::setFromSocket(ConnectionSocket *socket)
{
    _fromSocket = socket;
}

void Connection::setToSocket(ConnectionSocket *socket)
{
    _toSocket = socket;
}

void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen());
    painter->drawLine(line());
}

void Connection::setColor(QColor color)
{
    setPen(QPen(color, 2.0));
}

void Connection::trackSockets()
{
    qDebug() << "Tracking Sockets";

    if (_fromSocket != nullptr && _toSocket != nullptr)
    {
        setLine(QLineF(_fromSocket->scenePos(), _toSocket->scenePos()));
    }
}

void Connection::trackCursor(QPointF pos)
{
    qDebug() << "Tracking Cursor";

    if (_toSocket == nullptr && _fromSocket != nullptr)
    {
        if (pos.x() - _fromSocket->scenePos().x() >= 0)
        {
            setLine(QLineF(_fromSocket->scenePos(), pos - QPointF(2, 2)));
        }
        else
        {
            setLine(QLineF(_fromSocket->scenePos(), pos + QPointF(2, -2)));
        }
    }
    if (_fromSocket == nullptr && _toSocket != nullptr)
    {
        if (pos.x() - _toSocket->scenePos().x() >= 0)
        {
            setLine(QLineF(_toSocket->scenePos(), pos - QPointF(2, 2)));
        }
        else
        {
            setLine(QLineF(_toSocket->scenePos(), pos + QPointF(2, -2)));
        }
    }
}

bool Connection::tryConnect(ConnectionSocket *socket)
{
    if (!socket->hasConnectionObject())
    {
        if (_fromSocket != nullptr && socket->getDirection() == 1)
        {
            _toSocket = socket;
            socket->addConnection(this);
        }
        else if (_toSocket != nullptr && socket->getDirection() == 0)
        {
            _fromSocket = socket;
            socket->addConnection(this);
        }

        trackSockets();
        return true;
    }

    return false;
}
