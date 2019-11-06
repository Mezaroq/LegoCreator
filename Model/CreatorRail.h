#ifndef CREATORRAIL_H
#define CREATORRAIL_H

#include <Model/CreatorObject.h>
#include <QString>
#include <QtMath>
#include <QHash>

class CreatorRail : public CreatorObject
{
public:
    static const int TOGGLE_SIZE = 3;

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
        POINT_NORMAL,
        POINT_REVERSE,
        POINT_SWITCH
    };

    /*!
     * \brief CreatorRail
     * \param railType                  typ toru const
     * \param railPosition              pozycjaStartowa const
     * \param railAngle                 kąt toru zależny od poprzedniego odcinka
     * \param railPointRadius           promienie użyte do obliczania railPosition dla następnego odcinka w zależności do którego RailToggle zostanie wybrane
     * \param railPointAngleOffset      offset dodawany do railAngle w celu obliczenia następnej pozycji
     * \param railRotateRadius          promienie używane tylko do obracania odcinków w zależności od RailRotate
     * \param railRotateAngleOffset     offset dodawany do railAngle w celu obliczenia pozycji dla obrotu toru
     * \param railPositionOffset        offset dla każdej pozycji w przypadku gdy SVG nie zaczyna się w lewym górnym rogu
     * \param railIsRotate              czy torem można zmieniać pozycje w jakiej jest ułożony
     * \param railTransformOffset       offset dla każdej pozycji w przypadku gdy SVG nie zaczyna się w lewym górnym rogu, używany do rotacji
     */
    CreatorRail(RailType railType,
                QPointF railPosition,
                qreal railAngle,
                QHash<qint8, qreal> railPointRadius,
                QHash<qint8, qreal> railPointAngleOffset,
                QHash<qint8, qreal> railToggleRadius,
                QHash<qint8, qreal> railToggleAngleOffset,
                bool railIsToggle = false,
                bool railIsRotate = false,
                QPoint railPositionOffset = QPoint(0, 0),
                QPoint railTransformOffset = QPoint(0, 0));
    static QString      getResource(RailType railType);
    static qint8        getRailPointKey(RailToggle railToggle, RailPoint railPoint);
    RailType            getRailType();
    QPointF             getNextPoint(CreatorRail *focusRail = nullptr);
    qreal               getNextAngle();
    QPointF             getTogglePoint();
    void                setRailPosition();
    void                setRailAngle();
    void                setRailIndex();
    void                prepareRail();
    void                rotateRail();
    void                rotateToggle();
    void                changeRailPoint();

private:
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
    bool                railIsRotate;
    bool                railIsToggle;
};

#endif // CREATORRAIL_H
