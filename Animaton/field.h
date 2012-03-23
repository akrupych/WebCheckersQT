#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <QtGui>                // support QGraphicsScene

class Field
{
    Cell* GameCells[ROW_NUMBER][COLUMN_NUMBER];
    bool canBeatTR(const Cell* arg);
    bool canBeatTL(const Cell* arg);
    bool canBeatBR(const Cell* arg);
    bool canBeatBL(const Cell* arg);

    bool qcanBeatTR(const Cell* arg);
    bool qcanBeatTL(const Cell* arg);
    bool qcanBeatBR(const Cell* arg);
    bool qcanBeatBL(const Cell* arg);

    bool qcanMoveTR(const Cell* arg);
    bool qcanMoveTL(const Cell* arg);
    bool qcanMoveBR(const Cell* arg);
    bool qcanMoveBL(const Cell* arg);


public:
    Cell* getTopRight(const Cell* arg)const;
    Cell* getTopLeft(const Cell* arg)const;
    Cell* getBottomRight(const Cell* arg)const;
    Cell* getBottomLeft(const Cell* arg)const;

    Field();
    bool isEmpty(unsigned char row, unsigned char column)const;
    void showField(QGraphicsScene* scene)const;
    bool canBeat(unsigned char row, unsigned char column);
    bool qcanBeat(unsigned char row, unsigned char column);

    bool canMove(unsigned char row, unsigned char column);
    bool qcanMove(unsigned char row, unsigned char column);
    Figure getCellFigure(unsigned char row, unsigned char column);

    Cell* getCell(unsigned char row, unsigned char column);
};

#endif // FIELD_H
