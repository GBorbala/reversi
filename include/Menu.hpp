#ifndef MENU_HPP
#define MENU_HPP

#include "Cell.hpp"

using namespace genv;

class Menu: public Widget {

public:
    Menu(int x, int y, int sx, int sy);
    ~Menu();

    void show_result(Cell* cells[8][8]);
    void start_menu( event);
    bool game_is_on_getter();

protected:


private:
    bool game_is_on;
};

#endif
