#include "CreatorGridSettings.h"
#include "ui_creatorgridsettings.h"

CreatorGridSettings::CreatorGridSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatorGridSettings)
{
    ui->setupUi(this);
    setWindowTitle("Grid settings");
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
}

CreatorGridSettings::~CreatorGridSettings()
{
    delete ui;
}

QSpinBox *CreatorGridSettings::getGridSizeSpinBox()
{
    return ui->gridSizeSpinBox;
}

QComboBox *CreatorGridSettings::getStudsPerPlateComboBox()
{
    return ui->studsPerPlateComboBox;
}

void CreatorGridSettings::on_pushButton_clicked()
{
    emit gridSizeChanged(ui->studsPerPlateComboBox->currentIndex(), ui->gridSizeSpinBox->value());
    hide();
}
