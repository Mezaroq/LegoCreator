#ifndef CREATORMENUMODEL_H
#define CREATORMENUMODEL_H

#include <Model/CreatorResourceModel.h>
#include <QListWidgetItem>

class CreatorMenuModel : public CreatorResourceModel, public QListWidgetItem
{
public:
    CreatorMenuModel(ResourceType menuType, const QString name);
    virtual ModelType getModelType() override;
    ResourceType getResourceType();

private:
    ResourceType menuType;
};

#endif // CREATORMENUMODEL_H
