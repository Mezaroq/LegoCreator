#include "View/MainGraphicsScene.h"
#include "QGraphicsSceneMouseEvent"

#include "QDebug"

MainGraphicsScene::MainGraphicsScene()
{
    parent();
}

MainGraphicsScene::~MainGraphicsScene()
{
    parent();
}

void MainGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton) {
        qDebug() << mouseEvent->scenePos();
    }
}
