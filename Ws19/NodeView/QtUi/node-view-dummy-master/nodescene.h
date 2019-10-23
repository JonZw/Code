#ifndef NODESCENE_H
#define NODESCENE_H

#include <QGraphicsScene>

class ConnectionSocket;
class Connection;


class NodeScene : public QGraphicsScene
{
public:
    NodeScene(QObject *parent = nullptr);
    ~NodeScene() override;

    void addNode(QPointF pos, QString name, int inputs, int outputs);
    void addConnection();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    ConnectionSocket *activeSocket = nullptr;
};

#endif // NODESCENE_H
