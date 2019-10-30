#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <Model/CreatorSvgModel.h>
#include <QtSvg>

#include <QDebug>
#include <QtMath>

class CreatorScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CreatorScene();
    QPointF getNextPos(QPointF currentPos, double radius, double angle);

private:
    CreatorSvgModel* focusObject = nullptr;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void keyPressEvent(QKeyEvent *keyEvent);

signals:
    void focusObjectChanged(CreatorSvgModel* newObject, CreatorSvgModel* oldObject);
};

#endif // CGRAPHICSSCENE_H
