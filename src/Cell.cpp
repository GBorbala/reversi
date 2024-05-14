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
}

void Cell::draw_pink()
{
    // Draw a black rectangle of dimensions sx by sy
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);

    // Draw a white rectangle of dimensions sx-1 by sy-1 to create a black border
    gout << move_to(_x + 1, _y + 1) << color(255, 255, 255) << box(_size_x - 1, _size_y - 1);


    int center_x = _x + _size_x / 2;
    int center_y = _y + _size_y / 2;
    gout << color(255, 20, 147); // Pink color

    int star_outer_radius = _size_x / 4; // Radius of the outer points of the star
    int star_inner_radius = star_outer_radius / 2; // Radius of the inner points of the star

    // Coordinates for the star's points (10-point star)
    double pi = 3.14159265358979323846;
    for (int i = 0; i < 10; ++i) {
        double angle = i * pi / 5; // 36 degrees
        int radius = (i % 2 == 0) ? star_outer_radius : star_inner_radius;
        int x = center_x + radius * cos(angle);
        int y = center_y + radius * sin(angle);
        if (i == 0) {
            gout << move_to(x, y);
        } else {
            gout << line_to(x, y);
        }
    }
    gout << line_to(center_x + star_outer_radius, center_y);
}

void Cell::draw_black()
{
    // Draw a black rectangle of dimensions sx by sy
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);

    // Draw a white rectangle of dimensions sx-1 by sy-1 to create a black border
    gout << move_to(_x + 1, _y + 1) << color(255, 255, 255) << box(_size_x - 1, _size_y - 1);


    int center_x = _x + _size_x / 2;
    int center_y = _y + _size_y / 2;
    gout << color(0, 0, 0);

    int star_outer_radius = _size_x / 4; // Radius of the outer points of the star
    int star_inner_radius = star_outer_radius / 2; // Radius of the inner points of the star

    // Coordinates for the star's points (10-point star)
    double pi = 3.14159265358979323846;
    for (int i = 0; i < 10; ++i) {
        double angle = i * pi / 5; // 36 degrees
        int radius = (i % 2 == 0) ? star_outer_radius : star_inner_radius;
        int x = center_x + radius * cos(angle);
        int y = center_y + radius * sin(angle);
        if (i == 0) {
            gout << move_to(x, y);
        } else {
            gout << line_to(x, y);
        }
    }
    gout << line_to(center_x + star_outer_radius, center_y);
}

Cell::~Cell()
{
    //dtor
}
