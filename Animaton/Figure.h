#ifndef FIGURE_H
#define FIGURE_H

#define COLOR_RED 1
#define COLOR_BLUE 2
#include <string>

using namespace std;

class Figure
{
    unsigned char color;
    bool queen;
public:
    Figure(unsigned char col);
    unsigned char getColor()const;
    unsigned char getEnemyColor()const;
    bool isQueen()const;
    void setQueen();
};

#endif // FIGURE_H
