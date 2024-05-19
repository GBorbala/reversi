#include "graphics.hpp"
#include "Widget.hpp"
#include "Cell.hpp"
#include "Reversi.hpp"
#include "GameMaster.hpp"
#include "Menu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

int main()
{
    gout.open(600,600);
    event ev;

    GameMaster* game_master = new GameMaster();

    //Menu* menu = new Menu(0, 0, 600, 600);
    //menu->start_menu(ev);
    game_master->_menu->start_menu(ev);

    while(gin >> ev)
    {
        game_master->the_game(ev);
        gout << refresh;
    }

    return 0;
}
