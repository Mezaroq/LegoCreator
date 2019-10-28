#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QtSvg>

#include <QDebug>
#include <QtMath>

class CreatorScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CreatorScene();
    QPointF getNextPos(QPointF currentPos, double radius, double angle);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // CGRAPHICSSCENE_H
