#include "graphics.hpp"
#include "Widget.hpp"
#include "Cell.hpp"
#include "Reversi.hpp"

using namespace genv;

int main()
{
    gout.open(600,600);
    /*gout << font("LiberationSans-Regular.ttf",20);
    gout << text("hello world");*/

    event ev;
    /*Cell* c = new Cell(20,20,75,75,'w');
    c->draw();*/

    Reversi* reversi = new Reversi(0,0,600,600);
    reversi->draw();
    gout << refresh;
    while(gin >> ev)
    {
        reversi->event_handle(ev);
        gout<<refresh;
    }
    return 0;
}
