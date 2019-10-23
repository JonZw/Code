#include "nodegeometry.h"
#include "connectionsocket.h"
#include "nodebody.h"
#include "nodeheader.h"

#include <QFontMetrics>
#include <QDebug>

NodeGeometry::NodeGeometry(const QString _name,
                           QColor _color,
                           qreal minimal_width,
                           qreal minimal_height,
                           int inputs,
                           int outputs)
{
    color = _color;
    pressed = false;
    name = _name;

    width = calculateWidth(minimal_width, name);
    height = calculateHeight(minimal_height, inputs, outputs);

    setFlags(ItemIsSelectable | ItemIsMovable | ItemSendsGeometryChanges);

    body = new NodeBody(this, color, width, height);
    header = new NodeHeader(this, name, Qt::white, width, height);
}

NodeGeometry::~NodeGeometry()
{
    delete body;
    delete header;
}

QRectF NodeGeometry::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

void NodeGeometry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    body->paint(painter, option, widget);
    header->paint(painter, option, widget);
}

qreal NodeGeometry::calculateWidth(qreal minimal_width, QString name)
{
    QFontMetrics metrics(name);

    if (metrics.horizontalAdvance(name) > minimal_width - 10)
    {
        return metrics.horizontalAdvance(name) + 10;
    }
    else
    {
        return minimal_width;
    }
}

qreal NodeGeometry::calculateHeight(qreal minimal_height, int inputs, int outputs)
{
    if (inputs > 1 || outputs > 1)
    {
        return minimal_height + (inputs > outputs ? outputs : inputs) * 20;

    }
    else
    {
        return minimal_height;
    }
}

void NodeGeometry::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void NodeGeometry::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant NodeGeometry::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionHasChanged)
    {
        for (QGraphicsItem *item : childItems())
        {
            ConnectionSocket *socket = qgraphicsitem_cast<ConnectionSocket *>(item);
            socket->nodeMoved();
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
