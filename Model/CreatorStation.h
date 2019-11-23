#ifndef CREATORSTATION_H
#define CREATORSTATION_H

#include <Model/CreatorObject.h>

class CreatorStation : public CreatorObject
{
public:
    enum StationType{
        STATION_PASSENGER,
        STATION_FREIGHT,
        STATION_SMALL
    };
    CreatorStation(qint32 objectID, StationType stationType, QPointF stationPosition, qreal stationAngle, QPoint stationPositionOffset = QPoint(0, 0), QPoint stationTransformOffset = QPoint(0, 0));
    static QString  getResource(StationType stationType);
    virtual qint32 getObjectID() override;
    StationType     getStationType() const;
    QPointF         getStationPosition() const;
    qreal           getStationAngle() const;
    QPoint          getStationPositionOffset() const;
    QPoint          getStationTransformOffset() const;
    QPointF         getStationPointPosition();
    void            prepareStation();
    void            setStationPosition();
    void            moveStation(QPointF position);
    void            setStationAngle();
    void            setStationIndex();
    void            toggleStationAngle();

private:
    qint32      stationID;
    StationType stationType;
    QPointF     stationPosition;
    qreal       stationAngle;
    QPoint      stationPositionOffset;
    QPoint      stationTransformOffset;
};

#endif // CREATORSTATION_H
