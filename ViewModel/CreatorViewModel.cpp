#include "CreatorViewModel.h"

CreatorViewModel::CreatorViewModel(CreatorScene *scene)
{
    this->scene = scene;
}

CreatorViewModel::~CreatorViewModel() {}

void CreatorViewModel::createRail(CreatorRail::RailType railType)
{   
    CreatorRail *newRail;
    QPointF railPosition = QPointF(0, 0);
    qreal railAngle = 0.0;
    QHash<qint8, qreal> railPointRadius;
    QHash<qint8, qreal> railPointAngleOffset;
    QHash<qint8, qreal> railToggleRadius;
    QHash<qint8, qreal> railToggleAngleOffset;

    if (CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject)) {
        railPosition = focusRail->getNextPoint();
        railAngle = focusRail->getNextAngle();
    }
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 40);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        newRail = new CreatorRail(railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, true);
        objectCreated(newRail);
        break;
    case CreatorRail::RAIL_DOUBLE_FLEX:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        newRail = new CreatorRail(railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, true);
        objectCreated(newRail);
        break;
    case CreatorRail::RAIL_STRAIGHT:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 160);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        newRail = new CreatorRail(railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, true);
        objectCreated(newRail);
        break;
    case CreatorRail::RAIL_CURVED:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 140.47);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 171.68);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), -11.25);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 11.25);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleRadius.insert(CreatorRail::TOGGLE_REVERSE, 174.69);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_REVERSE, 37.94);
        newRail = new CreatorRail(railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, true, true, QPoint(0, -28), QPoint(0, 28));
        objectCreated(newRail);
        break;
    case CreatorRail::RAIL_LEFT_SWITCH:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 320);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), 336.32);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 320);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), 206.68);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), 367.02);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), 57.11);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), -22.1);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), 87.68);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), 1.32);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), -44.59);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleRadius.insert(CreatorRail::TOGGLE_REVERSE, 329.85);
        railToggleRadius.insert(CreatorRail::TOGGLE_SWITCH, 346.25);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_REVERSE, 14.04);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_SWITCH, 13.76);
        newRail = new CreatorRail(railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, true, true, QPoint(0, -127), QPoint(0, 127));
        objectCreated(newRail);
        break;
    case CreatorRail::RAIL_RIGHT_SWITCH:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 320); //
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), 367.02);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 320); //
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), 57.11);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), 336.32);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), 206.68);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0); //
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), 21.18);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 0); //
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), -112.91);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), -0.4);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), 69.82);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleRadius.insert(CreatorRail::TOGGLE_REVERSE, 329.85);
        railToggleRadius.insert(CreatorRail::TOGGLE_SWITCH, 373.84);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_REVERSE, 14.04);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_SWITCH, 11.03);
        newRail = new CreatorRail(railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, true, true);
        objectCreated(newRail);
        break;
    }
}

void CreatorViewModel::menuItemClicked(QListWidgetItem *item)
{
    switch (static_cast<CreatorMenu*>(item)->getMenuType()) {
    case CreatorMenu::RAIL_FLEX:
        createRail(CreatorRail::RAIL_FLEX);
        break;
    case CreatorMenu::RAIL_DOUBLE_FLEX:
        createRail(CreatorRail::RAIL_DOUBLE_FLEX);
        break;
    case CreatorMenu::RAIL_STRAIGHT:
        createRail(CreatorRail::RAIL_STRAIGHT);
        break;
    case CreatorMenu::RAIL_CURVED:
        createRail(CreatorRail::RAIL_CURVED);
        break;
    case CreatorMenu::RAIL_LEFT_SWITCH:
        createRail(CreatorRail::RAIL_LEFT_SWITCH);
        break;
    case CreatorMenu::RAIL_RIGHT_SWITCH:
        createRail(CreatorRail::RAIL_RIGHT_SWITCH);
        break;
    case CreatorMenu::STATION_PASSENGER:
        break;
    case CreatorMenu::STATION_FREIGHT:
        break;
    case CreatorMenu::STATION_SMALL:
        break;
    }
}

void CreatorViewModel::focusObjectChanged(CreatorObject *newFocusObject)
{
    if (focusObject) {
        focusObject->graphicsEffect()->setEnabled(false);
    }

    if (newFocusObject) {
        newFocusObject->graphicsEffect()->setEnabled(true);
    }
    focusObject = newFocusObject;
}

void CreatorViewModel::objectCreated(CreatorObject *newObject)
{
    QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
    effect->setColor(QColor(46, 83, 97));
    newObject->setGraphicsEffect(effect);
    newObject->setFlag(QGraphicsItem::ItemIsFocusable);
    objectsList.append(newObject);
    scene->addItem(newObject);
    scene->setFocusItem(newObject);
    focusObjectChanged(newObject);
}

void CreatorViewModel::openProjectTriggered()
{

}

void CreatorViewModel::saveProjectTriggered()
{

}

void CreatorViewModel::exportAsImageTriggered()
{

}

void CreatorViewModel::rotateObjectTriggered()
{
    if (CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject))
        focusRail->rotateRail();
}

void CreatorViewModel::rotateToggleTriggered()
{
    if (CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject))
        focusRail->rotateToggle();
}

void CreatorViewModel::changeConnectionTriggered()
{
    if (CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject))
        focusRail->changeRailPoint();
}

void CreatorViewModel::removeObjectTriggered()
{
    if (focusObject) {
        objectsList.removeOne(focusObject);
        delete focusObject;
        focusObject = nullptr;
    }
}

void CreatorViewModel::removeAllTriggered()
{
    focusObject = nullptr;
    for (CreatorObject *object : objectsList) {
        objectsList.removeOne(object);
        delete object;
    }
    scene->update();
}
