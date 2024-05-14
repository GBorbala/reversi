#ifndef CELL_HPP
#define CELL_HPP

#include "Widget.hpp"

class Cell : public Widget
{
    public:
        Cell(int,int,int,int,char);

        void draw() override;

        virtual ~Cell();

    protected:
        char _content;

    private:
};

#endif // CELL_HPP
