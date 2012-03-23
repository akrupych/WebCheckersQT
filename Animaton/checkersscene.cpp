#include "checkersscene.h"
#include <QGraphicsSceneMouseEvent>


CheckersScene::CheckersScene()
{
    this->step_number = 1;
}

void CheckersScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if( event->button() == Qt::LeftButton )
    {
        QPointF pnt = event->scenePos();
        int step_x = this->width()/8;
        int step_y = this->height()/8;

        if( ((int)pnt.x()/step_x)%2 == ((int)pnt.y()/step_y)%2 )
        {
            unsigned char row_number = (int)pnt.x()/step_x;
            unsigned char column_number = ( (int)pnt.y()/step_y )/2;


        }
    }
}
