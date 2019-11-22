#ifndef CGRAPHICSVIEW_H
#define CGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QtMath>

#include <QDebug>

class CreatorView : public QGraphicsView
{
    Q_OBJECT
public:
    CreatorView(QWidget* parent = nullptr);

private:
    QPoint* startPoint = new QPoint();
    const double SCALE_FACTOR = 1.2;
    const double MAX_ZOOM = qPow(SCALE_FACTOR, 4);
    const double MIN_ZOOM = qPow(SCALE_FACTOR, -12);
    double currentZoom = 1;

protected:
    virtual void wheelEvent(QWheelEvent *event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
};

#endif // CGRAPHICSVIEW_H
