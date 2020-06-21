//
// Created by alexa on 6/18/2020.
//

#ifndef METRICS_INTELLIJMENU_H
#define METRICS_INTELLIJMENU_H

#include <iostream>

/**
 *  меню с выбором режима работы (добавить запись, просмотр всех, поиск с подменю поиска по каждому атрибуту и выход).
 *  При этом после выполнения действия происходит возврат в меню
 */
class IntellijMenu {
public:
    int firstScreen();
    int addRecord();
    int seeAll();
    int searchScreen();
    int nameSearch();
    int colorSearch();
    int letterSearch();
    int third();
    int fourth();
    int out();
};

#endif //METRICS_INTELLIJMENU_H
