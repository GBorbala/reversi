#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget
{
public:
    Widget(int x, int y, int sx, int sy);
    virtual void draw();
    virtual void event_handle(genv::event ev);
    bool mouse_is_on(int,int);
    virtual ~Widget();

protected:
    int _x;
    int _y;
    int _size_x;
    int _size_y;

private:
};

#endif // WIDGET_HPP
