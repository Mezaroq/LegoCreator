#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H

#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

class CGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CGraphicsScene();

private:
     QGraphicsPixmapItem *item;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // CGRAPHICSSCENE_H
