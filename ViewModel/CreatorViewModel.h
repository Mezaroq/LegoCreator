#ifndef CREATORVIEWMODEL_H
#define CREATORVIEWMODEL_H

#include <Model/CreatorObject.h>
#include <Model/CreatorMenu.h>
#include <Model/CreatorRail.h>
#include <View/MainWindow.h>
#include <View/CreatorScene.h>
#include <View/CreatorGridSettings.h>
#include <QGraphicsEffect>
#include <QPainter>
#include <QFileDialog>
#include <QCoreApplication>
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

    CreatorViewModel(CreatorScene *scene, MainWindow *window);
    virtual ~CreatorViewModel();
    bool sceneHasObject(CreatorObject::ObjectType type);
    void update(UpdateReason reason, CreatorObject *object = nullptr);
    void createRail(CreatorRail::RailType railType);
    void removeRail();
    void drawGrid(qint8 studsPerPlate, int gridSize, bool resize = false, qreal gridLineSize = 0.25);

private:
    int objectId = 0;
    CreatorScene *scene;
    CreatorObject *focusObject = nullptr;
    QList<CreatorObject*> objectsList;
    QList<QGraphicsLineItem*> gridLines;
    QGraphicsSvgItem *toggleRailNextPoint;
    QGraphicsRectItem *gridBorder;
    QMessageBox removeAllConfirm;
    CreatorGridSettings *gridSettings;
    MainWindow *window;
    qint8 currentStuds;
    int currentGridSize;

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
    void gridResized(qint8 studsPerPlate, int gridSize);
};

#endif // CREATORVIEWMODEL_H
