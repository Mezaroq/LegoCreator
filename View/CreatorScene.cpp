#include <View/CreatorScene.h>

CreatorScene::CreatorScene() : QGraphicsScene(){}

QPointF CreatorScene::getNextPos(QPointF currentPos, double radius, double angle)
{
    double radian = qDegreesToRadians(angle);
    double x = currentPos.x() + (radius * qCos(radian));
    double y = currentPos.y() + (radius * qSin(radian));
    return QPointF(x, y);
}

void CreatorScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    QGraphicsScene::mousePressEvent(mouseEvent);
    if(mouseEvent->button() == Qt::LeftButton) {
        CreatorSvgModel* newFocusObject = dynamic_cast<CreatorSvgModel*>(focusItem());
        if (focusObject) {
            emit focusObjectChanged(newFocusObject, focusObject);
        } else {
            emit focusObjectChanged(newFocusObject, nullptr);
        }
        focusObject = newFocusObject;
    }
    //    if (focusItem()) {
    //        qDebug() << focusItem();

    //    if(mouseEvent->button() == Qt::LeftButton) {
    //            if (focusItem()) {
    //                item = static_cast<QGraphicsSvgItem*>(focusItem());
    //            qDebug() << item->pos();
    //            qDebug() << item->boundingRect().width();

    //                qDebug() << "Next Pos:" << getNextPos(item->scenePos(), item->boundingRect().width(), 0);
    //                qDebug() << "Next Switch Pos:" << getNextPos(item->scenePos() + item->transformOriginPoint(), 320, -22.5);
    //            qDebug() << "Left Corner" << item->boundingRect().topLeft();
    //            qDebug() << "OriginPoint" << item->transformOriginPoint();
    //            item->setRotation(angle+=22.5);
    //            }
    //    } else if (mouseEvent->button() == Qt::RightButton) {
    //        qDebug() << mouseEvent->scenePos();
    //    }
}

void CreatorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void CreatorScene::keyPressEvent(QKeyEvent *keyEvent)
{
    qDebug() << keyEvent->modifiers() << keyEvent->key();
    if(focusItem()) {
        switch (keyEvent->key()) {
        case Qt::Key_Up:
            focusItem()->setPos(focusItem()->x(), focusItem()->y() - 10);
            break;
        case Qt::Key_Down:
            focusItem()->setPos(focusItem()->x(), focusItem()->y() + 10);
            break;
        case Qt::Key_Left:
            focusItem()->setPos(focusItem()->x() - 10, focusItem()->y());
            break;
        case Qt::Key_Right:
            focusItem()->setPos(focusItem()->x() + 10, focusItem()->y());
            break;
        default:
            break;
        }
    }
}
