#include <View/CGraphicsView.h>

CGraphicsView::CGraphicsView(QWidget *parent) : QGraphicsView (parent){}

void CGraphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    if (event->delta() > 0) {
        scale(scaleFactor, scaleFactor);
    }
    else {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}

void CGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if (event->button() == Qt::MiddleButton) {
        startPoint->setX(event->x());
        startPoint->setY(event->y());
    }
}

void CGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    if (event->buttons() & Qt::MiddleButton) {
        QPointF currentPoint = mapToScene(startPoint->toPoint());
        QPointF newPoint = mapToScene(event->pos());
        QPointF translation = newPoint - currentPoint;

        translate(translation.x(), translation.y());

        startPoint->setX(event->x());
        startPoint->setY(event->y());
    }
}
