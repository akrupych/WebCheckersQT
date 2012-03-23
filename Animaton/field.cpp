#include "field.h"
#define FIELD_WIDTH 8
#define FIELD_HEIGHT 8

Field::Field()
{
    for( int i = 0; i < ROW_NUMBER; i++ )
    {
        for( int j = 0; j < COLUMN_NUMBER; j++ )
        {
            if( i < 3 )
            {
                GameCells[i][j] = new Cell(COLOR_RED, i, j);
            }

            if( i > 4 )
            {
                GameCells[i][j] = new Cell(COLOR_BLUE, i, j);
            }

            if( i <= 4 && i >= 3 )
            {
                GameCells[i][j] = new Cell(i,j);
                GameCells[i][j]->setCanMove(false);
            }
        }
    }
}

void Field::showField(QGraphicsScene *scene)const
{
    scene->clear();

    QPen Boundarypen = QPen( Qt::black, 8 );

    scene->addRect( 0, 0, scene->width(), scene->height(), Boundarypen );
    QPen fieldpen = QPen(Qt::black);
    QBrush cellbrush = QBrush(Qt::black);

    QBrush redbrush = QBrush(Qt::red);
    QBrush bluebrush = QBrush(Qt::blue);

    int wigth = scene->width()/8;
    int height = scene->height()/8;

    for( int i = 0; i < 8; i++ )
    {
        for( int j = 0; j < 8; j++ )
        {
            if( ( i%2 != 0 && j%2 != 0 ) || ( i%2 == 0 && j%2 == 0 ) )
            {
                int x = i*wigth;
                int y = j*height;

                scene->addRect( x, y, wigth, height, fieldpen, cellbrush );

                if( !GameCells[i][j/2]->isEmpty() )
                {
                    if( GameCells[i][j/2]->getFigure().getColor() == COLOR_RED )
                    {
                        scene->addEllipse(x, y, wigth, height, fieldpen, redbrush );
                    }

                    if( GameCells[i][j/2]->getFigure().getColor() == COLOR_BLUE )
                    {
                        scene->addEllipse(x, y, wigth, height, fieldpen, bluebrush );
                    }
                }
            }
        }
    }

}

bool Field::isEmpty(unsigned char row, unsigned char column) const
{
    if(row >= ROW_NUMBER || column >= COLUMN_NUMBER)
    {
        string exep = "ERROR! unexpected argument in isEmpty function (class Field)\n";
        throw exep;
    }

    return GameCells[row][column]->isEmpty();
}

Cell * Field::getTopRight(const Cell *arg)const
{
    if( arg == NULL )
    {
        return NULL;
    }

    if( arg->getRow() == ROW_NUMBER-1 )
    {
        return NULL;
    }

    if( arg->getRow()%2 == 0 )
    {
        if( arg->getColumn() == COLUMN_NUMBER-1 )
        {
            return NULL;
        }

        return this->GameCells[arg->getRow()+1][arg->getColumn()+1];
    }
    else
    {
        return this->GameCells[arg->getRow()+1][arg->getColumn()];
    }
}

Cell * Field::getTopLeft(const Cell *arg)const
{
    if( arg == NULL )
    {
        return NULL;
    }
    if( arg->getRow() == ROW_NUMBER-1 )
    {
        return NULL;
    }

    if( arg->getRow()%2 == 1 )
    {
        if( arg->getColumn() == 0 )
        {
            return NULL;
        }

        return this->GameCells[arg->getRow()+1][arg->getColumn()-1];
    }
    else
    {
        return this->GameCells[arg->getRow()+1][arg->getColumn()];
    }
}

Cell * Field::getBottomRight(const Cell *arg)const
{
    if( arg == NULL )
    {
        return NULL;
    }

    if( arg->getRow() == 0 )
    {
        return NULL;
    }

    if( arg->getRow()%2 == 0 )
    {
        if( arg->getColumn() == COLUMN_NUMBER-1 )
        {
            return NULL;
        }

        return this->GameCells[arg->getRow()-1][arg->getColumn()+1];
    }
    else
    {
        return this->GameCells[arg->getRow()-1][arg->getColumn()];
    }
}

Cell * Field::getBottomLeft(const Cell *arg)const
{
    if( arg == NULL )
    {
        return NULL;
    }

    if( arg->getRow() == 0 )
    {
        return NULL;
    }

    if( arg->getRow()%2 == 1 )
    {
        if( arg->getColumn() == COLUMN_NUMBER-1 )
        {
            return NULL;
        }

        return this->GameCells[arg->getRow()-1][arg->getColumn()-1];
    }
    else
    {
        return this->GameCells[arg->getRow()-1][arg->getColumn()];
    }
}

bool Field::canBeatTR(const Cell *arg)
{
    Cell* temp = getTopRight(arg);
    Cell* tempTR = getTopRight(temp);

    if( tempTR != NULL && !arg->isEmpty() )    // getTopRight checks arg for NULL value
    {
        if( !temp->isEmpty() )
        {
            if( arg->getFigure().getColor() == temp->getFigure().getColor() )
            {
                return false;
            }
            if( tempTR->isEmpty() )
            {
                tempTR->setCanMove(true);
            }
         }
    }
    return false;
}

bool Field::canBeatTL(const Cell *arg)
{
    Cell* temp = getTopLeft(arg);
    Cell* tempTR = getTopLeft(temp);

    if( tempTR != NULL && !arg->isEmpty() )    // getTopRight checks arg for NULL value
    {
        if( !temp->isEmpty() )
        {
            if( arg->getFigure().getColor() == temp->getFigure().getColor() )
            {
                return false;
            }
            if( tempTR->isEmpty() )
            {
                tempTR->setCanMove(true);
            }
         }
    }
    return false;
}

bool Field::canBeatBR(const Cell *arg)
{
    Cell* temp = getBottomRight(arg);
    Cell* tempTR = getBottomRight(temp);

    if( tempTR != NULL && !arg->isEmpty() )    // getTopRight checks arg for NULL value
    {
        if( !temp->isEmpty() )
        {
            if( arg->getFigure().getColor() == temp->getFigure().getColor() )
            {
                return false;
            }
            if( tempTR->isEmpty() )
            {
                tempTR->setCanMove(true);
            }
         }
    }
    return false;
}

bool Field::canBeatBL(const Cell *arg)
{
    Cell* temp = getBottomLeft(arg);
    Cell* tempTR = getBottomLeft(temp);

    if( tempTR != NULL && !arg->isEmpty() )    // getTopRight checks arg for NULL value
    {
        if( !temp->isEmpty() )
        {
            if( arg->getFigure().getColor() == temp->getFigure().getColor() )
            {
                return false;
            }
            if( tempTR->isEmpty() )
            {
                tempTR->setCanMove(true);
            }
         }
    }
    return false;
}

bool Field::canBeat(unsigned char row, unsigned char column)
{
    Cell* arg = getCell(row, column);
    return ( canBeatTR(arg) || canBeatTL(arg) || canBeatBR(arg) || canBeatBL(arg) );
}

bool Field::qcanBeatTR(const Cell *arg)
{
    if( arg == NULL || !arg->getFigure().isQueen() )
    {
        string exep = "ERROR! qcanBeatTR function cannot take not queen, or arg is NULL\n";
        throw exep;
    }

    unsigned char tmpcol = arg->getFigure().getColor();
    bool was_token = false;

    Cell* temp = getTopRight(arg);                          // Top Right element

    while( temp != NULL )                                   // while it's not an end of field
    {
        if( temp->isEmpty() )                               // if it's empty cell
        {
            if( was_token )                                 // and we beated some figure
            {
                temp->setCanMove(true);                     // then we can move on this
            }
            temp = getTopRight(temp);                       // set checking on next top right cell
        }

        else                                                // if it's not empty cell
        {
            if( temp->getFigure().getColor() == tmpcol )    // if it's friendly figure
            {
                break;
            }
            else                                            // !!! if it's an empty cell
            {
                if( was_token )                             // we can beat only 1 time per move!
                {
                    break;
                }

                // !!! not token
                if( getTopRight(temp)->isEmpty() )          // if next one is empty
                {
                    was_token = true;                       // we beated!
                    temp = getTopRight(temp);               // move to that pozition
                    temp->setCanMove(true);
                }
            }
        }
    }
    return was_token;
}

bool Field::qcanBeatTL(const Cell *arg)
{
    if( arg == NULL || !arg->getFigure().isQueen() )
    {
        string exep = "ERROR! qcanBeatTL function cannot take not queen, or arg is NULL\n";
        throw exep;
    }

    unsigned char tmpcol = arg->getFigure().getColor();
    bool was_token = false;

    Cell* temp = getTopLeft(arg);                          // Top Left element

    while( temp != NULL )                                   // while it's not an end of field
    {
        if( temp->isEmpty() )                               // if it's empty cell
        {
            if( was_token )                                 // and we beated some figure
            {
                temp->setCanMove(true);                     // then we can move on this
            }
            temp = getTopLeft(temp);                       // set checking on next top right cell
        }

        else                                                // if it's not empty cell
        {
            if( temp->getFigure().getColor() == tmpcol )    // if it's friendly figure
            {
                break;
            }
            else                                            // !!! if it's an empty cell
            {
                if( was_token )                             // we can beat only 1 time per move!
                {
                    break;
                }

                // !!! not token
                if( getTopLeft(temp)->isEmpty() )          // if next one is empty
                {
                    was_token = true;                       // we beated!
                    temp = getTopLeft(temp);               // move to that pozition
                    temp->setCanMove(true);
                }
            }
        }
    }
    return was_token;
}

bool Field::qcanBeatBR(const Cell *arg)
{
    if( arg == NULL || !arg->getFigure().isQueen() )
    {
        string exep = "ERROR! qcanBeatBR function cannot take not queen, or arg is NULL\n";
        throw exep;
    }

    unsigned char tmpcol = arg->getFigure().getColor();
    bool was_token = false;

    Cell* temp = getBottomRight(arg);                          // Bottom Right element

    while( temp != NULL )                                   // while it's not an end of field
    {
        if( temp->isEmpty() )                               // if it's empty cell
        {
            if( was_token )                                 // and we beated some figure
            {
                temp->setCanMove(true);                     // then we can move on this
            }
            temp = getBottomRight(temp);                       // set checking on next top right cell
        }

        else                                                // if it's not empty cell
        {
            if( temp->getFigure().getColor() == tmpcol )    // if it's friendly figure
            {
                break;
            }
            else                                            // !!! if it's an empty cell
            {
                if( was_token )                             // we can beat only 1 time per move!
                {
                    break;
                }

                // !!! not token
                if( getBottomRight(temp)->isEmpty() )          // if next one is empty
                {
                    was_token = true;                       // we beated!
                    temp = getBottomRight(temp);               // move to that pozition
                    temp->setCanMove(true);
                }
            }
        }
    }
    return was_token;
}

bool Field::qcanBeatBL(const Cell *arg)
{
    if( arg == NULL || !arg->getFigure().isQueen() )
    {
        string exep = "ERROR! qcanBeatBL function cannot take not queen, or arg is NULL\n";
        throw exep;
    }

    unsigned char tmpcol = arg->getFigure().getColor();
    bool was_token = false;

    Cell* temp = getBottomLeft(arg);                       // Bottom Left element

    while( temp != NULL )                                   // while it's not an end of field
    {
        if( temp->isEmpty() )                               // if it's empty cell
        {
            if( was_token )                                 // and we beated some figure
            {
                temp->setCanMove(true);                     // then we can move on this
            }
            temp = getBottomLeft(temp);                       // set checking on next top right cell
        }

        else                                                // if it's not empty cell
        {
            if( temp->getFigure().getColor() == tmpcol )    // if it's friendly figure
            {
                break;
            }
            else                                            // !!! if it's an empty cell
            {
                if( was_token )                             // we can beat only 1 time per move!
                {
                    break;
                }

                // !!! not token
                if( getBottomLeft(temp)->isEmpty() )          // if next one is empty
                {
                    was_token = true;                       // we beated!
                    temp = getBottomLeft(temp);               // move to that pozition
                    temp->setCanMove(true);
                }
            }
        }
    }
    return was_token;
}

bool Field::qcanBeat(unsigned char row, unsigned char column)
{
    Cell* arg = getCell(row, column);

    return ( qcanBeatTR(arg) || qcanBeatTL(arg) || qcanBeatBR(arg) || qcanBeatBL(arg) );
}

Cell * Field::getCell(unsigned char row, unsigned char column)
{
    if(row >= ROW_NUMBER || column >= COLUMN_NUMBER)
    {
        string exep = "ERROR! unexpected argument in getCell function (class Field)\n";
        throw exep;
    }
    return this->GameCells[row][column];
}

Figure Field::getCellFigure(unsigned char row, unsigned char column)
{
    if(row >= ROW_NUMBER || column >= COLUMN_NUMBER)
    {
        string exep = "ERROR! unexpected argument in getCellFigure function (class Field)\n";
        throw exep;
    }
    return this->GameCells[row][column]->getFigure();
}



