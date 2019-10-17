#include <View/CGraphicsScene.h>

CGraphicsScene::CGraphicsScene() : QGraphicsScene(){}

void CGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mousePressEvent(mouseEvent);
    if(mouseEvent->button() == Qt::LeftButton) {
        qDebug() << mouseEvent->scenePos();
        qDebug() << QGraphicsScene::focusItem();
        qDebug() << mouseEvent;
    }
}
