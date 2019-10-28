#include "CreatorViewModel.h"

CreatorViewModel::CreatorViewModel()
{

}

CreatorViewModel::~CreatorViewModel()
{

}

void CreatorViewModel::menuItemClicked(QListWidgetItem *item)
{
    CreatorMenuModel *menuItem = static_cast<CreatorMenuModel*>(item);
    qDebug() << menuItem->getResItemType();
}

void CreatorViewModel::focusItemChanged(QGraphicsItem *newFocusItem, QGraphicsItem *oldFocusItem, Qt::FocusReason reason)
{
    if (newFocusItem) {
        qDebug() << static_cast<CreatorSvgModel*>(newFocusItem)->getModelType();
    } else {
        qDebug() << "stary" << static_cast<CreatorSvgModel*>(oldFocusItem)->getModelType();
    }
}
