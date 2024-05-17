#include "Cell.hpp"
#include "Widget.hpp"
#include "graphics.hpp"
#include <cmath>

using namespace genv;

Cell::Cell(int x, int y, int sx, int sy, char content):Widget(x,y,sx,sy),_content(content)
{
    //ctor
}

char Cell::_content_getter()
{
    return _content;
}

void Cell::_content_setter(char _new_content)
{
    _content = _new_content;
}


void Cell::draw()
{
    // Draw a black rectangle of dimensions sx by sy
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);

    // Draw a white rectangle of dimensions sx-1 by sy-1 to create a black border
    gout << move_to(_x + 1, _y + 1) << color(255, 255, 255) << box(_size_x - 1, _size_y - 1);

    int r,g,b;

    if(_content=='p')
    {
        r=255;
        g=20;
        b=147;
    }
    else if(_content == 'b')
    {
        r=0;
        g=0;
        b=0;
    }
    else if(_content == 'g')
    {
        r=200;
        g=200;
        b=200;
    }


    int center_x = _x + _size_x / 2;
    int center_y = _y + _size_y / 2;
    gout << color(r, g, b);

    int radius = _size_x / 4; // Radius of the circle

    if (_content != 'n')
    {
        // Fill the circle
        for (int y = -radius; y <= radius; ++y)
        {
            for (int x = -radius; x <= radius; ++x)
            {
                if (x * x + y * y <= radius * radius)
                {
                    gout << move_to(center_x + x, center_y + y) << dot;
                }
            }
        }
    }

}

Cell::~Cell()
{
    //dtor
}
