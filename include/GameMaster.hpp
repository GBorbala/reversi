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

protected:
    Reversi* _reversi;
    Menu* _menu;

private:
};

#endif // GAMEMASTER_HPP

