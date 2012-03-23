#include "player.h"
#include "Figure.h"

Player::Player(unsigned char arg)
{
    if(arg != COLOR_RED && arg != COLOR_BLUE)
    {
        string exep = "ERROR! Player constructor got unexpected parameter\n";
        throw exep;
    }

    side = arg;
}

bool Player::canBeatAny(Field &arg)
{
    for( int i = 0; i < ROW_NUMBER; i++ )
    {
        for( int j = 0; j < COLUMN_NUMBER; j++ )
        {
            if( arg.canBeat(i,j) )
            {
                return true;
            }
        }
    }
    return false;
}

bool Player::getStep(Field &arg, unsigned char row, unsigned char column)
{
    if(row >= ROW_NUMBER || column >= COLUMN_NUMBER)
    {
        string exep = "ERROR! unexpected argument in getStep function (class Player)\n";
        throw exep;
    }

    Cell* temp = arg.getCell(row, column);

    if( !temp->isEmpty() )
    {
        Figure tempf = temp->getFigure();

        if( tempf.getColor() != this->side )    // if it's enemy color
        {
            return false;
        }
        else                                    // our side
        {
            if( !tempf.isQueen() )              // if it's not a queen
            {
                if( arg.canBeat(row, column) )             // if we can beat with this figure
                {
                    return true;
                }
                else                            // if can't beat
                {
                    if( this->canBeatAny(arg) )     // check if we can beat with somebody
                    {
                        return false;
                    }
                    else                        //
                    {
                        // TODO !!!!return temp->canMoveAny();
                    }
                }
            }
            else
            {

            }
        }
    }

    return false;
}



