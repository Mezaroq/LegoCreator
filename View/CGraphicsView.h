#ifndef CGRAPHICSVIEW_H
#define CGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPointF>

#include <QDebug>

class CGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    CGraphicsView(QWidget* parent = nullptr);

private:
    QPointF* startPoint = new QPointF();

protected:
    virtual void wheelEvent(QWheelEvent *event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
};

#endif // CGRAPHICSVIEW_H
