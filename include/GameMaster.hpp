#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "Widget.hpp"
#include "Reversi.hpp"
#include "Menu.hpp"

class GameMaster
{
public:
    GameMaster();
    virtual ~GameMaster();
    void the_game(event);
    Menu* _menu;

protected:
    Reversi* _reversi;


private:
};

#endif // GAMEMASTER_HPP

