#ifndef MENU_HPP
#define MENU_HPP

#include "Cell.hpp"


class Menu {
    int _x;
    int _y;
    int _size_x;
    int _size_y;

public:
    Menu(int x, int y, int sx, int sy);
    ~Menu();

    void show_result(Cell* cells[8][8]);
};

#endif
