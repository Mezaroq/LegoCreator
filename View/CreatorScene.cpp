#include <View/CreatorScene.h>

CreatorScene::CreatorScene() : QGraphicsScene(){}

void CreatorScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton) {
        QGraphicsScene::mousePressEvent(mouseEvent);
        CreatorObject* newFocusObject = static_cast<CreatorObject*>(focusItem());
        emit focusObjectChanged(newFocusObject);
    }
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
