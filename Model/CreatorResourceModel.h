#ifndef CREATORRESOURCEMODEL_H
#define CREATORRESOURCEMODEL_H

#include <QList>

class CreatorResourceModel
{
public:
    enum ModelType{
        MODEL_RAIL,
        MODEL_STATION,
        MODEL_MENU
    };

    enum ResourceType{
        RAIL_FLEX,
        RAIL_DOUBLE_FLEX,
        RAIL_STRAIGHT,
        RAIL_CURVED,
        RAIL_LEFT_SWITCH,
        RAIL_RIGHT_SWITCH,
        STATION_PASSENGER,
        STATION_FREIGHT,
        STATION_SMALL
    };

    CreatorResourceModel();
    virtual ~CreatorResourceModel();
    QString getResource(ModelType modelType, ResourceType resourceType);
    virtual ModelType getModelType() = 0;

private:
    QList<QString> resourceItem;
    QList<QString> resourceIcon;
};

#endif // CREATORRESOURCEMODEL_H
