#include "CreatorGridSettings.h"
#include "ui_creatorgridsettings.h"

CreatorGridSettings::CreatorGridSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatorGridSettings)
{
    ui->setupUi(this);
    setWindowTitle("Grid settings");
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    ui->studsPerPlateComboBox->setCurrentIndex(STUD_4);
    ui->gridSizeSpinBox->setMaximum(100000);
    ui->gridSizeSpinBox->setMinimum(0);
    ui->gridSizeSpinBox->setValue(10000);
}

CreatorGridSettings::~CreatorGridSettings()
{
    delete ui;
}

void CreatorGridSettings::on_pushButton_clicked()
{
    qint8 studs = 0;
    switch (ui->studsPerPlateComboBox->currentIndex()) {
    case CreatorGridSettings::STUD_1:
        studs = 1;
        break;
    case CreatorGridSettings::STUD_2:
        studs = 2;
        break;
    case CreatorGridSettings::STUD_4:
        studs = 4;
        break;
    case CreatorGridSettings::STUD_8:
        studs = 8;
        break;
    case CreatorGridSettings::STUD_16:
        studs = 16;
        break;
    case CreatorGridSettings::STUD_32:
        studs = 32;
        break;
    }
    emit gridSizeChanged(studs, ui->gridSizeSpinBox->value());
    hide();
}
