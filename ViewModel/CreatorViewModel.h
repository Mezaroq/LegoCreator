#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <Model/CreatorMenuModel.h>
#include <Model/CreatorRailModel.h>
#include <View/CreatorScene.h>
#include <QObject>
#include <QList>
#include <QDebug>

class CreatorViewModel : public QObject
{
    Q_OBJECT

public:
    CreatorViewModel(CreatorScene *scene);
    virtual ~CreatorViewModel();
    void createRail(CreatorResourceModel::ResourceType railType);

private:
    int currentModelId = 0;
    CreatorScene *scene;
    CreatorRailModel *focusRail = nullptr;
    QList<CreatorResourceModel*> modelItems;

public slots:
    void menuItemClicked(QListWidgetItem *item);
    void focusObjectChanged(CreatorSvgModel *newObject, CreatorSvgModel *oldObject);
};

#endif // MAINVIEWMODEL_H
