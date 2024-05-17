#include "Reversi.hpp"
#include "Cell.hpp"
#include "Widget.hpp"
#include "graphics.hpp"
#include "Menu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace genv;

const int Reversi::dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int Reversi::dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

Reversi::Reversi(int x, int y, int sx, int sy):Widget(x,y,sx,sy), round(true)
{
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            _cells[i][j] = new Cell(x+j * 75, y + i * 75, 75, 75, 'n');
        }
    }
}

//to menu class
/*void Reversi::show_result()
{
    gout<<color(255, 255, 255) << move_to(_x,_y)<<box(_size_x, _size_y);

    int p_counter=0;
    int b_counter=0;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(_cells[i][j]->_content_getter()=='p')
            {
                p_counter++;
            }
            else if(_cells[i][j]->_content_getter()=='b')
            {
                b_counter++;
            }
        }
    }

    gout<<color(255,20,147)<<move_to(250,250)<<text("Pink points: ")<<text(std::to_string(p_counter));
    gout<<color(0,0,0)<<move_to(250,280)<<text("Black points: ")<<text(std::to_string(b_counter));
}*/

void Reversi::draw()
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {

            _cells[i][j]->_content_setter('n');

        }
    }

    _cells[3][3]->_content_setter('p');
    _cells[4][4]->_content_setter('p');
    _cells[4][3]->_content_setter('b');
    _cells[3][4]->_content_setter('b');

    find_legal_moves();

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
            gout<<refresh;
        }
    }
}

void Reversi::flip(int i, int j, char player)
{
    char player_color = player;

    for (int dir = 0; dir < 8; ++dir)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        bool found_opponent = false;


        while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
        {
            char content = _cells[nx][ny]->_content_getter();
            if (content == 'n' or content=='g')
            {
                break;
            }
            if (content == player_color)
            {
                if (found_opponent)
                {

                    int flip_x = i + dx[dir];
                    int flip_y = j + dy[dir];
                    while (flip_x != nx || flip_y != ny)
                    {
                        _cells[flip_x][flip_y]->_content_setter(player_color);
                        flip_x += dx[dir];
                        flip_y += dy[dir];
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                found_opponent = true;
            }
            nx += dx[dir];
            ny += dy[dir];
        }
    }
}

void Reversi::event_handle(event ev)
{
    bool legal_exists=false;
    bool ng_exists=false;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(_cells[i][j]->_content_getter()=='g')
            {
                legal_exists=true;
            }
            else if(_cells[i][j]->_content_getter()=='g' or _cells[i][j]->_content_getter()=='n')
            {
                ng_exists=true;
            }
        }
    }

    Menu menu(0, 0, 600, 600);
    if(!legal_exists && !ng_exists)
    {
        menu.show_result(_cells);
    }
    else
    {
        this->find_legal_moves();
        this->update();

        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            if(round)
            {
                for(int i = 0; i < 8; ++i)
                {
                    for(int j = 0; j < 8; ++j)
                    {
                        if(_cells[i][j]->mouse_is_on(ev.pos_x, ev.pos_y) && _cells[i][j]->_content_getter()=='g')
                        {
                            //find_legal_moves();
                            _cells[i][j]->_content_setter('p');
                            this->flip(i, j, 'p');
                            this->update();
                            round = !round;
                            break;
                        }
                    }
                }
            }

            if(!round)
            {
                this->find_legal_moves_black();
                this->update();
                round = !round;
            }
        }
    }

}



void Reversi::find_legal_moves_black()
{
    // Clear previous legal moves
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (_cells[i][j]->_content_getter() == 'g')
            {
                _cells[i][j]->_content_setter('n');
            }
        }
    }

    std::vector<Coordinate> coordinates;


    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            if (_cells[x][y]->_content_getter() == 'n')
            {
                bool valid_move = false;
                for (int dir = 0; dir < 8; ++dir)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    int count_opponents = 0;
                    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                    {
                        char content = _cells[nx][ny]->_content_getter();
                        if (content == 'n' || content == 'g')
                        {
                            break;
                        }
                        if (content == 'p')
                        {
                            count_opponents++;
                        }
                        else if (content == 'b')
                        {
                            if (count_opponents > 0)
                            {
                                valid_move = true;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                        nx += dx[dir];
                        ny += dy[dir];
                    }
                    if (valid_move)
                    {
                        coordinates.push_back(Coordinate(x, y));
                        break;
                    }
                }
            }
        }
    }

    if (!coordinates.empty())
    {

        int ran = rand() % coordinates.size();
        int x = coordinates[ran].x;
        int y = coordinates[ran].y;

        _cells[x][y]->_content_setter('b');
        this->flip(x, y, 'b');
    }
}



void Reversi::find_legal_moves()
{
    // Clear previous legal moves
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (_cells[i][j]->_content_getter() == 'g')
            {
                _cells[i][j]->_content_setter('n');
            }
        }
    }



    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            if (_cells[x][y]->_content_getter() == 'n')
            {

                bool valid_move = false;
                for (int dir = 0; dir < 8; ++dir)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    int count_opponents = 0;
                    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                    {
                        char content = _cells[nx][ny]->_content_getter();
                        if (content == 'n' or content == 'g')
                        {
                            break;
                        }
                        if (content == 'b')
                        {
                            count_opponents++;
                        }
                        else if (content == 'p')
                        {
                            if (count_opponents > 0)
                            {
                                valid_move = true;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                        nx += dx[dir];
                        ny += dy[dir];
                    }
                    if (valid_move)
                    {
                        _cells[x][y]->_content_setter('g');
                        break;
                    }
                }
            }
        }
    }
}




Reversi::~Reversi()
{
    //dtor
}
