#include "cell.h"

Cell::Cell(unsigned char row_n, unsigned char column_n)
{
    if(row_n >= ROW_NUMBER || column_n >= COLUMN_NUMBER)
    {
        string exep = "ERROR! unexpected argument in Cell::Cell(unsigned char row_n, unsigned char column_n)\n";
        throw exep;
    }

    row = row_n;
    column = column_n;
    canMoveTo = false;
    figure = NULL;
}

Cell::Cell(unsigned char fcolor, unsigned char row_n, unsigned char column_n)
{
    if(row_n >= ROW_NUMBER || column_n >= COLUMN_NUMBER)
    {
        string exep = "ERROR! unexpected argument Cell(unsigned char fcolor, unsigned char row_n, unsigned char column_n)\n";
        throw exep;
    }

    row = row_n;
    column = column_n;
    canMoveTo = false;
    figure = new Figure(fcolor);
}

bool Cell::isEmpty() const
{
    if( this->figure == NULL )
    {
        return true;
    }
    return false;
}

void Cell::beat()
{
    delete figure;
    figure = NULL;
}

void Cell::setCanMove(bool arg)
{
    this->canMoveTo = arg;
}

unsigned char Cell::getRow()const
{
    return row;
}

unsigned char Cell::getColumn()const
{
    return column;
}

Figure Cell::getFigure() const
{
    if( figure == NULL )
    {
        string exep = "ERROR! getFigure function cannot return value from NULL pointer!\n";
        throw exep;
    }

    return *figure;
}

