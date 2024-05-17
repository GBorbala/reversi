#include "Menu.hpp"
#include "Widget.hpp"
#include "Cell.hpp"
#include "graphics.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

Menu::Menu(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    // ctor
}

void Menu::show_result(Cell* cells[8][8])
{
    gout << color(255, 255, 255) << move_to(_x, _y) << box(_size_x, _size_y);

    int p_counter = 0;
    int b_counter = 0;

    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(cells[i][j]->_content_getter() == 'p')
            {
                p_counter++;
            }
            else if(cells[i][j]->_content_getter() == 'b')
            {
                b_counter++;
            }
        }
    }

    gout << color(255, 20, 147) << move_to(250, 250) << text("Pink points: ") << text(std::to_string(p_counter));
    gout << color(0, 0, 0) << move_to(250, 280) << text("Black points: ") << text(std::to_string(b_counter));
}

Menu::~Menu()
{
    // dtor
}

