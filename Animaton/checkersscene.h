#ifndef CHECKERSSCENE_H
#define CHECKERSSCENE_H

#include <QGraphicsScene>



class CheckersScene : public QGraphicsScene
{

    unsigned char step_number;
public:
    CheckersScene();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CHECKERSSCENE_H
