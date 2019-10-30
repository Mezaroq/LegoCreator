#include "CreatorResourceModel.h"

CreatorResourceModel::CreatorResourceModel()
{
    /// Resource Item
    resourceItem.insert(RAIL_FLEX,          ":/lc/resources/rails/flex_rail.svg");
    resourceItem.insert(RAIL_DOUBLE_FLEX,   ":/lc/resources/rails/double_flex_rail.svg");
    resourceItem.insert(RAIL_STRAIGHT,      ":/lc/resources/rails/straight_rail.svg");
    resourceItem.insert(RAIL_CURVED,        ":/lc/resources/rails/curved_rail.svg");
    resourceItem.insert(RAIL_LEFT_SWITCH,   ":/lc/resources/rails/left_switch_rail.svg");
    resourceItem.insert(RAIL_RIGHT_SWITCH,  ":/lc/resources/rails/right_switch_rail.svg");

    /// Resource Icon
    resourceIcon.insert(RAIL_FLEX,          ":/lc/resources/icons/flex_rail_icon.svg");
    resourceIcon.insert(RAIL_DOUBLE_FLEX,   ":/lc/resources/icons/double_flex_rail_icon.svg");
    resourceIcon.insert(RAIL_STRAIGHT,      ":/lc/resources/icons/straight_rail_icon.svg");
    resourceIcon.insert(RAIL_CURVED,        ":/lc/resources/icons/curved_rail_icon.svg");
    resourceIcon.insert(RAIL_LEFT_SWITCH,   ":/lc/resources/icons/left_switch_rail_icon.svg");
    resourceIcon.insert(RAIL_RIGHT_SWITCH,  ":/lc/resources/icons/right_switch_rail_icon.svg");
}

CreatorResourceModel::~CreatorResourceModel()
{

}

QString CreatorResourceModel::getResource(CreatorResourceModel::ModelType modelType, CreatorResourceModel::ResourceType resourceType)
{
    switch (modelType) {
    case MODEL_MENU:
        return resourceIcon.at(resourceType);
    case MODEL_RAIL:
    case MODEL_STATION:
        return resourceItem.at(resourceType);
    }
}
