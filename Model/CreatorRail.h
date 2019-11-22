#ifndef CREATORRAIL_H
#define CREATORRAIL_H

#include <Model/CreatorObject.h>
#include <QString>
#include <QtMath>
#include <QHash>

class CreatorRail : public CreatorObject
{
public:
    enum RailType{
        RAIL_FLEX,
        RAIL_DOUBLE_FLEX,
        RAIL_STRAIGHT,
        RAIL_CURVED,
        RAIL_LEFT_SWITCH,
        RAIL_RIGHT_SWITCH
    };
    enum RailToggle{
        TOGGLE_NORMAL,
        TOGGLE_REVERSE,
        TOGGLE_SWITCH
    };
    enum RailPoint{
        POINT_NONE,
        POINT_NORMAL,
        POINT_REVERSE,
        POINT_SWITCH
    };

    /*!
     * \brief CreatorRail
     * \param railType
     * \param railPosition              pozycja startowa
     * \param railAngle                 kąt toru
     * \param railPointRadius           promienie do obliczania punktow dla kolejnych odcinkow wzgledem obecnego
     * \param railPointAngleOffset      offsety kata dla kolejnych odcinkow wzgledem obecnego
     * \param railToggleRadius          promienie do obliczania punktów zmiany orientacji
     * \param railToggleAngleOffset     offsety do obliczania punktow zmiany orientacji
     * \param railPositionOffset        offset pozycji np. zakret posiada offset bo boundingRect zaczyna sie nie w miejscu gdzie railPosition
     * \param railTransformOffset       offset dla transformacji qt (dla rotacji)
     */
    CreatorRail(RailType railType,
                QPointF railPosition,
                qreal railAngle,
                QHash<qint8, qreal> railPointRadius,
                QHash<qint8, qreal> railPointAngleOffset,
                QHash<qint8, qreal> railToggleRadius,
                QHash<qint8, qreal> railToggleAngleOffset,
                QPoint railPositionOffset = QPoint(0, 0),
                QPoint railTransformOffset = QPoint(0, 0));
    static QString      getResource(RailType railType);
    static qint8        getRailPointKey(RailToggle railToggle, RailPoint railPoint);
    RailType            getRailType();
    QPointF             getRailPosition();
    qreal               getRailAngle();
    QPointF             getNextRailPosition();
    qreal               getNextRailAngle();
    QPointF             getToggleRailSwitch();
    QPointF             getToggleRailPoint();
    RailToggle          getRailToggle();
    RailPoint           getRailPoint();
    CreatorRail*        getConnectedRail();
    QHash<RailPoint, CreatorRail*> getConnectedRails();
    void                setConnectedRail(RailPoint railPoint, CreatorRail *connectedRail);
    void                setRailPosition();
    void                setRailAngle();
    void                setRailIndex();
    void                setRailRotate(bool rotate);
    void                setRailToggle(bool toggle);
    void                removeConnectedRail(CreatorRail *connectedRail);
    void                toggleRailAngle();
    void                toggleRailSwitch();
    void                toggleRailPoint();
    void                prepareRail();

private:
    static const int    TOGGLE_SIZE = 3;
    QHash<RailPoint, CreatorRail*> connectedRails;
    RailType            railType;
    QPointF             railPosition;
    qreal               railAngle;
    QHash<qint8, qreal> railPointRadius;
    QHash<qint8, qreal> railPointAngleOffset;
    QHash<qint8, qreal> railToggleRadius;
    QHash<qint8, qreal> railToggleAngleOffset;
    QPoint              railPositionOffset;
    QPoint              railTransformOffset;
    RailToggle          railToggle = TOGGLE_NORMAL;
    RailPoint           railPoint = POINT_NORMAL;
};

#endif // CREATORRAIL_H
