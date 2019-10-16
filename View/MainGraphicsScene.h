#ifndef MAINGRAPHICSSCENE_H
#define MAINGRAPHICSSCENE_H

#include "QGraphicsScene"

class MainGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MainGraphicsScene();
    ~MainGraphicsScene();

private:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // MAINGRAPHICSSCENE_H
