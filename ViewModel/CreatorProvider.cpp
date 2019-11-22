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
    menuItems.insert(CreatorMenu::RAIL_FLEX,           new CreatorMenu(CreatorMenu::RAIL_FLEX, "Flex"));
    menuItems.insert(CreatorMenu::RAIL_DOUBLE_FLEX,    new CreatorMenu(CreatorMenu::RAIL_DOUBLE_FLEX, "Double\nFlex"));
    menuItems.insert(CreatorMenu::RAIL_STRAIGHT,       new CreatorMenu(CreatorMenu::RAIL_STRAIGHT, "Straight"));
    menuItems.insert(CreatorMenu::RAIL_CURVED,         new CreatorMenu(CreatorMenu::RAIL_CURVED, "Curved"));
    menuItems.insert(CreatorMenu::RAIL_LEFT_SWITCH,    new CreatorMenu(CreatorMenu::RAIL_LEFT_SWITCH, "Left\nSwitch"));
    menuItems.insert(CreatorMenu::RAIL_RIGHT_SWITCH,   new CreatorMenu(CreatorMenu::RAIL_RIGHT_SWITCH, "Right\nSwitch"));
    menuItems.insert(CreatorMenu::STATION_PASSENGER,   new CreatorMenu(CreatorMenu::STATION_PASSENGER, "Passenger\nStation"));
    menuItems.insert(CreatorMenu::STATION_FREIGHT,     new CreatorMenu(CreatorMenu::STATION_FREIGHT, "Freight\nStation"));
}

void CreatorProvider::createConnections()
{
    connect(menu, SIGNAL(itemClicked(QListWidgetItem*)), viewModel, SLOT(menuItemClicked(QListWidgetItem*)));
    connect(scene, SIGNAL(focusObjectChanged(CreatorObject*)), viewModel, SLOT(focusObjectChanged(CreatorObject*)));
    connect(scene, SIGNAL(pointerPositionChanged(bool, bool, QPointF)), viewModel, SLOT(pointerChanged(bool, bool, QPointF)));
    connect(scene, SIGNAL(focusObjectMoved(QPointF)), viewModel, SLOT(focusObjectMoved(QPointF)));
    connect(actionOpen_project, SIGNAL(triggered()), viewModel, SLOT(openProjectTriggered()));
    connect(actionSave_project, SIGNAL(triggered()), viewModel, SLOT(saveProjectTriggered()));
    connect(actionExport_as_image, SIGNAL(triggered()), viewModel, SLOT(exportAsImageTriggered()));
    connect(actionRotate_object, SIGNAL(triggered()), viewModel, SLOT(rotateObjectTriggered()));
    connect(actionToggle_object, SIGNAL(triggered()), viewModel, SLOT(rotateToggleTriggered()));
    connect(actionSwitch_point, SIGNAL(triggered()), viewModel, SLOT(changeConnectionTriggered()));
    connect(actionRemove_object, SIGNAL(triggered()), viewModel, SLOT(removeObjectTriggered()));
    connect(actionRemove_all_objects, SIGNAL(triggered()), viewModel, SLOT(removeAllTriggered()));
    connect(actionGrid_settings, SIGNAL(triggered()), viewModel, SLOT(gridSettingsTriggered()));
    connect(actionToggle_grid, SIGNAL(toggled(bool)), viewModel, SLOT(gridToggled(bool)));
    connect(actionChange_pointer, SIGNAL(triggered()), viewModel, SLOT(pointerChanged()));
    connect(actionPointer_settings, SIGNAL(triggered()), viewModel, SLOT(pointerSettingsTriggered()));
}

void CreatorProvider::createObjects()
{
    view = mainWindow.getGraphicsView();
    menu = mainWindow.getListWidget();
    actionOpen_project = mainWindow.getActionOpenProject();
    actionSave_project = mainWindow.getActionSaveProject();
    actionExport_as_image = mainWindow.getActionExportAsImage();
    actionRotate_object = mainWindow.getActionRotateObject();
    actionToggle_object = mainWindow.getActionToggleObject();
    actionSwitch_point = mainWindow.getActionSwitchPoint();
    actionRemove_object = mainWindow.getActionRemoveObject();
    actionRemove_all_objects = mainWindow.getActionRemoveAllObjects();
    actionGrid_settings = mainWindow.getActionGridSettings();
    actionToggle_grid = mainWindow.getActionToggleGrid();
    actionChange_pointer = mainWindow.getActionChangePointer();
    actionPointer_settings = mainWindow.getActionPointerSettings();
    scene = new CreatorScene();
    viewModel = new CreatorViewModel(scene, &mainWindow);
}

void CreatorProvider::setObjectsData()
{
    view->setScene(scene);

    for(CreatorMenu* item : menuItems) {
        menu->addItem(item);
    }
}
