#ifndef CREATORGRIDSETTINGS_H
#define CREATORGRIDSETTINGS_H

#include <QDialog>
#include <QComboBox>
#include <QSpinBox>

namespace Ui {
class CreatorGridSettings;
}

class CreatorGridSettings : public QDialog
{
    Q_OBJECT
public:
    explicit CreatorGridSettings(QWidget *parent = nullptr);
    ~CreatorGridSettings();
    QComboBox* getStudsPerPlateComboBox();
    QSpinBox* getGridSizeSpinBox();

signals:
    void gridSizeChanged(int plateSize, int gridSize);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreatorGridSettings *ui;
};

#endif // CREATORGRIDSETTINGS_H
