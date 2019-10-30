#include "CreatorMenuModel.h"

CreatorMenuModel::CreatorMenuModel(ResourceType menuType, const QString name) :
    QListWidgetItem(QIcon(getResource(ModelType::MODEL_MENU, menuType)), name)
{
    this->menuType = menuType;
}

CreatorResourceModel::ModelType CreatorMenuModel::getModelType()
{
    return ModelType::MODEL_MENU;
}

CreatorResourceModel::ResourceType CreatorMenuModel::getResourceType()
{
    return menuType;
}
