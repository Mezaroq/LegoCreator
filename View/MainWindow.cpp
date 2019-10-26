#include <View/MainWindow.h>
#include <ui_mainwindow.h>
#include <View/CGraphicsScene.h>

#include <QtSvg>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QGraphicsRectItem *rect = new QGraphicsRectItem(10, 20, 30, 40);
    QPen *pen = new QPen(Qt::black);
    rect->setPen(*pen);
    rect->setPos(100, 100);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setBrush(QColor(200, 200, 200, 127));
    CGraphicsScene *scene = new CGraphicsScene();
//    scene->setBackgroundBrush(QColor(200, 200, 200, 127));
    scene->addText("test");
    QGraphicsSvgItem *item = new QGraphicsSvgItem(":/images/logo.svg");
    item->renderer();
    item->setScale(1);
    item->setPos(50, 50);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(item);
    scene->addItem(rect);
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
