#ifndef CREATORVIEWMODEL_H
#define CREATORVIEWMODEL_H

#include <Model/CreatorObject.h>
#include <Model/CreatorMenu.h>
#include <Model/CreatorRail.h>
#include <View/CreatorScene.h>
#include <QGraphicsEffect>
#include <QObject>
#include <QHash>
#include <QList>
#include <QDebug>

class CreatorViewModel : public QObject
{
    Q_OBJECT

public:
    CreatorViewModel(CreatorScene *scene);
    virtual ~CreatorViewModel();
    void createRail(CreatorRail::RailType railType);

private:
    int objectId = 0;
    CreatorScene *scene;
    CreatorObject *focusObject = nullptr;
    QList<CreatorObject*> objectsList;


public slots:
    void menuItemClicked(QListWidgetItem *item);
    void focusObjectChanged(CreatorObject *newFocusObject);
    void objectCreated(CreatorObject *newObject);
    void openProjectTriggered();
    void saveProjectTriggered();
    void exportAsImageTriggered();
    void rotateObjectTriggered();
    void rotateToggleTriggered();
    void changeConnectionTriggered();
    void removeObjectTriggered();
    void removeAllTriggered();
};

#endif // CREATORVIEWMODEL_H
