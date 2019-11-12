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
    QAction *getActionOpenProject();
    QAction *getActionSaveProject();
    QAction *getActionExportAsImage();
    QAction *getActionRotateObject();
    QAction *getActionRotateToggle();
    QAction *getActionChangeConnection();
    QAction *getActionRemoveObject();
    QAction *getActionRemoveAll();

    ~MainWindow();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
