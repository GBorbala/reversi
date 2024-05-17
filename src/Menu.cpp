#include "Menu.hpp"
#include "Widget.hpp"
#include "Cell.hpp"
#include "graphics.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

Menu::Menu(int x, int y, int sx, int sy) :Widget(x,y,sx,sy),game_is_on(false)
{
    // ctor
}

bool Menu::game_is_on_getter()
{
    return game_is_on;
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

void Menu::start_menu( event ev)
{
    gout << color(255, 255, 255) << move_to(_x, _y) << box(_size_x, _size_y);

    gout << color(0, 0, 0) << move_to(50, 200) << text("Welcome to Reversi! Would you like to start the game? ");
    gout << color(0, 0, 0)<< move_to(250, 250) << box(100,50);
    gout << color(255, 255, 255)<< move_to(252, 252) << box(96,46);
    gout << color(0, 0, 0)<< move_to(260, 270) << text("Start");
    gout<<refresh;

    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        if(ev.pos_x>250 && ev.pos_x<350 && ev.pos_y>250 && ev.pos_y<300)
        {
            game_is_on=true;
        }
    }


}


Menu::~Menu()
{
    // dtor
}

