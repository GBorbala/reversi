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

void Reversi::flip(int i, int j)
{
    char player_color = 'p'; // Assuming the player's color is always pink

    // Directional vectors for exploring adjacent cells
    int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    // Check all eight directions for possible flips
    for (int dir = 0; dir < 8; ++dir)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        bool found_opponent = false;

        // Iterate in the current direction until the boundary or an empty cell is reached
        while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
        {
            char content = _cells[nx][ny]->_content_getter();
            if (content == 'n')
            {
                break; // Break the loop if an empty cell is encountered
            }
            if (content == player_color)
            {
                if (found_opponent)
                {
                    // Flip the opponent's pieces to pink until we reach the player's own piece
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
                    break; // No opponent's pieces found, exit the loop
                }
            }
            else
            {
                found_opponent = true; // Found opponent's piece
            }
            nx += dx[dir];
            ny += dy[dir];
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
                if(_cells[i][j]->mouse_is_on(ev.pos_x, ev.pos_y) && _cells[i][j]->_content_getter()=='g')
                {
                    _cells[i][j]->_content_setter('p');
                    this->flip(i,j);
                    find_legal_moves();
                    this->update();

                }
            }
        }
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

    int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            if (_cells[x][y]->_content_getter() == 'n')
            { // Check only empty cells
                bool adjacent_to_black = false;
                for (int dir = 0; dir < 8; ++dir)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && _cells[nx][ny]->_content_getter() == 'b')
                    {
                        adjacent_to_black = true;
                        break;
                    }
                }
                if (!adjacent_to_black) continue; // Skip if not adjacent to a black star cell

                // Check if it would sandwich black stars between pink stars
                bool valid_move = false;
                for (int dir = 0; dir < 8; ++dir)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    bool found_opponent = false;
                    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                    {
                        char content = _cells[nx][ny]->_content_getter();
                        if (content == 'n')
                        {
                            break; // If an empty cell is found, break the loop
                        }
                        if (content == 'b')
                        {
                            found_opponent = true;
                        }
                        else if (content == 'p')
                        {
                            if (found_opponent)
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
                        break; // No need to check other directions once a legal move is found
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
