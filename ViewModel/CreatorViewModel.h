#ifndef CREATORVIEWMODEL_H
#define CREATORVIEWMODEL_H

#include <Model/CreatorObject.h>
#include <Model/CreatorMenu.h>
#include <Model/CreatorRail.h>
#include <Model/CreatorStation.h>
#include <View/MainWindow.h>
#include <View/CreatorScene.h>
#include <View/CreatorGridSettings.h>
#include <QGraphicsEffect>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QCoreApplication>
#include <QObject>
#include <QHash>
#include <QList>

class CreatorViewModel : public QObject
{
    Q_OBJECT
public:
    enum PlateSize{
        STUD_1,
        STUD_2,
        STUD_4,
        STUD_8,
        STUD_16,
        STUD_32
    };
    enum UpdateReason{
        OBJECT_GET_FOCUS,
        OBJECT_LOST_FOCUS,
        POINTER_CHANGED,
        OBJECT_MOVED
    };

    CreatorViewModel(CreatorScene *scene, MainWindow *mainWindow);
    virtual ~CreatorViewModel();
    int  getPlateSize(PlateSize gridPlateSize);
    CreatorObject* getObjectByID(qint32 id);
    void viewModelSetup();
    void viewModelUpdate(UpdateReason reason, CreatorObject *object = nullptr);
    void drawGrid(int studsPerPlate, int gridSize, bool resize = false, qreal gridLineSize = 0.25);
    void createRail(CreatorRail::RailType railType);
    void createStation(CreatorStation::StationType stationType);

private:
    const QPoint                POSITION_POINTER_OFFSET = QPoint(-8, -8);
    const int                   POINTER_INDEX_VALUE = 10000;
    bool                        gridIsHidden = false;
    int                         objectId = 0;
    int                         currentStuds = getPlateSize(STUD_4);
    int                         currentGridSize = 10000;
    CreatorRail::RailToggle     lastRailToggle = CreatorRail::TOGGLE_NORMAL;
    MainWindow                  *mainWindow;
    CreatorScene                *scene;
    CreatorObject               *focusObject = nullptr;
    CreatorScene::PointerState  positionPointerState = CreatorScene::POINTER_DISABLED;
    QGraphicsSvgItem            *positionPointer;
    QList<CreatorObject*>       objectsList;
    QList<QGraphicsLineItem*>   gridLines;
    QGraphicsRectItem           *gridBorder;
    CreatorGridSettings         *gridSettings;
    QMessageBox                 removeAllConfirm;
    QColorDialog                *color;

public slots:
    void menuItemClicked(QListWidgetItem *item);
    void focusObjectChanged(CreatorObject *newFocusObject);
    void objectCreated(CreatorObject *newObject);
    void pointerChanged(bool isSet = false, bool positionChanged = false, QPointF position = QPoint());
    void pointerSettingsTriggered();
    void focusObjectMoved(QPointF newPosition);
    void openProjectTriggered();
    void saveProjectTriggered();
    void exportAsImageTriggered();
    void rotateObjectTriggered();
    void rotateToggleTriggered();
    void changeConnectionTriggered();
    void removeObjectTriggered();
    void removeAllTriggered(bool fileOpen  = false);
    void gridSettingsTriggered();
    void gridToggled(bool checked);
    void gridResized(int gridPlateSize, int gridSize);
    void backgroudColorChanged();
};

#endif // CREATORVIEWMODEL_H
