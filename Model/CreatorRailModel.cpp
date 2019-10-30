#include "CreatorRailModel.h"

CreatorRailModel::CreatorRailModel(CreatorResourceModel::ResourceType railType, QPointF railPosition, double railAngle, double railRadius, QPoint railOffset) :
    CreatorSvgModel(getResource(ModelType::MODEL_RAIL, railType), ModelType::MODEL_RAIL)
{
    this->railType = railType;
    this->railPosition = railPosition;
    this->railAngle = railAngle;
    this->railRadius.append(railRadius);
    this->railOffset = railOffset;
    setZIndex();
}

CreatorResourceModel::ModelType CreatorRailModel::getModelType()
{
    return ModelType::MODEL_RAIL;
}

void CreatorRailModel::setZIndex()
{
    switch (railType) {
    case RAIL_CURVED:
        setZValue(1);
        break;
    case RAIL_FLEX:
    case RAIL_DOUBLE_FLEX:
    case RAIL_STRAIGHT:
        setZValue(2);
        break;
    default:
        setZValue(0);
    }
}
