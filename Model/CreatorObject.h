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
    int getObjectIndexValue(ObjectType objectType);
    static qint32 getNextObjectID(int startValue = 0);
    virtual qint32 getObjectID() = 0;

private:
    ObjectType objectType;
};

#endif // CREATOROBJECT_H
