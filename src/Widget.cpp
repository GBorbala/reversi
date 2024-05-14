#include "Widget.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int x, int y, int sx, int sy): _x(x), _y(y), _size_x(sx), _size_y(sy)
{

}

void Widget::draw()
{

}

void Widget::event_handle(event ev)
{

}

bool Widget::mouse_is_on(int m_x, int m_y)
{
    return (m_x>_x && m_x<_x+_size_x && m_y>_y && m_y<_y+_size_y);
}

Widget::~Widget()
{
    //dtor
}
