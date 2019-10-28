#ifndef CREATORSVGMODEL_H
#define CREATORSVGMODEL_H

#include <QGraphicsSvgItem>

class CreatorSvgModel : public QGraphicsSvgItem
{
public:
    CreatorSvgModel(const QString &fileName, int modelType);
    int getModelType();

private:
    int modelType;
};

#endif // CREATORSVGMODEL_H
