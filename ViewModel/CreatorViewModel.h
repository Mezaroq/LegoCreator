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
#include <QMessageBox>
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
    void update(UpdateReason reason, CreatorObject *object = nullptr);
    void createRail(CreatorRail::RailType railType);
    void removeRail();
    void drawGrid(qint8 studsPerPlate, qint16 gridSize, bool resize = false, qreal gridLineSize = 0.25);

private:
    int objectId = 0;
    CreatorScene *scene;
    CreatorObject *focusObject = nullptr;
    QList<CreatorObject*> objectsList;
    QList<QGraphicsLineItem*> gridLines;
    QGraphicsSvgItem *toggleRailNextPoint;
    QGraphicsRectItem *gridBorder;
    QMessageBox removeAllConfirm;

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
    void gridSettingsTriggered();
    void gridToggled(bool checked);
};

#endif // CREATORVIEWMODEL_H
