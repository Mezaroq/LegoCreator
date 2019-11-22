#include <View/CreatorView.h>

CreatorView::CreatorView(QWidget *parent) : QGraphicsView (parent){
    setMouseTracking(true);
}

void CreatorView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    if (event->delta() > 0) {
        if (transform().m11() < MAX_ZOOM) {
            scale(SCALE_FACTOR, SCALE_FACTOR);
        }
    }
    else {
        if (transform().m11() > MIN_ZOOM) {
            scale(1/SCALE_FACTOR, 1/SCALE_FACTOR);
        }
    }
}

void CreatorView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if (event->button() == Qt::MiddleButton) {
        startPoint->setX(event->x());
        startPoint->setY(event->y());
    }
}

void CreatorView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    if (event->buttons() & Qt::MiddleButton) {
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - startPoint->x()));
        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - startPoint->y()));
        startPoint->setX(event->x());
        startPoint->setY(event->y());
    }
}
