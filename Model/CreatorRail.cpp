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

QPointF CreatorRail::getNextPoint(CreatorRail *focusRail)
{
    qreal radianAngle;
    qreal positionX = 0.0;
    qreal positionY = 0.0;

    switch (railPoint) {
    case CreatorRail::POINT_NORMAL:
    case CreatorRail::POINT_SWITCH:
        radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.value( ((railToggle * TOGGLE_SIZE) + railPoint) ));
        positionX = railPosition.x() + (railPointRadius.value( ((railToggle * TOGGLE_SIZE) + railPoint) ) * qCos(radianAngle));
        positionY = railPosition.y() + (railPointRadius.value( ((railToggle * TOGGLE_SIZE) + railPoint) ) * qSin(radianAngle));
        return QPointF(positionX, positionY);
    case CreatorRail::POINT_REVERSE:
        // TUTAJ FUNKCJA BARDZIEJ ROZBUDOWANA BO MUSI BRAC POD UWAGE PROMIEN POPRZEDNIEGO ODCINKA I SWOJ KAT MINUS OFFSETY POPRZEDNIEGO ODCINKA
        return QPointF(positionX, positionY);
    }



//    switch (railPoint) {
//    case CreatorRail::POINT_NORMAL:
//        switch (railToggle) {
//        case CreatorRail::TOGGLE_NORMAL:
//            radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.at(POINT_NORMAL));
//            positionX = railPosition.x() + (railPointRadius.at(POINT_NORMAL) * qCos(radianAngle));
//            positionY = railPosition.y() + (railPointRadius.at(POINT_NORMAL) * qSin(radianAngle));
//            return QPointF(positionX, positionY);
//        case CreatorRail::TOGGLE_REVERSE:
//            switch (railType) {
//            case CreatorRail::RAIL_FLEX:
//            case CreatorRail::RAIL_DOUBLE_FLEX:
//            case CreatorRail::RAIL_STRAIGHT:
//                break;
//            case CreatorRail::RAIL_CURVED:
//            case CreatorRail::RAIL_LEFT_SWITCH:
//            case CreatorRail::RAIL_RIGHT_SWITCH:
//                radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.at(POINT_REVERSE));
//                positionX = railPosition.x() + (railPointRadius.at(POINT_REVERSE) * qCos(radianAngle));
//                positionY = railPosition.y() + (railPointRadius.at(POINT_REVERSE) * qSin(radianAngle));
//                return QPointF(positionX, positionY);
//            }
//            break;
//        case CreatorRail::TOGGLE_SWITCH:
//            switch (railType) {
//            case CreatorRail::RAIL_FLEX:
//            case CreatorRail::RAIL_DOUBLE_FLEX:
//            case CreatorRail::RAIL_STRAIGHT:
//            case CreatorRail::RAIL_CURVED:
//                break;
//            case CreatorRail::RAIL_LEFT_SWITCH:
//            case CreatorRail::RAIL_RIGHT_SWITCH:
//                radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.at(POINT_SWITCH));
//                positionX = railPosition.x() + (railPointRadius.at(POINT_SWITCH) * qCos(radianAngle));
//                positionY = railPosition.y() + (railPointRadius.at(POINT_SWITCH) * qSin(radianAngle));
//                return QPointF(positionX, positionY);
//            }
//            break;

//        }
//        break;
//    case CreatorRail::POINT_REVERSE:
//        break;
//    case CreatorRail::POINT_SWITCH:
//        break;
//    }
    //    switch (railToggle) {
    //    case CreatorRail::TOGGLE_NORMAL:
    //        radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.at(TOGGLE_NORMAL));
    //        positionX = railPosition.x() + (railPointRadius.at(TOGGLE_NORMAL) * qCos(radianAngle));
    //        positionY = railPosition.y() + (railPointRadius.at(TOGGLE_NORMAL) * qSin(radianAngle));
    //        return QPointF(positionX, positionY);
    //    case CreatorRail::TOGGLE_REVERSE:
    //        radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.at(TOGGLE_REVERSE));
    //        positionX = railPosition.x() + (railPointRadius.at(TOGGLE_REVERSE) * qCos(radianAngle));
    //        positionY = railPosition.y() + (railPointRadius.at(TOGGLE_REVERSE) * qSin(radianAngle));
    //        return QPointF(positionX, positionY);
    //    case CreatorRail::TOGGLE_SWITCH:
    //        radianAngle = qDegreesToRadians(railAngle + railPointAngleOffset.at(TOGGLE_SWITCH));
    //        positionX = railPosition.x() + (railPointRadius.at(TOGGLE_SWITCH) * qCos(radianAngle));
    //        positionY = railPosition.y() + (railPointRadius.at(TOGGLE_SWITCH) * qSin(radianAngle));
    //        return QPointF(positionX, positionY);
    //    }
}

qreal CreatorRail::getNextAngle()
{
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
    case CreatorRail::RAIL_DOUBLE_FLEX:
    case CreatorRail::RAIL_STRAIGHT:
        return railAngle;
    case CreatorRail::RAIL_CURVED:
        switch (railToggle) {
        case CreatorRail::TOGGLE_NORMAL:
            return railAngle - 22.5;
        case CreatorRail::TOGGLE_REVERSE:
            return railAngle + 22.5;
        default:
            return railAngle;
        }
    case CreatorRail::RAIL_LEFT_SWITCH:
        return railAngle;
    case CreatorRail::RAIL_RIGHT_SWITCH:
        return railAngle;
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
