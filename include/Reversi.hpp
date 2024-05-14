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
        void event_handle(event)override;
        void find_legal_moves();
        virtual ~Reversi();

    protected:
        Cell* _cells[8][8];

    private:
};

#endif // REVERSI_HPP
