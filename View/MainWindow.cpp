#include <View/MainWindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Lego Creator");
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

QAction *MainWindow::getActionToggleObject()
{
    return ui->actionToggle_object;
}

QAction *MainWindow::getActionSwitchPoint()
{
    return ui->actionSwitch_point;
}

QAction *MainWindow::getActionRemoveObject()
{
    return ui->actionRemove_object;
}

QAction *MainWindow::getActionRemoveAllObjects()
{
    return ui->actionRemove_all_objects;
}

QAction *MainWindow::getActionGridSettings()
{
    return ui->actionGrid_settings;
}

QAction *MainWindow::getActionToggleGrid()
{
    return ui->actionToggle_grid;
}

QAction *MainWindow::getActionChangePointer()
{
    return ui->actionChange_pointer;
}

QAction *MainWindow::getActionPointerSettings()
{
    return ui->actionPointer_settings;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFullscreen_mode_toggled(bool arg1)
{
    if (arg1) {
        showFullScreen();
        ui->actionFullscreen_mode->setIcon(QIcon(":/creator/resources/icons/icon_bar_fullscreen_on.svg"));
    } else{
        showMaximized();
        ui->actionFullscreen_mode->setIcon(QIcon(":/creator/resources/icons/icon_bar_fullscreen_off.svg"));
    }
}

void MainWindow::on_actionToggle_grid_toggled(bool arg1)
{
    if (arg1)
        ui->actionToggle_grid->setIcon(QIcon(":/creator/resources/icons/icon_bar_grid_hide.svg"));
    else
        ui->actionToggle_grid->setIcon(QIcon(":/creator/resources/icons/icon_bar_grid_show.svg"));
}
