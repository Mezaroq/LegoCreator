#include "CreatorSvgModel.h"

CreatorSvgModel::CreatorSvgModel(const QString &fileName, int modelType) : QGraphicsSvgItem(fileName)
{
    this->modelType = modelType;
}

int CreatorSvgModel::getModelType()
{
    return modelType;
}
