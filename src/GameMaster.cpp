#include "GameMaster.hpp"
#include "graphics.hpp"
#include "Menu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

GameMaster::GameMaster()
{
    _reversi = new Reversi(0, 0, 600, 600);
    _menu = new Menu(0,0,600,600);
}

void GameMaster::the_game(event ev)
{
    if(_menu->game_is_on_getter()==false)
    {
        _menu->start_menu( ev);
        //gout<<refresh;
    }
    else
    {
        //_reversi->draw();
        _reversi->event_handle( ev);
        gout<<refresh;
    }
}

GameMaster::~GameMaster()
{
    //ctor
}
