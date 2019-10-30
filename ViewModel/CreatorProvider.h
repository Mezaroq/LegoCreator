#ifndef MAINPROVIDER_H
#define MAINPROVIDER_H

#include <Model/CreatorMenuModel.h>
#include <Model/CreatorRailModel.h>
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

    QList<CreatorMenuModel *> menuItems;
};

#endif // MAINPROVIDER_H
