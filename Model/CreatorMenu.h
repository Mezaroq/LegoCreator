#ifndef CREATORMENU_H
#define CREATORMENU_H

#include <QListWidgetItem>

class CreatorMenu : public QListWidgetItem
{
public:
    enum MenuType{
        RAIL_FLEX,
        RAIL_DOUBLE_FLEX,
        RAIL_STRAIGHT,
        RAIL_CURVED,
        RAIL_LEFT_SWITCH,
        RAIL_RIGHT_SWITCH,
        STATION_PASSENGER,
        STATION_FREIGHT,
        STATION_SMALL
    };

    CreatorMenu(MenuType menuType, const QString name);
    static QString getIcon(MenuType menuType);
    MenuType getMenuType();

private:
    MenuType menuType;
};

#endif // CREATORMENUMODEL_H
