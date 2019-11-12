#include "CreatorObject.h"

CreatorObject::CreatorObject(const QString object, const CreatorObject::ObjectType objectType) : QGraphicsSvgItem(object)
{
    this->objectType = objectType;
}

CreatorObject::ObjectType CreatorObject::getObjectType() const
{
    return objectType;
}
