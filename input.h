#ifndef INPUT_H
#define INPUT_H
#include "cspline.h"
#include <QDebug>

class Input
{
public:
    Input(int control, int grain, double tension);
    void update_tension(double tension);
    void update_pointX(int i, int x);
    void update_pointY(int i, int y);
    void update_number(int c, int g);
    void update_grain();
    void debug();
    int control;
    int grain;
    int total;
    double tension;
    double point_x[100];
    double point_y[100];
    double grain_x[1024];
    double grain_y[1024];
};

#endif // INPUT_H
