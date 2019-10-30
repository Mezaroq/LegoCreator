#ifndef CREATORRAILMODEL_H
#define CREATORRAILMODEL_H

#include <Model/CreatorResourceModel.h>
#include <Model/CreatorSvgModel.h>

class CreatorRailModel : public CreatorResourceModel, public CreatorSvgModel
{
public:
    CreatorRailModel(ResourceType railType, QPointF railPosition, double railAngle, double railRadius, QPoint railOffset = QPoint(0, 0));
    virtual ModelType getModelType() override;
    void setZIndex();

private:
    ResourceType railType;
    QPointF railPosition;
    double railAngle;
    QList<double> railRadius;
    QPoint railOffset;
};

#endif // CREATORRAILMODEL_H
