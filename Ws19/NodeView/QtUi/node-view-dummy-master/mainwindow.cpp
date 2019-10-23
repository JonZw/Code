#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nodegeometry.h"
#include "connectionsocket.h"
#include "nodescene.h"

#include <QMenu>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new NodeScene();

    // PATH MUST BE MANUALLY CHANGED IF USED ON DIFFERENT SYSTEM AT THE MOMENT!
    QPixmap grid("/home/john/Dokumente/qt/node_view_dummy/resources/grid.png");
    scene->setBackgroundBrush(grid);
    scene->setSceneRect(0, 0, 5000, 5000);

    ui->graphicsView->setScene(scene);

    connect(ui->pushButton_f1, SIGNAL(released()), this, SLOT(filter_pressed()));
    connect(ui->pushButton_f2, SIGNAL(released()), this, SLOT(filter_pressed()));
    connect(ui->pushButton_f3, SIGNAL(released()), this, SLOT(filter_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;

    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : qAsConst(items))
    {
        scene->removeItem(item);
        delete item;
    }
}

void MainWindow::filter_pressed()
{
    QPushButton *button = static_cast<QPushButton*>(sender());

    QPointF center = ui->graphicsView->mapToScene(ui->graphicsView->viewport()->rect().center());
    center.setX(center.x() - 100);
    center.setY(center.y() - 65);

    if (button->text() == "Filter 1")
        scene->addNode(center, button->text(), 1, 1);
    if (button->text() == "Filter 2")
        scene->addNode(center, button->text(), 2, 3);
    if (button->text() == "Filter 3")
        scene->addNode(center, button->text(), 4, 3);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
