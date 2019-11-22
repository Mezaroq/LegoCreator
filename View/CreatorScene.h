#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H

#include <Model/CreatorObject.h>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QtMath>
#include <QDebug>

class CreatorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum PointerState{
        POINTER_DISABLED,
        POINTER_ENABLED,
        POINTER_SET
    };

    CreatorScene();
    void setPointerState(PointerState state);
    void setPointerMoveVector(int studs);
    void setFocusObject(CreatorObject *focusObject);

private:
    CreatorObject* focusObject = nullptr;
    bool objectIsMoving = false;
    QPointF movingObjectOffset;
    PointerState pointerState;
    qreal pointerMoveVector = 10;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void keyPressEvent(QKeyEvent *keyEvent) override;

signals:
    void focusObjectMoved(QPointF newPosition);
    void focusObjectChanged(CreatorObject* newFocusObject);
    void pointerPositionChanged(bool isSet,bool positionChanged, QPointF position);
};

#endif // CGRAPHICSSCENE_H
