#ifndef PLAYER_H
#define PLAYER_H
#include "field.h"
#include <QtGui>                // support QGraphicsScene

class Player
{
    unsigned char side;
    bool canBeatAny(Field &arg);

public:
    Player(unsigned char arg);
    bool getStep(Field &arg, unsigned char row, unsigned char column);
};

#endif // PLAYER_H
