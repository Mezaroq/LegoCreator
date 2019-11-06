#include <View/MainWindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(100, 100));
}

CreatorView* MainWindow::getGraphicsView()
{
    return ui->graphicsView;
}

QListWidget* MainWindow::getListWidget()
{
    return ui->listWidget;
}

QAction *MainWindow::getActionOpenProject()
{
    return ui->actionOpen_project;
}

QAction *MainWindow::getActionSaveProject()
{
    return ui->actionSave_project;
}

QAction *MainWindow::getActionExportAsImage()
{
    return ui->actionExport_as_image;
}

QAction *MainWindow::getActionRotateObject()
{
    return ui->actionRotate_object;
}

QAction *MainWindow::getActionRotateToggle()
{
    return ui->actionRotate_toggle;
}

QAction *MainWindow::getActionChangeConnection()
{
    return ui->actionChange_connection;
}

QAction *MainWindow::getActionRemoveObject()
{
    return ui->actionRemove_object;
}

QAction *MainWindow::getActionRemoveAll()
{
    return ui->actionRemove_all;
}

MainWindow::~MainWindow()
{
    delete ui;
}
