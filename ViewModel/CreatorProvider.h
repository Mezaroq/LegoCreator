#ifndef CREATORPROVIDER_H
#define CREATORPROVIDER_H

#include <Model/CreatorMenu.h>
#include <View/CreatorScene.h>
#include <View/MainWindow.h>
#include <ViewModel/CreatorViewModel.h>
#include <QObject>
#include <QList>

#include <QDebug>

class CreatorProvider : public QObject
{
    Q_OBJECT
public:
    CreatorProvider();
    void createMenuItems();
    void createConnections();
    void createObjects();
    void setObjectsData();

private:
    MainWindow mainWindow;
    QGraphicsView *view;
    QListWidget *menu;
    CreatorScene *scene;
    CreatorViewModel *viewModel;
    QList<CreatorMenu *> menuItems;
    QAction *actionOpen_project;
    QAction *actionSave_project;
    QAction *actionExport_as_image;
    QAction *actionRotate_object;
    QAction *actionToggle_object;
    QAction *actionSwitch_point;
    QAction *actionRemove_object;
    QAction *actionRemove_all_objects;
    QAction *actionGrid_settings;
    QAction *actionToggle_grid;
};

#endif // CREATORPROVIDER_H
