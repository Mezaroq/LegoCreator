#include "CreatorMenu.h"

CreatorMenu::CreatorMenu(CreatorMenu::MenuType menuType, const QString name) :
    QListWidgetItem(QIcon(CreatorMenu::getIcon(menuType)), name)
{
    this->menuType = menuType;
}

QString CreatorMenu::getIcon(CreatorMenu::MenuType menuType)
{
    switch (menuType) {
    case CreatorMenu::RAIL_FLEX:
        return ":/creator/resources/icons/icon_menu_rail_flex.svg";
    case CreatorMenu::RAIL_DOUBLE_FLEX:
        return ":/creator/resources/icons/icon_menu_rail_double_flex.svg";
    case CreatorMenu::RAIL_STRAIGHT:
        return ":/creator/resources/icons/icon_menu_rail_straight.svg";
    case CreatorMenu::RAIL_CURVED:
        return ":/creator/resources/icons/icon_menu_rail_curved.svg";
    case CreatorMenu::RAIL_LEFT_SWITCH:
        return ":/creator/resources/icons/icon_menu_rail_left_switch.svg";
    case CreatorMenu::RAIL_RIGHT_SWITCH:
        return ":/creator/resources/icons/icon_menu_rail_right_switch.svg";
    case CreatorMenu::STATION_PASSENGER:
        return ":/creator/resources/icons/icon_menu_station_passenger.svg";
    case CreatorMenu::STATION_FREIGHT:
        return ":/creator/resources/icons/icon_menu_station_freight.svg";
    case CreatorMenu::STATION_SMALL:
        return ":/creator/resources/icons/icon_menu_station_small.svg";
    }
}

CreatorMenu::MenuType CreatorMenu::getMenuType()
{
    return menuType;
}
