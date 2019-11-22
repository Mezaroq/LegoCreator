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
    CreatorStation(StationType stationType, QPointF stationPosition, qreal stationAngle, QPoint stationPositionOffset = QPoint(0, 0), QPoint stationTransformOffset = QPoint(0, 0));
    static QString getResource(StationType stationType);
    QPointF getStationPosition();
    void prepareStation();
    void setStationPosition();
    void moveStation(QPointF position);
    void setStationAngle();
    void setStationIndex();
    void toggleStationAngle();

private:
    StationType stationType;
    QPointF stationPosition;
    qreal stationAngle;
    QPoint stationPositionOffset;
    QPoint stationTransformOffset;
};

#endif // CREATORSTATION_H
