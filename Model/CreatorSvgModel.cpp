#include "CreatorSvgModel.h"

CreatorSvgModel::CreatorSvgModel(const QString &fileName, CreatorResourceModel::ModelType modelType) : QGraphicsSvgItem(fileName)
{
    this->modelType = modelType;
}

int CreatorSvgModel::getModelType()
{
    return modelType;
}
