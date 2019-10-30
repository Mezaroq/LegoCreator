#include "CreatorViewModel.h"

CreatorViewModel::CreatorViewModel(CreatorScene *scene)
{
    this->scene = scene;
}

CreatorViewModel::~CreatorViewModel()
{

}

void CreatorViewModel::createRail(CreatorResourceModel::ResourceType railType)
{
    qDebug() << focusRail;
    if (focusRail || (currentModelId == 0)) {
        CreatorRailModel* railItem = new CreatorRailModel(railType, QPointF(0, 0), 0, 160);
        railItem->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
        scene->addItem(railItem);
        modelItems.insert(currentModelId, railItem);
        currentModelId++;
    }
}

void CreatorViewModel::menuItemClicked(QListWidgetItem *item)
{
    CreatorMenuModel *menuItem = static_cast<CreatorMenuModel*>(item);
    switch (menuItem->getResourceType()) {
    case CreatorMenuModel::RAIL_FLEX:
        createRail(CreatorMenuModel::RAIL_FLEX);
        break;
    case CreatorMenuModel::RAIL_DOUBLE_FLEX:
        createRail(CreatorMenuModel::RAIL_DOUBLE_FLEX);
        break;
    case CreatorMenuModel::RAIL_STRAIGHT:
        createRail(CreatorMenuModel::RAIL_STRAIGHT);
        break;
    case CreatorMenuModel::RAIL_CURVED:
        createRail(CreatorMenuModel::RAIL_CURVED);
        break;
    case CreatorMenuModel::RAIL_LEFT_SWITCH:
        createRail(CreatorMenuModel::RAIL_LEFT_SWITCH);
        break;
    case CreatorMenuModel::RAIL_RIGHT_SWITCH:
        createRail(CreatorMenuModel::RAIL_RIGHT_SWITCH);
        break;
    case CreatorMenuModel::STATION_PASSENGER:
        break;
    case CreatorMenuModel::STATION_FREIGHT:
        break;
    case CreatorMenuModel::STATION_SMALL:
        break;
    }
}

void CreatorViewModel::focusObjectChanged(CreatorSvgModel *newObject, CreatorSvgModel *oldObject)
{
    if (newObject) {
        switch (newObject->getModelType()) {
        case CreatorResourceModel::MODEL_RAIL:
            focusRail = static_cast<CreatorRailModel*>(newObject);
            break;
        case CreatorResourceModel::MODEL_STATION:
            qDebug() << "STATION SET wsk";
            break;
        }
    } else if(oldObject && (newObject == nullptr)){
        switch (oldObject->getModelType()) {
        case CreatorResourceModel::MODEL_RAIL:
            focusRail = nullptr;
            break;
        case CreatorResourceModel::MODEL_STATION:
            qDebug() << "STATION SET nullptr";
            break;
        }
    }
}
