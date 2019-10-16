#include "View/MainWindow.h"
#include "ui_mainwindow.h"
#include "View/MainGraphicsScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    MainGraphicsScene *scene = new MainGraphicsScene();
    scene->addText("test");
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
