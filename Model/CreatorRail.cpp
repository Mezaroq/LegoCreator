#include "CreatorRail.h"

CreatorRail::CreatorRail(CreatorRail::RailType railType, QPointF railPosition, qreal railAngle, QHash<qint8, qreal> railPointRadius, QHash<qint8, qreal> railPointAngleOffset, QHash<qint8, qreal> railToggleRadius, QHash<qint8, qreal> railToggleAngleOffset, bool railIsToggle, bool railIsRotate, QPoint railPositionOffset, QPoint railTransformOffset) :
    CreatorObject(CreatorRail::getResource(railType), CreatorObject::OBJECT_RAIL)
{
    this->railType = railType;
    this->railPosition = railPosition;
    this->railAngle = railAngle;
    this->railPointRadius = railPointRadius;
    this->railPointAngleOffset = railPointAngleOffset;
    this->railToggleRadius = railToggleRadius;
    this->railToggleAngleOffset = railToggleAngleOffset;
    this->railPositionOffset = railPositionOffset;
    this->railTransformOffset = railTransformOffset;
    this->railIsRotate = railIsRotate;
    this->railIsToggle = railIsToggle;
    prepareRail();
}

QString CreatorRail::getResource(CreatorRail::RailType railType)
{
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
        return ":/creator/resources/objects/object_rail_flex.svg";
    case CreatorRail::RAIL_DOUBLE_FLEX:
        return ":/creator/resources/objects/object_rail_double_flex.svg";
    case CreatorRail::RAIL_STRAIGHT:
        return ":/creator/resources/objects/object_rail_straight.svg";
    case CreatorRail::RAIL_CURVED:
        return ":/creator/resources/objects/object_rail_curved.svg";
    case CreatorRail::RAIL_LEFT_SWITCH:
        return ":/creator/resources/objects/object_rail_left_switch.svg";
    case CreatorRail::RAIL_RIGHT_SWITCH:
        return ":/creator/resources/objects/object_rail_right_switch.svg";
    }
}

qint8 CreatorRail::getRailPointKey(CreatorRail::RailToggle railToggle, CreatorRail::RailPoint railPoint)
{
    return (railToggle * CreatorRail::TOGGLE_SIZE) + railPoint;
}

CreatorRail::RailType CreatorRail::getRailType()
{
    return railType;
}

QPointF CreatorRail::getNextPoint()
{
    qreal radianAngle;
    qreal positionX = 0.0;
    qreal positionY = 0.0;

    radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.value( getRailPointKey(railToggle, railPoint) ));
    positionX = railPosition.x() + (railPointRadius.value( getRailPointKey(railToggle, railPoint) ) * qCos(radianAngle));
    positionY = railPosition.y() + (railPointRadius.value( getRailPointKey(railToggle, railPoint) ) * qSin(radianAngle));
    return QPointF(positionX, positionY);
}

qreal CreatorRail::getNextAngle()
{
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
    case CreatorRail::RAIL_DOUBLE_FLEX:
    case CreatorRail::RAIL_STRAIGHT:
        if (railPoint == POINT_REVERSE)
            return railAngle + 180;
        return railAngle;
    case CreatorRail::RAIL_CURVED:
        switch (railToggle) {
        case CreatorRail::TOGGLE_NORMAL:
            if (railPoint == POINT_REVERSE)
                return railAngle + 180;
            return railAngle - 22.5;
        case CreatorRail::TOGGLE_REVERSE:
            if (railPoint == POINT_REVERSE)
                return railAngle + 180;
            return railAngle + 22.5;
        default:
            return railAngle;
        }
    case CreatorRail::RAIL_LEFT_SWITCH:
        switch (railToggle) {
        case CreatorRail::TOGGLE_NORMAL:
            switch (railPoint) {
            case CreatorRail::POINT_NORMAL:
                return railAngle;
            case CreatorRail::POINT_REVERSE:
                return railAngle + 180;
            case CreatorRail::POINT_SWITCH:
                return railAngle - 22.5;
            }
        case CreatorRail::TOGGLE_REVERSE:
            switch (railPoint) {
            case CreatorRail::POINT_NORMAL:
                return railAngle;
            case CreatorRail::POINT_REVERSE:
                return railAngle + 180;
            case CreatorRail::POINT_SWITCH:
                return railAngle + 157.5;
            }
            break;
        case CreatorRail::TOGGLE_SWITCH:
            switch (railPoint) {
            case CreatorRail::POINT_NORMAL:
                return railAngle + 22.5;
            case CreatorRail::POINT_REVERSE:
                return railAngle + 180;
            case CreatorRail::POINT_SWITCH:
                return railAngle - 157.5;
            }
        }
    case CreatorRail::RAIL_RIGHT_SWITCH:
        switch (railToggle) {
        case CreatorRail::TOGGLE_NORMAL:
            switch (railPoint) {
            case CreatorRail::POINT_NORMAL:
                return railAngle;
            case CreatorRail::POINT_REVERSE:
                return railAngle + 180;
            case CreatorRail::POINT_SWITCH:
                return railAngle + 22.5;
            }
        case CreatorRail::TOGGLE_REVERSE:
            switch (railPoint) {
            case CreatorRail::POINT_NORMAL:
                return railAngle;
            case CreatorRail::POINT_REVERSE:
                return railAngle + 180;
            case CreatorRail::POINT_SWITCH:
                return railAngle - 157.5;
            }
            break;
        case CreatorRail::TOGGLE_SWITCH:
            switch (railPoint) {
            case CreatorRail::POINT_NORMAL:
                return railAngle - 22.5;
            case CreatorRail::POINT_REVERSE:
                return railAngle + 180;
            case CreatorRail::POINT_SWITCH:
                return railAngle + 157.5;
            }
        }
    }
}

QPointF CreatorRail::getTogglePoint()
{
    switch (railToggle) {
    case CreatorRail::TOGGLE_NORMAL:
        return railPosition + railPositionOffset;
    case CreatorRail::TOGGLE_REVERSE:
    case CreatorRail::TOGGLE_SWITCH:
        qreal radianAngle = qDegreesToRadians(railAngle + railToggleAngleOffset.value(railToggle));
        qreal positionX = railPosition.x() + (railToggleRadius.value(railToggle) * qCos(radianAngle));
        qreal positionY = railPosition.y() + (railToggleRadius.value(railToggle) * qSin(radianAngle));
        return (QPointF(positionX, positionY) + railPositionOffset);
    }
}

void CreatorRail::prepareRail()
{
    setRailPosition();
    setRailAngle();
    setRailIndex();
    setTransformOriginPoint(railTransformOffset);
}

void CreatorRail::rotateRail()
{
    if (railIsRotate)
        setRotation(railAngle-=22.5);
}

void CreatorRail::rotateToggle()
{
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
    case CreatorRail::RAIL_DOUBLE_FLEX:
    case CreatorRail::RAIL_STRAIGHT:
        break;
    case CreatorRail::RAIL_CURVED:
        if (railToggle == TOGGLE_NORMAL)
            railToggle = TOGGLE_REVERSE;
        else
            railToggle = TOGGLE_NORMAL;
        break;
    case CreatorRail::RAIL_LEFT_SWITCH:
    case CreatorRail::RAIL_RIGHT_SWITCH:
        switch (railToggle) {
        case CreatorRail::TOGGLE_NORMAL:
            railToggle = TOGGLE_REVERSE;
            break;
        case CreatorRail::TOGGLE_REVERSE:
            railToggle = TOGGLE_SWITCH;
            break;
        case CreatorRail::TOGGLE_SWITCH:
            railToggle = TOGGLE_NORMAL;
            break;
        }
        break;
    }
    setRailAngle();
    setRailPosition();
}

void CreatorRail::changeRailPoint()
{
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
    case CreatorRail::RAIL_DOUBLE_FLEX:
    case CreatorRail::RAIL_STRAIGHT:
    case CreatorRail::RAIL_CURVED:
        if (railPoint == POINT_NORMAL)
            railPoint = POINT_REVERSE;
        else
            railPoint = POINT_NORMAL;
        break;
    case CreatorRail::RAIL_LEFT_SWITCH:
    case CreatorRail::RAIL_RIGHT_SWITCH:
        switch (railPoint) {
        case CreatorRail::POINT_NORMAL:
            railPoint = POINT_REVERSE;
            break;
        case CreatorRail::POINT_REVERSE:
            railPoint = POINT_SWITCH;
            break;
        case CreatorRail::POINT_SWITCH:
            railPoint = POINT_NORMAL;
            break;
        }
        break;
    }
    qDebug() << railPoint;
}

void CreatorRail::setRailPosition()
{
    setPos(getTogglePoint());
}

void CreatorRail::setRailAngle()
{
    switch (railToggle) {
    case CreatorRail::TOGGLE_NORMAL:
        setRotation(railAngle);
        break;
    case CreatorRail::TOGGLE_REVERSE:
        switch (railType) {
        case CreatorRail::RAIL_FLEX:
        case CreatorRail::RAIL_DOUBLE_FLEX:
        case CreatorRail::RAIL_STRAIGHT:
            break;
        case CreatorRail::RAIL_CURVED:
            setRotation(railAngle - 157.5);
            break;
        case CreatorRail::RAIL_LEFT_SWITCH:
        case CreatorRail::RAIL_RIGHT_SWITCH:
            setRotation(railAngle - 180);
            break;
        }
        break;
    case CreatorRail::TOGGLE_SWITCH:
        switch (railType) {
        case CreatorRail::RAIL_FLEX:
        case CreatorRail::RAIL_DOUBLE_FLEX:
        case CreatorRail::RAIL_STRAIGHT:
        case CreatorRail::RAIL_CURVED:
            break;
        case CreatorRail::RAIL_LEFT_SWITCH:
            setRotation(railAngle - 157.5);
            break;
        case CreatorRail::RAIL_RIGHT_SWITCH:
            setRotation(railAngle + 157.5);
            break;
        }
        break;
    }
}

void CreatorRail::setRailIndex()
{
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
    case CreatorRail::RAIL_DOUBLE_FLEX:
    case CreatorRail::RAIL_STRAIGHT:
        setZValue(1000);
        break;
    case CreatorRail::RAIL_CURVED:
        setZValue(100);
        break;
    case CreatorRail::RAIL_LEFT_SWITCH:
    case CreatorRail::RAIL_RIGHT_SWITCH:
        setZValue(10);
        break;
    }
}
