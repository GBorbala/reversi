#ifndef CELL_HPP
#define CELL_HPP

#include "Widget.hpp"

class Cell : public Widget
{
    public:
        Cell(int,int,int,int,char);
        char _content_getter();
        void _content_setter(char);
        void draw() override;
        void draw_pink();
        void draw_black();
        virtual ~Cell();

    protected:
        char _content;

    private:
};

#endif // CELL_HPP
