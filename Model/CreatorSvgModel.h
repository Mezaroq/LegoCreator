#ifndef CREATORSVGMODEL_H
#define CREATORSVGMODEL_H

#include <QGraphicsSvgItem>
#include <Model/CreatorResourceModel.h>

class CreatorSvgModel : public QGraphicsSvgItem
{
public:
    CreatorSvgModel(const QString &fileName, CreatorResourceModel::ModelType modelType);
    int getModelType();

private:
    CreatorResourceModel::ModelType modelType;
};

#endif // CREATORSVGMODEL_H
