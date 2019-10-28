#include "CreatorMenuModel.h"

CreatorMenuModel::CreatorMenuModel(ResItemType itemType, const QString name) :
    QListWidgetItem(QIcon(getResource(ResModelType::MODEL_MENU, itemType)), name)
{
    this->itemType = itemType;
}

CreatorResourceModel::ResModelType CreatorMenuModel::getResModelType()
{
    return ResModelType::MODEL_MENU;
}

CreatorResourceModel::ResItemType CreatorMenuModel::getResItemType()
{
    return itemType;
}
