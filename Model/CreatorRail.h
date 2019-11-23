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

    CreatorRail(qint32 objectID, RailType railType,
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
    virtual qint32      getObjectID() override;
    RailType            getRailType() const;
    QPointF             getRailPosition() const;
    qreal               getRailAngle() const;
    QHash<qint8, qreal> getRailPointRadius() const;
    QHash<qint8, qreal> getRailPointAngleOffset() const;
    QHash<qint8, qreal> getRailToggleRadius() const;
    QHash<qint8, qreal> getRailToggleAngleOffset() const;
    QPoint              getRailPositionOffset() const;
    QPoint              getRailTransformOffset() const;
    QPointF             getNextRailPosition();
    qreal               getNextRailAngle();
    QPointF             getToggleRailSwitch();
    QPointF             getToggleRailPoint();
    RailToggle          getRailToggle() const;
    RailPoint           getRailPoint() const;
    CreatorRail*        getConnectedRail();
    QHash<RailPoint, CreatorRail*> getConnectedRails();
    QHash<qint8, qint32> getConnectedRailsByID();
    void                setConnectedRail(RailPoint railPoint, CreatorRail *connectedRail);
    void                setRailPosition();
    void                setRailAngle();
    void                setRailIndex();
    void                setRailToggle(const RailToggle &value);
    void                setRailPoint(const RailPoint &value);
    void                removeConnectedRail(CreatorRail *connectedRail);
    void                toggleRailAngle();
    void                toggleRailSwitch();
    void                toggleRailPoint();
    void                prepareRail();

private:
    static const int    TOGGLE_SIZE = 3;
    qint32              railID;
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
