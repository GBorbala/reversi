#include "GameMaster.hpp"
#include "graphics.hpp"
#include "Menu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

GameMaster::GameMaster()
{

    _menu = new Menu(0,0,600,600);
    _reversi = new Reversi(0, 0, 600, 600,_menu);
}

void GameMaster::the_game(event ev)
{
    if(_menu->game_is_on_getter()==false && _menu->retry_getter()==false)
    {
        _menu->start_menu( ev);
        gout<<refresh;
    }
    else if(_menu->game_is_on_getter()==true  && _menu->retry_getter()==false)
    {
        _reversi->event_handle( ev);
        gout<<refresh;
    }
    else if(_menu->retry_getter()==true)
    {
        _reversi->draw();
        _menu->retry_setter(false);
        _menu->game_is_on_setter(true);
    }
}

GameMaster::~GameMaster()
{
    //ctor
}
