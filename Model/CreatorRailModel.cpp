#include "CreatorRailModel.h"

CreatorRailModel::CreatorRailModel(CreatorResourceModel::ResItemType railType, QPointF railPosition, double railAngle, double railRadius, QPoint railOffset) :
    CreatorSvgModel(getResource(ResModelType::MODEL_RAIL, railType), ResModelType::MODEL_RAIL)
{
    this->railType = railType;
    this->railPosition = railPosition;
    this->railAngle = railAngle;
    this->railRadius.append(railRadius);
    this->railOffset = railOffset;
}

CreatorResourceModel::ResModelType CreatorRailModel::getResModelType()
{
    return ResModelType::MODEL_RAIL;
}
