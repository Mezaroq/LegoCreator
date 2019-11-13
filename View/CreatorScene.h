#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H

#include <Model/CreatorObject.h>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QtMath>
#include <QDebug>

class CreatorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CreatorScene();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void keyPressEvent(QKeyEvent *keyEvent) override;

signals:
    void focusObjectChanged(CreatorObject* newFocusObject);
};

#endif // CGRAPHICSSCENE_H
