#include "CreatorViewModel.h"

CreatorViewModel::CreatorViewModel(CreatorScene *scene, MainWindow *mainWindow)
{
    this->scene = scene;
    this->mainWindow = mainWindow;
    viewModelSetup();
}

CreatorViewModel::~CreatorViewModel() {}

int CreatorViewModel::getPlateSize(CreatorViewModel::PlateSize gridPlateSize)
{
    switch (gridPlateSize) {
    case CreatorViewModel::STUD_1:
        return 1;
    case CreatorViewModel::STUD_2:
        return 2;
    case CreatorViewModel::STUD_4:
        return 4;
    case CreatorViewModel::STUD_8:
        return 8;
    case CreatorViewModel::STUD_16:
        return 16;
    case CreatorViewModel::STUD_32:
        return 32;
    }
    return 1;
}

CreatorObject *CreatorViewModel::getObjectByID(qint32 id)
{
    for (CreatorObject *object : objectsList) {
        if (object->getObjectID() == id) {
            return object;
        }
    }
    return nullptr;
}

void CreatorViewModel::viewModelSetup()
{
    removeAllConfirm.setText("Remove all objects?");
    removeAllConfirm.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    removeAllConfirm.setDefaultButton(QMessageBox::Cancel);
    removeAllConfirm.iconPixmap();

    gridBorder = new QGraphicsRectItem();
    scene->addItem(gridBorder);
    drawGrid(currentStuds, currentGridSize);

    gridSettings = new CreatorGridSettings();
    gridSettings->getGridSizeSpinBox()->setRange(0, 100000);
    gridSettings->getGridSizeSpinBox()->setValue(currentGridSize);
    gridSettings->getStudsPerPlateComboBox()->setCurrentIndex(STUD_4);
    connect(gridSettings, SIGNAL(gridSizeChanged(int, int)), this, SLOT(gridResized(int, int)));

    scene->setPointerState(positionPointerState);
    positionPointer = new QGraphicsSvgItem(":/creator/resources/objects/object_rail_point.svg");
    positionPointer->setZValue(POINTER_INDEX_VALUE);
    positionPointer->hide();
    positionPointer->setCacheMode(QGraphicsItem::ItemCoordinateCache);
    positionPointer->setCachingEnabled(true);
    scene->addItem(positionPointer);

    color = new QColorDialog(mainWindow);
    color->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
}

void CreatorViewModel::createRail(CreatorRail::RailType railType)
{   
    CreatorRail *newRail;
    QPointF railPosition = positionPointer->pos() - POSITION_POINTER_OFFSET;
    qreal railAngle = 0.0;
    CreatorRail::RailToggle toggle = CreatorRail::TOGGLE_NORMAL;
    QHash<qint8, qreal> railPointRadius;
    QHash<qint8, qreal> railPointAngleOffset;
    QHash<qint8, qreal> railToggleRadius;
    QHash<qint8, qreal> railToggleAngleOffset;
    CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject);

    if (focusRail) {
        if (focusRail->getToggleRailPoint().isNull())
            return;
        railPosition = focusRail->getNextRailPosition();
        railAngle = focusRail->getNextRailAngle();
        toggle = focusRail->getRailToggle();
    }
    switch (railType) {
    case CreatorRail::RAIL_FLEX:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 40);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        newRail = new CreatorRail(CreatorObject::getNextObjectID(), railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset);
        break;
    case CreatorRail::RAIL_DOUBLE_FLEX:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        newRail = new CreatorRail(CreatorObject::getNextObjectID(), railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset);
        break;
    case CreatorRail::RAIL_STRAIGHT:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 160);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        newRail = new CreatorRail(CreatorObject::getNextObjectID(), railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset);
        break;
    case CreatorRail::RAIL_CURVED:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 140.47);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 171.68);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 80);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), -11.25);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 11.25);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 90);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleRadius.insert(CreatorRail::TOGGLE_REVERSE, 174.69);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_REVERSE, 37.94);
        newRail = new CreatorRail(CreatorObject::getNextObjectID(), railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, QPoint(0, -28), QPoint(0, 28));
        if (toggle == CreatorRail::TOGGLE_REVERSE || lastRailToggle == CreatorRail::TOGGLE_REVERSE) {
            newRail->toggleRailSwitch();
            lastRailToggle = CreatorRail::TOGGLE_REVERSE;
        } else {
            lastRailToggle = CreatorRail::TOGGLE_NORMAL;
        }
        break;
    case CreatorRail::RAIL_LEFT_SWITCH:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 320);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), 336.32);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 320);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), 206.68);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), 367.02);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), 57.11);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), -22.1);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), 87.68);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), 1.32);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), -44.59);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleRadius.insert(CreatorRail::TOGGLE_REVERSE, 329.85);
        railToggleRadius.insert(CreatorRail::TOGGLE_SWITCH, 346.25);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_REVERSE, 14.04);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_SWITCH, 13.76);
        newRail = new CreatorRail(CreatorObject::getNextObjectID(), railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, QPoint(0, -127), QPoint(0, 127));
        break;
    case CreatorRail::RAIL_RIGHT_SWITCH:
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 320);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), 367.02);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 320);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), 57.11);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), 336.32);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 80);
        railPointRadius.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), 206.68);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_NORMAL, CreatorRail::POINT_SWITCH), 21.18);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_NORMAL), 0);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_REVERSE, CreatorRail::POINT_SWITCH), -112.91);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_NORMAL), -0.4);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_REVERSE), 90);
        railPointAngleOffset.insert(CreatorRail::getRailPointKey(CreatorRail::TOGGLE_SWITCH, CreatorRail::POINT_SWITCH), 69.82);
        railToggleRadius.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleRadius.insert(CreatorRail::TOGGLE_REVERSE, 329.85);
        railToggleRadius.insert(CreatorRail::TOGGLE_SWITCH, 373.84);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_NORMAL, 0);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_REVERSE, 14.04);
        railToggleAngleOffset.insert(CreatorRail::TOGGLE_SWITCH, 11.03);
        newRail = new CreatorRail(CreatorObject::getNextObjectID(), railType, railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset);
        break;
    }
    if (focusRail) {
        focusRail->setConnectedRail(focusRail->getRailPoint(), newRail);
        newRail->setConnectedRail(CreatorRail::POINT_REVERSE, focusRail);
        focusRail->toggleRailPoint();
    }
    objectCreated(newRail);
}

void CreatorViewModel::createStation(CreatorStation::StationType stationType)
{
    CreatorStation *station;
    QPointF stationPosition = positionPointer->pos() - POSITION_POINTER_OFFSET;
    qreal stationAngle = 0.0;

    switch (stationType) {
    case CreatorStation::STATION_PASSENGER:
        station = new CreatorStation(CreatorObject::getNextObjectID(), stationType, stationPosition, stationAngle, QPoint(0, -40), QPoint(0, 40));
        break;
    case CreatorStation::STATION_FREIGHT:
        station = new CreatorStation(CreatorObject::getNextObjectID(), stationType, stationPosition, stationAngle, QPoint(-10, -10), QPoint(10, 10));
        break;
    case CreatorStation::STATION_SMALL:
        station = new CreatorStation(CreatorObject::getNextObjectID(), stationType, stationPosition, stationAngle, QPoint(0, -20), QPoint(0, 20));
        break;
    }
    objectCreated(station);
}

void CreatorViewModel::drawGrid(int studsPerPlate, int gridSize, bool resize, qreal gridLineSize)
{
    currentStuds = studsPerPlate;
    currentGridSize = gridSize;

    if (resize) {
        for (QGraphicsLineItem *line : gridLines) {
            delete line;
        }
        gridLines.clear();
    }
    const int STUD_SIZE = 10;
    const int PLATE_SIZE = STUD_SIZE * studsPerPlate;
    const int AMOUNT_OF_PLATES = (gridSize / 2) / PLATE_SIZE;
    const int MIN_GRID_POSITION = -(PLATE_SIZE * AMOUNT_OF_PLATES);
    const int MAX_GRID_POSITION = PLATE_SIZE * AMOUNT_OF_PLATES;

    gridBorder->setRect(MIN_GRID_POSITION, MIN_GRID_POSITION, MAX_GRID_POSITION*2, MAX_GRID_POSITION*2);
    if (gridIsHidden)
        gridBorder->hide();

    for (int plate_position = MIN_GRID_POSITION; plate_position <= MAX_GRID_POSITION; plate_position+=PLATE_SIZE) {
        gridLines.append(scene->addLine(QLineF(plate_position, MIN_GRID_POSITION, plate_position, MAX_GRID_POSITION), QPen(Qt::darkGray, gridLineSize)));
        if (gridIsHidden)
            gridLines.last()->hide();
        gridLines.append(scene->addLine(QLineF(MIN_GRID_POSITION, plate_position, MAX_GRID_POSITION, plate_position), QPen(Qt::darkGray, gridLineSize)));
        if (gridIsHidden)
            gridLines.last()->hide();
    }
}

void CreatorViewModel::viewModelUpdate(CreatorViewModel::UpdateReason reason, CreatorObject *object)
{
    CreatorRail *rail = dynamic_cast<CreatorRail*>(object);
    CreatorStation *station = dynamic_cast<CreatorStation*>(object);

    switch (reason) {
    case CreatorViewModel::OBJECT_MOVED:
        switch (object->getObjectType()) {
        case CreatorObject::OBJECT_RAIL:
            break;
        case CreatorObject::OBJECT_STATION:
            positionPointer->setPos(station->getStationPointPosition() + POSITION_POINTER_OFFSET);
            break;
        }
        break;
    case CreatorViewModel::OBJECT_GET_FOCUS:
        switch (object->getObjectType()) {
        case CreatorObject::OBJECT_RAIL:
            if (!rail->getToggleRailPoint().isNull()) {
                positionPointer->setPos(rail->getToggleRailPoint());
                positionPointer->show();
                positionPointerState = CreatorScene::POINTER_DISABLED;
            } else {
                positionPointer->hide();
                positionPointerState = CreatorScene::POINTER_DISABLED;
            }
            break;
        case CreatorObject::OBJECT_STATION:
            positionPointer->setPos(station->getStationPointPosition() + POSITION_POINTER_OFFSET);
            positionPointer->show();
            positionPointerState = CreatorScene::POINTER_DISABLED;
            break;
        }
        break;
    case CreatorViewModel::OBJECT_LOST_FOCUS:
        positionPointer->hide();
        positionPointerState = CreatorScene::POINTER_DISABLED;
        break;
    case CreatorViewModel::POINTER_CHANGED:
        switch (object->getObjectType()) {
        case CreatorObject::OBJECT_RAIL:
            positionPointer->setPos(rail->getToggleRailPoint());
            break;
        case CreatorObject::OBJECT_STATION:
            positionPointer->setPos(station->getStationPointPosition());
            positionPointer->show();
            break;
        }
        break;
    }
    scene->update();
}

void CreatorViewModel::menuItemClicked(QListWidgetItem *item)
{
    switch (static_cast<CreatorMenu*>(item)->getMenuType()) {
    case CreatorMenu::RAIL_FLEX:
        if (positionPointerState == CreatorScene::POINTER_SET || dynamic_cast<CreatorRail*>(focusObject))
            createRail(CreatorRail::RAIL_FLEX);
        break;
    case CreatorMenu::RAIL_DOUBLE_FLEX:
        if (positionPointerState == CreatorScene::POINTER_SET || dynamic_cast<CreatorRail*>(focusObject))
            createRail(CreatorRail::RAIL_DOUBLE_FLEX);
        break;
    case CreatorMenu::RAIL_STRAIGHT:
        if (positionPointerState == CreatorScene::POINTER_SET || dynamic_cast<CreatorRail*>(focusObject))
            createRail(CreatorRail::RAIL_STRAIGHT);
        break;
    case CreatorMenu::RAIL_CURVED:
        if (positionPointerState == CreatorScene::POINTER_SET || dynamic_cast<CreatorRail*>(focusObject))
            createRail(CreatorRail::RAIL_CURVED);
        break;
    case CreatorMenu::RAIL_LEFT_SWITCH:
        if (positionPointerState == CreatorScene::POINTER_SET || dynamic_cast<CreatorRail*>(focusObject))
            createRail(CreatorRail::RAIL_LEFT_SWITCH);
        break;
    case CreatorMenu::RAIL_RIGHT_SWITCH:
        if (positionPointerState == CreatorScene::POINTER_SET || dynamic_cast<CreatorRail*>(focusObject))
            createRail(CreatorRail::RAIL_RIGHT_SWITCH);
        break;
    case CreatorMenu::STATION_PASSENGER:
        if (positionPointerState == CreatorScene::POINTER_SET)
            createStation(CreatorStation::STATION_PASSENGER);
        break;
    case CreatorMenu::STATION_FREIGHT:
        if (positionPointerState == CreatorScene::POINTER_SET)
            createStation(CreatorStation::STATION_FREIGHT);
        break;
    case CreatorMenu::STATION_SMALL:
        if (positionPointerState == CreatorScene::POINTER_SET)
            createStation(CreatorStation::STATION_SMALL);
        break;
    }
}

void CreatorViewModel::focusObjectChanged(CreatorObject *newFocusObject)
{
    if (focusObject) {
        focusObject->graphicsEffect()->setEnabled(false);
        viewModelUpdate(OBJECT_LOST_FOCUS);
    }

    if (newFocusObject) {
        newFocusObject->graphicsEffect()->setEnabled(true);
        viewModelUpdate(OBJECT_GET_FOCUS, newFocusObject);
    } else {
        viewModelUpdate(OBJECT_LOST_FOCUS);
    }
    focusObject = newFocusObject;
    scene->setFocusObject(newFocusObject);
}

void CreatorViewModel::objectCreated(CreatorObject *newObject)
{
    QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
    effect->setColor(QColor(46, 83, 97));

    newObject->setGraphicsEffect(effect);
    newObject->setFlag(QGraphicsItem::ItemIsFocusable);

    objectsList.append(newObject);
    scene->addItem(newObject);
    scene->setFocusItem(newObject);
    focusObjectChanged(newObject);
}

void CreatorViewModel::pointerChanged(bool isSet, bool positionChanged, QPointF position)
{
    if (focusObject)
        focusObjectChanged(nullptr);
    switch (positionPointerState) {
    case CreatorScene::POINTER_DISABLED:
    case CreatorScene::POINTER_SET:
        positionPointerState = CreatorScene::POINTER_ENABLED;
        scene->setPointerState(positionPointerState);
        mainWindow->getActionChangePointer()->setIcon(QIcon(":/creator/resources/icons/icon_bar_pointer_enabled.svg"));
        positionPointer->show();
//        positionPointer->setPos(QPoint(0, 0) + POSITION_POINTER_OFFSET); //probably this should be disabled
        scene->update();
        break;
    case CreatorScene::POINTER_ENABLED:
        if (positionChanged) {
            positionPointer->setPos(position + POSITION_POINTER_OFFSET);
            scene->update();
        } else if (isSet) {
            positionPointerState = CreatorScene::POINTER_SET;
            scene->setPointerState(positionPointerState);
            mainWindow->getActionChangePointer()->setIcon(QIcon(":/creator/resources/icons/icon_bar_pointer_disabled.svg"));
        } else {
            positionPointerState = CreatorScene::POINTER_DISABLED;
            scene->setPointerState(positionPointerState);
            mainWindow->getActionChangePointer()->setIcon(QIcon(":/creator/resources/icons/icon_bar_pointer_disabled.svg"));
            viewModelUpdate(OBJECT_LOST_FOCUS);
        }
        break;
    }
}

void CreatorViewModel::pointerSettingsTriggered()
{
    bool settingsChanged;

    QStringList settings;
    settings.append("1 stud");
    settings.append("2 studs");
    settings.append("4 studs");
    settings.append("8 studs");
    settings.append("16 studs");
    settings.append("32 studs");

    QString item = QInputDialog::getItem(mainWindow, tr("Pointer settings"), tr("Studs:"), settings, 0, false, &settingsChanged, Qt::WindowType::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);

    if (settingsChanged) {
        scene->setPointerMoveVector(getPlateSize(PlateSize(settings.indexOf(item))));
    }
}

void CreatorViewModel::focusObjectMoved(QPointF newPosition)
{
    switch (focusObject->getObjectType()) {
    case CreatorObject::OBJECT_STATION:
    {
        CreatorStation *station = static_cast<CreatorStation*>(focusObject);
        station->moveStation(newPosition);
        viewModelUpdate(OBJECT_MOVED, station);
        break;
    }
    default:
        break;
    }
}

void CreatorViewModel::openProjectTriggered()
{
    QString fileName = QFileDialog::getOpenFileName(mainWindow, "Open Project", QCoreApplication::applicationDirPath(), "Lego Creator Project (*.lcp)");
    if (!fileName.isNull()) {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        qint8 objectType;
        int nextObjectID;
        in >> nextObjectID;
        CreatorObject::getNextObjectID(nextObjectID);
        removeAllTriggered(true);
        QHash<CreatorRail*, QHash<qint8, qint32>> connectedRails;

        while (!in.atEnd()) {
            in >> objectType;
            switch (CreatorObject::ObjectType(objectType)) {
            case CreatorObject::OBJECT_RAIL:
            {
                qint32 objectID;
                qint8 railType;
                QPointF railPosition;
                qreal railAngle;
                QHash<qint8, qreal> railPointRadius;
                QHash<qint8, qreal> railPointAngleOffset;
                QHash<qint8, qreal> railToggleRadius;
                QHash<qint8, qreal> railToggleAngleOffset;
                QPoint railPositionOffset;
                QPoint railTransformOffset;
                qint8 railToggle;
                qint8 railPoint;
                QHash<qint8, qint32> connectedRailsByID;
                in >> objectID;
                in >> railType;
                in >> railPosition;
                in >> railAngle;
                in >> railPointRadius;
                in >> railPointAngleOffset;
                in >> railToggleRadius;
                in >> railToggleAngleOffset;
                in >> railPositionOffset;
                in >> railTransformOffset;
                in >> railToggle;
                in >> railPoint;
                in >> connectedRailsByID;
                CreatorRail *rail = new CreatorRail(objectID, CreatorRail::RailType(railType), railPosition, railAngle, railPointRadius, railPointAngleOffset, railToggleRadius, railToggleAngleOffset, railPositionOffset, railTransformOffset);
                connectedRails.insert(rail, connectedRailsByID);
                rail->setRailToggle(CreatorRail::RailToggle(railToggle));
                rail->setRailPoint(CreatorRail::RailPoint(railPoint));
                objectCreated(rail);
                break;
            }
            case CreatorObject::OBJECT_STATION:
            {
                qint32 objectID;
                qint8 stationType;
                qreal stationAngle;
                QPointF stationPosition;
                QPoint stationPositionOffset;
                QPoint stationTransformOffset;
                in >> objectID;
                in >> stationType;
                in >> stationPosition;
                in >> stationAngle;
                in >> stationPositionOffset;
                in >> stationTransformOffset;
                CreatorStation *station = new CreatorStation(objectID, CreatorStation::StationType(stationType), stationPosition, stationAngle, stationPositionOffset, stationTransformOffset);
                objectCreated(station);
                break;
            }
            }
        }
        if (!connectedRails.isEmpty()) {
            QHashIterator<CreatorRail*, QHash<qint8, qint32>> railList(connectedRails);
            while (railList.hasNext()) {
                railList.next();
                QHashIterator<qint8, qint32> railConnectedRails(railList.value());
                while (railConnectedRails.hasNext()) {
                    railConnectedRails.next();
                    railList.key()->setConnectedRail(CreatorRail::RailPoint(railConnectedRails.key()), static_cast<CreatorRail*>(getObjectByID(railConnectedRails.value()))); //tutaj jest problem lub w getObjectByID
                }
            }
        }
    }
}

void CreatorViewModel::saveProjectTriggered()
{
    QString fileName = QFileDialog::getSaveFileName(mainWindow, "Save Project", QCoreApplication::applicationDirPath(), "Lego Creator Project (*.lcp)");
    if (!fileName.isNull()) {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);
        out << CreatorObject::getNextObjectID();

        for (CreatorObject *object : objectsList) {
            switch (object->getObjectType()) {
            case CreatorObject::OBJECT_RAIL:
            {
                CreatorRail *rail = static_cast<CreatorRail*>(object);
                out << qint8(object->getObjectType());
                out << qint32(object->getObjectID());
                out << qint8(rail->getRailType());
                out << QPointF(rail->getRailPosition());
                out << qreal(rail->getRailAngle());
                out << QHash<qint8, qreal>(rail->getRailPointRadius());
                out << QHash<qint8, qreal>(rail->getRailPointAngleOffset());
                out << QHash<qint8, qreal>(rail->getRailToggleRadius());
                out << QHash<qint8, qreal>(rail->getRailToggleAngleOffset());
                out << QPoint(rail->getRailPositionOffset());
                out << QPoint(rail->getRailTransformOffset());
                out << qint8(rail->getRailToggle());
                out << qint8(rail->getRailPoint());
                out << QHash<qint8, qint32>(rail->getConnectedRailsByID());
                break;
            }
            case CreatorObject::OBJECT_STATION:
            {
                CreatorStation *station = static_cast<CreatorStation*>(object);
                out << qint8(object->getObjectType());
                out << qint32(object->getObjectID());
                out << qint8(station->getStationType());
                out << QPointF(station->getStationPosition());
                out << qreal(station->getStationAngle());
                out << QPoint(station->getStationPositionOffset());
                out << QPoint(station->getStationTransformOffset());
                break;
            }
            }
        }
    }
}

void CreatorViewModel::exportAsImageTriggered()
{
    QString fileName = QFileDialog::getSaveFileName(mainWindow, "Save Image", QCoreApplication::applicationDirPath(), "PNG (*.png);;JPEG (*.JPEG);;BMP Files (*.bmp);;SVG (*.svg)" );
    if (!fileName.isNull())
    {
        focusObjectChanged(nullptr);
        for (QGraphicsLineItem *line : gridLines) {
            delete line;
        }
        gridLines.clear();
        scene->removeItem(gridBorder);

        scene->setSceneRect(scene->itemsBoundingRect());
        QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
        image.fill(Qt::transparent);

        QPainter painter(&image);
        scene->render(&painter);
        image.save(fileName);
        scene->setSceneRect(QRect());
        mainWindow->getGraphicsView()->centerOn(scene->itemsBoundingRect().center());

        scene->addItem(gridBorder);
        drawGrid(currentStuds, currentGridSize);
    }
}

void CreatorViewModel::rotateObjectTriggered()
{
    if (focusObject) {
        switch (focusObject->getObjectType()) {
        case CreatorObject::OBJECT_RAIL: {
            CreatorRail *focusRail = static_cast<CreatorRail*>(focusObject);
            if (focusRail->getRailToggle() == CreatorRail::TOGGLE_NORMAL) {
                focusRail->toggleRailAngle();
                viewModelUpdate(POINTER_CHANGED, focusObject);
            }
            break;
        }
        case CreatorObject::OBJECT_STATION:
        {
            CreatorStation *focusStation = static_cast<CreatorStation*>(focusObject);
            focusStation->toggleStationAngle();
            break;
        }
        }
    }
}

void CreatorViewModel::rotateToggleTriggered()
{
    if (CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject)) {
        focusRail->toggleRailSwitch();
        if (focusRail->getRailType() == CreatorRail::RAIL_CURVED)
            lastRailToggle = focusRail->getRailToggle();
        viewModelUpdate(POINTER_CHANGED, focusObject);
    }
}

void CreatorViewModel::changeConnectionTriggered()
{
    if (CreatorRail* focusRail = dynamic_cast<CreatorRail*>(focusObject)) {
        focusRail->toggleRailPoint();
        viewModelUpdate(POINTER_CHANGED, focusObject);
    }
}

void CreatorViewModel::removeObjectTriggered()
{
    if (focusObject) {
        switch (focusObject->getObjectType()) {
        case CreatorObject::OBJECT_RAIL:
        {
            CreatorRail *focusRail = static_cast<CreatorRail*>(focusObject);
            for (CreatorRail* rail : focusRail->getConnectedRails()) {
                rail->removeConnectedRail(focusRail);
                rail->toggleRailPoint();
            }
            CreatorRail *newFocusRail = focusRail->getConnectedRail();
            focusObject = nullptr;
            objectsList.removeOne(focusRail);
            delete focusRail;
            if (newFocusRail)
                newFocusRail->toggleRailPoint();
            focusObjectChanged(newFocusRail);
            break;
        }
        case CreatorObject::OBJECT_STATION:
            objectsList.removeOne(focusObject);
            delete focusObject;
            focusObject = nullptr;
            focusObjectChanged(nullptr);
            break;
        }
    }
}

void CreatorViewModel::removeAllTriggered(bool fileOpen)
{
    if (!objectsList.isEmpty()) {
        int confirm;
        if (!fileOpen)
            confirm = removeAllConfirm.exec();
        else
            confirm = QMessageBox::Ok;

        if (confirm == QMessageBox::Ok) {
            focusObject = nullptr;
            for (CreatorObject *object : objectsList) {
                objectsList.removeOne(object);
                delete object;
            }
            viewModelUpdate(OBJECT_LOST_FOCUS);
        }
    }
}

void CreatorViewModel::gridSettingsTriggered()
{
    gridSettings->show();
}

void CreatorViewModel::gridToggled(bool checked)
{
    gridIsHidden = checked;
    if (checked) {
        for (QGraphicsLineItem *line : gridLines) {
            line->hide();
            gridBorder->hide();
        }
    } else {
        for (QGraphicsLineItem *line : gridLines) {
            line->show();
            gridBorder->show();
        }
    }
}

void CreatorViewModel::gridResized(int gridPlateSize, int gridSize)
{
    drawGrid(getPlateSize(PlateSize(gridPlateSize)), gridSize, true);
}

void CreatorViewModel::backgroudColorChanged()
{
    bool colorSelected = color->exec();
    if (colorSelected)
        scene->setBackgroundBrush(color->selectedColor());
}
