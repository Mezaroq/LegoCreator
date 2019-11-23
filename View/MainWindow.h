#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    CreatorView* getGraphicsView();
    QListWidget* getListWidget();
    QAction* getActionOpenProject();
    QAction* getActionSaveProject();
    QAction* getActionExportAsImage();
    QAction* getActionRotateObject();
    QAction* getActionToggleObject();
    QAction* getActionSwitchPoint();
    QAction* getActionRemoveObject();
    QAction* getActionRemoveAllObjects();
    QAction* getActionGridSettings();
    QAction* getActionToggleGrid();
    QAction* getActionChangePointer();
    QAction* getActionPointerSettings();
    QAction* getActionBackgroudColor();

    ~MainWindow();
private slots:
    void on_actionFullscreen_mode_toggled(bool arg1);
    void on_actionToggle_grid_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
