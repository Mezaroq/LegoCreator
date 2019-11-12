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

#include <QDialog>
#include <QDebug>

class CreatorViewModel : public QObject
{
    Q_OBJECT

public:
    enum UpdateReason{
        FOCUS_GET,
        FOCUS_LOST,
        POSITION_CHANGED
    };

    CreatorViewModel(CreatorScene *scene);
    virtual ~CreatorViewModel();
    bool sceneHasObject(CreatorObject::ObjectType type);
    void createRail(CreatorRail::RailType railType);
    void removeRail();
    void update(UpdateReason reason, CreatorObject *object = nullptr);

private:
    int objectId = 0;
    CreatorScene *scene;
    CreatorObject *focusObject = nullptr;
    QList<CreatorObject*> objectsList;
    QGraphicsSvgItem *toggleRailNextPoint;

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
