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
    menuItems.insert(CreatorMenu::RAIL_DOUBLE_FLEX,    new CreatorMenu(CreatorMenu::RAIL_DOUBLE_FLEX, "Double Flex"));
    menuItems.insert(CreatorMenu::RAIL_STRAIGHT,       new CreatorMenu(CreatorMenu::RAIL_STRAIGHT, "Straight"));
    menuItems.insert(CreatorMenu::RAIL_CURVED,         new CreatorMenu(CreatorMenu::RAIL_CURVED, "Curved"));
    menuItems.insert(CreatorMenu::RAIL_LEFT_SWITCH,    new CreatorMenu(CreatorMenu::RAIL_LEFT_SWITCH, "Left Switch"));
    menuItems.insert(CreatorMenu::RAIL_RIGHT_SWITCH,   new CreatorMenu(CreatorMenu::RAIL_RIGHT_SWITCH, "Right Switch"));
}

void CreatorProvider::createConnections()
{
    connect(menu, SIGNAL(itemClicked(QListWidgetItem*)), viewModel, SLOT(menuItemClicked(QListWidgetItem*)));
    connect(scene, SIGNAL(focusObjectChanged(CreatorObject*)), viewModel, SLOT(focusObjectChanged(CreatorObject*)));
    connect(actionOpen_project, SIGNAL(triggered()), viewModel, SLOT(openProjectTriggered()));
    connect(actionSave_project, SIGNAL(triggered()), viewModel, SLOT(saveProjectTriggered()));
    connect(actionExport_as_image, SIGNAL(triggered()), viewModel, SLOT(exportAsImageTriggered()));
    connect(actionRotate_object, SIGNAL(triggered()), viewModel, SLOT(rotateObjectTriggered()));
    connect(actionRotate_toggle, SIGNAL(triggered()), viewModel, SLOT(rotateToggleTriggered()));
    connect(actionChange_connection, SIGNAL(triggered()), viewModel, SLOT(changeConnectionTriggered()));
    connect(actionRemove_object, SIGNAL(triggered()), viewModel, SLOT(removeObjectTriggered()));
    connect(actionRemove_all, SIGNAL(triggered()), viewModel, SLOT(removeAllTriggered()));
}

void CreatorProvider::createObjects()
{
    view = mainWindow.getGraphicsView();
    menu = mainWindow.getListWidget();
    actionOpen_project = mainWindow.getActionOpenProject();
    actionSave_project = mainWindow.getActionSaveProject();
    actionExport_as_image = mainWindow.getActionExportAsImage();
    actionRotate_object = mainWindow.getActionRotateObject();
    actionRotate_toggle = mainWindow.getActionRotateToggle();
    actionChange_connection = mainWindow.getActionChangeConnection();
    actionRemove_object = mainWindow.getActionRemoveObject();
    actionRemove_all = mainWindow.getActionRemoveAll();
    scene = new CreatorScene();
    viewModel = new CreatorViewModel(scene);
}

void CreatorProvider::setObjectsData()
{
    view->setScene(scene);

    for(CreatorMenu* item : menuItems) {
        menu->addItem(item);
    }

    /// TESTING
    const int STUD_SIZE = 10;
    int STUD_PER_PLATE = 4; //VALUE FROM USER
    const int PLATE_SIZE = STUD_SIZE * STUD_PER_PLATE;
    int GRID_SIZE = 10000 / 2; //VALUE BEFORE /2 IS FROM USER
    const int AMOUNT_OF_PLATES = GRID_SIZE / PLATE_SIZE;
    const int MIN_GRID_POSITION = -(PLATE_SIZE * AMOUNT_OF_PLATES);
    const int MAX_GRID_POSITION = PLATE_SIZE * AMOUNT_OF_PLATES;
    qreal GRID_LINE_SIZE = 0.25;

    for (int plate = MIN_GRID_POSITION; plate <= MAX_GRID_POSITION; plate+=PLATE_SIZE) {
        scene->addLine(QLineF(plate, MIN_GRID_POSITION, plate, MAX_GRID_POSITION), QPen(Qt::gray, GRID_LINE_SIZE));
        scene->addLine(QLineF(MIN_GRID_POSITION, plate, MAX_GRID_POSITION, plate), QPen(Qt::gray, GRID_LINE_SIZE));
    }
}
