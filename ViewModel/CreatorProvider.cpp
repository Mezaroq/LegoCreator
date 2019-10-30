#include "CreatorProvider.h"

CreatorProvider::CreatorProvider()
{
    createObjects();
    createMenuItems();
    createConnections();
    setObjectsData();
    mainWindow.show();
}

void CreatorProvider::createMenuItems()
{
    menuItems.insert(CreatorResourceModel::RAIL_FLEX,           new CreatorMenuModel(CreatorResourceModel::RAIL_FLEX, "Flex"));
    menuItems.insert(CreatorResourceModel::RAIL_DOUBLE_FLEX,    new CreatorMenuModel(CreatorResourceModel::RAIL_DOUBLE_FLEX, "Double Flex"));
    menuItems.insert(CreatorResourceModel::RAIL_STRAIGHT,       new CreatorMenuModel(CreatorResourceModel::RAIL_STRAIGHT, "Straight"));
    menuItems.insert(CreatorResourceModel::RAIL_CURVED,         new CreatorMenuModel(CreatorResourceModel::RAIL_CURVED, "Curved"));
    menuItems.insert(CreatorResourceModel::RAIL_LEFT_SWITCH,    new CreatorMenuModel(CreatorResourceModel::RAIL_LEFT_SWITCH, "Left Switch"));
    menuItems.insert(CreatorResourceModel::RAIL_RIGHT_SWITCH,   new CreatorMenuModel(CreatorResourceModel::RAIL_RIGHT_SWITCH, "Right Switch"));
//    menuItems.insert(CreatorMenuModel::STATION_PASSENGER,       new CreatorMenuModel(CreatorMenuModel::STATION_PASSENGER, "Passenger Station"));
//    menuItems.insert(CreatorMenuModel::STATION_FREIGHT,         new CreatorMenuModel(CreatorMenuModel::STATION_FREIGHT, "Freight Station"));
//    menuItems.insert(CreatorMenuModel::STATION_SMALL,           new CreatorMenuModel(CreatorMenuModel::STATION_SMALL, "Small Station"));
}

void CreatorProvider::createConnections()
{
    connect(menu, SIGNAL(itemClicked(QListWidgetItem*)), viewModel, SLOT(menuItemClicked(QListWidgetItem*)));
    connect(scene, SIGNAL(focusObjectChanged(CreatorSvgModel*, CreatorSvgModel*)), viewModel, SLOT(focusObjectChanged(CreatorSvgModel*, CreatorSvgModel*)));
}

void CreatorProvider::createObjects()
{
    view = mainWindow.getGraphicsView();
    menu = mainWindow.getListWidget();
    scene = new CreatorScene();
    viewModel = new CreatorViewModel(scene);
}

void CreatorProvider::setObjectsData()
{
    view->setScene(scene);

    for(CreatorMenuModel* item : menuItems) {
        menu->addItem(item);
    }
}
