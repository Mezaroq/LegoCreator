#include <View/CreatorScene.h>

CreatorScene::CreatorScene() : QGraphicsScene(){}

void CreatorScene::setPointerState(CreatorScene::PointerState state)
{
    this->pointerState = state;
}

void CreatorScene::setPointerMoveVector(int studs)
{
    this->pointerMoveVector = 10 * studs;
}

void CreatorScene::setFocusObject(CreatorObject *focusObject)
{
    this->focusObject = focusObject;
}

void CreatorScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton) {
        if (pointerState == POINTER_ENABLED) {
            emit pointerPositionChanged(true,false, QPointF((round(mouseEvent->scenePos().x() / pointerMoveVector) * pointerMoveVector), (round(mouseEvent->scenePos().y() / pointerMoveVector) * pointerMoveVector)));
            return;
        }
        QGraphicsScene::mousePressEvent(mouseEvent);
        CreatorObject* newFocusObject = static_cast<CreatorObject*>(focusItem());
        emit focusObjectChanged(newFocusObject);
        if (focusObject) {
            objectIsMoving = true;
            movingObjectOffset.setX(mouseEvent->scenePos().x() - focusObject->pos().x());
            movingObjectOffset.setY(mouseEvent->scenePos().y() - focusObject->pos().y());
        }
    }
}

void CreatorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (pointerState == POINTER_ENABLED)
        emit pointerPositionChanged(false, true, QPointF((round(mouseEvent->scenePos().x() / pointerMoveVector) * pointerMoveVector), (round(mouseEvent->scenePos().y() / pointerMoveVector) * pointerMoveVector)));
    if (objectIsMoving) {
        QPointF movePoint = QPointF(mouseEvent->scenePos() - movingObjectOffset);
        movePoint.setX(round((movePoint.x() / pointerMoveVector)) * pointerMoveVector);
        movePoint.setY(round((movePoint.y() / pointerMoveVector)) * pointerMoveVector);
        emit focusObjectMoved(movePoint);
    }
}

void CreatorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (objectIsMoving)
        objectIsMoving = false;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void CreatorScene::keyPressEvent(QKeyEvent *keyEvent)
{
//    qDebug() << keyEvent->modifiers() << keyEvent->key();
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
