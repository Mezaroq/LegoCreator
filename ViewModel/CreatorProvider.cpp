#include "CreatorProvider.h"

CreatorProvider::CreatorProvider()
{
    /// Create Items
    setMenuItems();

    /// Get Objects
    QGraphicsView *view = mainWindow.getGraphicsView();
    QListWidget *menu = mainWindow.getListWidget();

    /// Set Objects
    view->setScene(scene);
    for(CreatorMenuModel* item : menuItems) {
        menu->addItem(item);
    }

    /// Set Connections
    connect(menu, SIGNAL(itemClicked(QListWidgetItem*)), viewModel, SLOT(menuItemClicked(QListWidgetItem*)));
    connect(scene, SIGNAL(focusItemChanged(QGraphicsItem*, QGraphicsItem*, Qt::FocusReason)), viewModel, SLOT(focusItemChanged(QGraphicsItem*, QGraphicsItem*, Qt::FocusReason)));

    /// Run
    mainWindow.show();

    /// TESTING
    CreatorRailModel *railItem = new CreatorRailModel(CreatorRailModel::RAIL_STRAIGHT, QPointF(0, 0), 0, 160);
    railItem->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(railItem);
}

CreatorProvider::~CreatorProvider()
{

}

void CreatorProvider::setMenuItems()
{
    menuItems.insert(CreatorMenuModel::RAIL_FLEX,           new CreatorMenuModel(CreatorMenuModel::RAIL_FLEX, "Flex"));
    menuItems.insert(CreatorMenuModel::RAIL_DOUBLE_FLEX,    new CreatorMenuModel(CreatorMenuModel::RAIL_DOUBLE_FLEX, "Double Flex"));
    menuItems.insert(CreatorMenuModel::RAIL_STRAIGHT,       new CreatorMenuModel(CreatorMenuModel::RAIL_STRAIGHT, "Straight"));
    menuItems.insert(CreatorMenuModel::RAIL_CURVED,         new CreatorMenuModel(CreatorMenuModel::RAIL_CURVED, "Curved"));
    menuItems.insert(CreatorMenuModel::RAIL_LEFT_SWITCH,    new CreatorMenuModel(CreatorMenuModel::RAIL_LEFT_SWITCH, "Left Switch"));
    menuItems.insert(CreatorMenuModel::RAIL_RIGHT_SWITCH,   new CreatorMenuModel(CreatorMenuModel::RAIL_RIGHT_SWITCH, "Right Switch"));
//    menuItems.insert(CreatorMenuModel::STATION_PASSENGER,   new CreatorMenuModel(CreatorMenuModel::STATION_PASSENGER, "Passenger Station"));
//    menuItems.insert(CreatorMenuModel::STATION_FREIGHT,     new CreatorMenuModel(CreatorMenuModel::STATION_FREIGHT, "Freight Station"));
//    menuItems.insert(CreatorMenuModel::STATION_SMALL,       new CreatorMenuModel(CreatorMenuModel::STATION_SMALL, "Small Station"));
}
