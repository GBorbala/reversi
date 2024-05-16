#include "graphics.hpp"
#include "Widget.hpp"
#include "Cell.hpp"
#include "Reversi.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

int main()
{
    gout.open(600,600);
    event ev;
    Reversi* reversi = new Reversi(0,0,600,600);
    reversi->draw();
    gout << refresh;
    while(gin >> ev)
    {
        reversi->event_handle(ev);
        reversi->update();
        gout<<refresh;
    }
    return 0;
}
