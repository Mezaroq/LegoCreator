#include <View/MainWindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(100, 100));

//    CRailModel *model = new CRailModel(CRailModel::RAIL_STRAIGHT, QPointF(0, 0), 0, 160);
//    model->getItem()->setFlag(QGraphicsItem::ItemIsFocusable);
//    scene->addItem(model->getItem());

//    CRailModel *model = new CRailModel(CRailModel::RAIL_CURVED, QPointF(160, 0), 0, 160);
//    model->getSceneSvgItem()->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
//    scene->addItem(model->getSceneSvgItem());


//    model = new CRailModel(CRailModel::RAIL_DOUBLE_FLEX, QPointF(-80, 0), 0, 160);
//    model->getItem()->setFlag(QGraphicsItem::ItemIsFocusable);
//    scene->addItem(model->getItem());
//    qDebug() << svg->getModel()->getType();
//    qDebug() << static_cast<CRailModel*>(svg->getModel())->getRailType();


//    ui->graphicsView->setAcceptDrops(true);


//    QImage image = QImage(":/lc/resources/rails/straight_rail.svg");
//    qDebug() << image.pixelColor(0,0);

//    QList<QGraphicsSvgItem*> *graphicsList = new QList<QGraphicsSvgItem*>();
//    QGraphicsSvgItem* curved = new QGraphicsSvgItem(":/lc/resources/rails/curved_rail_test.svg");

//    curved->boundingRect().setTopLeft(QPointF(0,30));
//    curved->setPos(160, 0);
//    curved->setTransformOriginPoint(0, 30);
//    curved->setRotation(-180+22.5);
//    curved->setPos(455.641,-122.459);
//    curved->setPos(405.893,-112.563);
//    curved->moveBy(curved->transformOriginPoint().rx(), -curved->transformOriginPoint().ry());
//    curved->moveBy(curved->transformOriginPoint().rx(), +curved->transformOriginPoint().ry());
//    curved->setTransformOriginPoint(0, 0);
//    graphicsList->append(curved);
//    graphicsList->append(new QGraphicsSvgItem(":/lc/resources/rails/straight_rail.svg"));
//    graphicsList->append(new QGraphicsSvgItem(":/lc/resources/rails/double_flex_rail.svg"));
//    graphicsList->append(new QGraphicsSvgItem(":/lc/resources/rails/flex_rail.svg"));

//    for(QGraphicsSvgItem* item : *graphicsList) {
//        item->setFlags(QGraphicsItem::ItemIsFocusable);
//        item->setFlag(QGraphicsItem::ItemIsSelectable);
//        item->setZValue(2);
//        scene->addItem(item);
//    }
//    curved->setZValue(1);
//    QGraphicsSvgItem* test = new QGraphicsSvgItem(":/lc/resources/rails/left_switch_rail.svg");

//    test->setTransformOriginPoint(0, 130);
//    test->setRotation(-22.5);
//    test->setPos(160, 0);
//    test->moveBy(test->transformOriginPoint().rx(), -test->transformOriginPoint().ry());
//    test->setFlag(QGraphicsItem::ItemIsFocusable);
//    test->setFlag(QGraphicsItem::ItemIsSelectable);
//    scene->addItem(test);

//    /*!
//     * \brief listWidget
//     */
//    QListWidget* listWidget = ui->listWidget;

//    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(test(QListWidgetItem*)));

//    listWidget->setDragEnabled(true);
//    listWidget->setDragDropMode(QAbstractItemView::DragOnly);
//    listWidget->setIconSize(QSize(100, 100));

//    QList<QListWidgetItem*> *menuList = new QList<QListWidgetItem*>();
//    menuList->append(new QListWidgetItem(QIcon(":/lc/resources/icons/straight_rail_icon.svg"), "Straight\nRail"));
//    menuList->append(new QListWidgetItem(QIcon(":/lc/resources/icons/double_flex_rail_icon.svg"), "Double Flex"));
//    menuList->append(new QListWidgetItem(QIcon(":/lc/resources/icons/flex_rail_icon.svg"), "Flex"));
//    menuList->append(new QListWidgetItem(QIcon(":/lc/resources/icons/curved_rail_icon.svg"), "Curved"));
//    menuList->append(new QListWidgetItem(QIcon(":/lc/resources/icons/left_switch_rail_icon.svg"), "Left Switch"));
//    menuList->append(new QListWidgetItem(QIcon(":/lc/resources/icons/right_switch_rail_icon.svg"), "Right Switch"));

//    for(QListWidgetItem* item : *menuList) {
//        listWidget->addItem(item);
//            item->setHidden(true);
//    }

//    ui->graphicsView->setBackgroundBrush(QBrush(QColor(Qt::green)));
//    ui->listWidget->setItemAlignment(Qt::AlignCenter);
//    ui->listWidget->setFlow(QListView::TopToBottom);
//    ui->listWidget->setViewMode(QListView::IconMode);
//    ui->listWidget->setMovement(QListView::Static);
//    ui->listWidget->setSpacing(25);
//    ui->listWidget->setFixedWidth(100);
//      ui->listWidget->setIconSize(QSize(50, 50));

//    lwi->setSizeHint(QSize(50, 50));
//    lwi->setTextAlignment(Qt::AlignCenter);
//    lwi =  new QListWidgetItem(QIcon(":/images/logo.svg"), nullptr);
//    lwi->setSizeHint(QSize(50, 50));
//    lwi->setTextAlignment(Qt::AlignCenter);
//    ui->listWidget->addItem(lwi);
//    lwi =  new QListWidgetItem(QIcon(":/images/logo.svg"), nullptr);
//    lwi->setSizeHint(QSize(50, 50));
//    lwi->setTextAlignment(Qt::AlignCenter);
//    ui->listWidget->addItem(lwi);
//    lwi =  new QListWidgetItem(QIcon(":/images/logo.svg"), nullptr);
//    lwi->setSizeHint(QSize(50, 50));
//    lwi->setTextAlignment(Qt::AlignCenter);
//    ui->listWidget->addItem(lwi);
//    lwi->setSizeHint(QSize(300, 300));
//    ui->listWidget->setStyleSheet(
//      "QListWidget::item {"
//         "text-align: center;"
//         "border-style: solid;"
//         "border-width:1px;"
//         "border-color:black;"
//         "background-color: green;"
//      "}"
//      "QListWidget::item:selected {"
//         "background-color: red;"
    //      "}");
}

CreatorView* MainWindow::getGraphicsView()
{
    return ui->graphicsView;
}

QListWidget* MainWindow::getListWidget()
{
    return ui->listWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}
