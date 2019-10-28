#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <Model/CreatorMenuModel.h>
#include <Model/CreatorRailModel.h>
#include <QObject>
#include <QDebug>

class CreatorViewModel : public QObject
{
    Q_OBJECT

public:
    CreatorViewModel();
    virtual ~CreatorViewModel();

private:
    CreatorRailModel *focusRail;

public slots:
    void menuItemClicked(QListWidgetItem *item);
    void focusItemChanged(QGraphicsItem *newFocusItem, QGraphicsItem *oldFocusItem, Qt::FocusReason reason);
};

#endif // MAINVIEWMODEL_H
