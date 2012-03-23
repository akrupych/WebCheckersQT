#include "figure.h"

Figure::Figure(unsigned char col)
{
    if( col != COLOR_RED && col != COLOR_BLUE )
    {
        string exep = "ERROR! unexpected parameter in Figure class constructor\n";
        throw exep;
    }

    this->color = col;
    this->queen = false;
}

void Figure::setQueen()
{
    this->queen = true;
}

bool Figure::isQueen() const
{
    return this->queen;
}

unsigned char Figure::getColor() const
{
    return this->color;
}

unsigned char Figure::getEnemyColor() const
{
    if( color == COLOR_RED )
    {
        return COLOR_BLUE;
    }

    else
    {
        return COLOR_RED;
    }
}



