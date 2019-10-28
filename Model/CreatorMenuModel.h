#ifndef CREATORMENUMODEL_H
#define CREATORMENUMODEL_H

#include <Model/CreatorResourceModel.h>
#include <QListWidgetItem>

class CreatorMenuModel : public CreatorResourceModel, public QListWidgetItem
{
public:
    CreatorMenuModel(ResItemType itemType, const QString name);
    virtual ResModelType getResModelType() override;
    ResItemType getResItemType();

private:
    ResItemType itemType;
};

#endif // CREATORMENUMODEL_H
