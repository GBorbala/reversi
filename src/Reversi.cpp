#include "Reversi.hpp"
#include "Cell.hpp"
#include "Widget.hpp"
#include "graphics.hpp"

using namespace genv;

Reversi::Reversi(int x, int y, int sx, int sy):Widget(x,y,sx,sy)
{
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            _cells[i][j] = new Cell(x+j * 75, y + i * 75, 75, 75, 'n');
        }
    }
}

void Reversi::draw()
{
    _cells[3][3]->_content_setter('p');
    _cells[4][4]->_content_setter('p');
    _cells[4][3]->_content_setter('b');
    _cells[3][4]->_content_setter('b');

    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            _cells[i][j]->draw();

        }
    }
}

void Reversi::update()
{

    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            _cells[i][j] -> draw();
        }
    }
}

void Reversi::event_handle(event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                if(_cells[i][j]->mouse_is_on(ev.pos_x, ev.pos_y) && _cells[i][j]->_content_getter()=='n')
                {
                    _cells[i][j]->_content_setter('p');
                    this->update();

                }
            }
        }
    }



}

Reversi::~Reversi()
{
    //dtor
}
