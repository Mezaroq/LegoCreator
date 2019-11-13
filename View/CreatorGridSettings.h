#ifndef CREATORGRIDSETTINGS_H
#define CREATORGRIDSETTINGS_H

#include <QDialog>

namespace Ui {
class CreatorGridSettings;
}

class CreatorGridSettings : public QDialog
{
    Q_OBJECT
public:
    enum PlateSize{
        STUD_1,
        STUD_2,
        STUD_4,
        STUD_8,
        STUD_16,
        STUD_32
    };
    explicit CreatorGridSettings(QWidget *parent = nullptr);
    ~CreatorGridSettings();

signals:
    void gridSizeChanged(qint8 plateSize, int gridSize);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreatorGridSettings *ui;
};

#endif // CREATORGRIDSETTINGS_H
