#ifndef CELL_H
#define CELL_H
#include "figure.h"
#define ROW_NUMBER 8
#define COLUMN_NUMBER 4

class Cell
{
    Figure* figure;
    bool canMoveTo;
    unsigned char row;
    unsigned char column;

public:
    Cell(unsigned char fcolor, unsigned char row_n, unsigned char column_n);
    Cell(unsigned char row_n, unsigned char column_n);
    void setFigure(Figure* arg);
    Figure getFigure()const;
    void beat();
    void setCanMove(bool arg);
    bool isEmpty()const;
    unsigned char getRow()const;
    unsigned char getColumn()const;
};

#endif // CELL_H
