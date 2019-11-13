#ifndef CREATOROBJECT_H
#define CREATOROBJECT_H

#include <QGraphicsSvgItem>

class CreatorObject : public QGraphicsSvgItem
{
public:
    enum ObjectType{
        OBJECT_RAIL,
        OBJECT_STATION
    };
    CreatorObject(const QString object, const ObjectType objectType);
    ObjectType getObjectType() const;

private:
    ObjectType objectType;
};

#endif // CREATOROBJECT_H
