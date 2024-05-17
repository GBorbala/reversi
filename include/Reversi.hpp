#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Widget.hpp"
#include "Cell.hpp"

using namespace genv;

class Reversi : public Widget
{
    public:
        Reversi(int,int,int,int);
        void draw() override;
        void update();
        //void show_result();
        void event_handle(event)override;
        void find_legal_moves();
        void find_legal_moves_black();
        void make_black_move();
        void flip(int, int, char);
        virtual ~Reversi();

    protected:
        Cell* _cells[8][8];
        struct Coordinate {
            int x;
            int y;

            Coordinate(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
        };

    private:
        static const int dx[8];
        static const int dy[8];
        bool round;

};

#endif // REVERSI_HPP
