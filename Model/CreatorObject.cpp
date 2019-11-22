#include "CreatorObject.h"

CreatorObject::CreatorObject(const QString object, const CreatorObject::ObjectType objectType) : QGraphicsSvgItem(object)
{
    this->objectType = objectType;
}

CreatorObject::ObjectType CreatorObject::getObjectType() const
{
    return objectType;
}

int CreatorObject::getObjectIndexValue(CreatorObject::ObjectType objectType)
{
    switch (objectType) {
    case CreatorObject::OBJECT_RAIL:
        return 1000;
    case CreatorObject::OBJECT_STATION:
        return 2000;
    }
}
