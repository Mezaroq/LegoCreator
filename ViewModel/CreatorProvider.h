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
    virtual ~CreatorProvider();
    void setMenuItems();

private:
    MainWindow mainWindow;
    CreatorScene *scene = new CreatorScene();
    CreatorViewModel *viewModel = new CreatorViewModel();
    QList<CreatorMenuModel *> menuItems;
};

#endif // MAINPROVIDER_H
