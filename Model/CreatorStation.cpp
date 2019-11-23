#include "CreatorStation.h"

CreatorStation::CreatorStation(qint32 objectID, StationType stationType, QPointF stationPosition, qreal stationAngle, QPoint stationPositionOffset, QPoint stationTransformOffset) :
    CreatorObject(getResource(stationType), CreatorObject::OBJECT_STATION)
{
    this->stationType = stationType;
    this->stationPosition = stationPosition + stationPositionOffset;
    this->stationAngle = stationAngle;
    this->stationPositionOffset = stationPositionOffset;
    this->stationTransformOffset = stationTransformOffset;
    this->stationID = objectID;
    prepareStation();
}

QString CreatorStation::getResource(CreatorStation::StationType stationType)
{
    switch (stationType) {
    case CreatorStation::STATION_PASSENGER:
        return ":/creator/resources/objects/object_station_passenger.svg";
    case CreatorStation::STATION_FREIGHT:
        return ":/creator/resources/objects/object_station_freight.svg";
    case CreatorStation::STATION_SMALL:
        return ":/creator/resources/objects/object_station_small.svg";
    }
}

qint32 CreatorStation::getObjectID()
{
    return stationID;
}

CreatorStation::StationType CreatorStation::getStationType() const
{
    return stationType;
}

QPointF CreatorStation::getStationPosition() const
{
    return stationPosition - stationPositionOffset;
}

qreal CreatorStation::getStationAngle() const
{
    return stationAngle;
}

QPoint CreatorStation::getStationPositionOffset() const
{
    return stationPositionOffset;
}

QPoint CreatorStation::getStationTransformOffset() const
{
    return stationTransformOffset;
}

QPointF CreatorStation::getStationPointPosition()
{
    return stationPosition - stationPositionOffset;
}

void CreatorStation::prepareStation()
{
    setStationPosition();
    setStationAngle();
    setStationIndex();
    setTransformOriginPoint(stationTransformOffset);
}

void CreatorStation::setStationPosition()
{
    setPos(stationPosition);
}

void CreatorStation::moveStation(QPointF position)
{
    stationPosition = position;
    setStationPosition();
}

void CreatorStation::setStationAngle()
{
    setRotation(stationAngle);
}

void CreatorStation::setStationIndex()
{
    switch (stationType) {
    case CreatorStation::STATION_PASSENGER:
        setZValue(getObjectIndexValue(CreatorObject::OBJECT_STATION) + 10);
        break;
    case CreatorStation::STATION_FREIGHT:
        setZValue(getObjectIndexValue(CreatorObject::OBJECT_STATION) + 10);
        break;
    case CreatorStation::STATION_SMALL:
        setZValue(getObjectIndexValue(CreatorObject::OBJECT_STATION) + 10);
        break;
    }
}

void CreatorStation::toggleStationAngle()
{
    setRotation(stationAngle-=22.5);
}
