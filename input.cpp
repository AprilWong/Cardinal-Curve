#include "input.h"

Input::Input(int c, int g, double t)
{
    control = c;
    grain = g;
    tension = t;
    total = (c - 1) * g;
    for (int i = 0; i < c; i ++) {
        point_x[i] = 100 * i / (c - 1);
        point_y[i] = 50;
    }
    for (int i = 0; i < total; i ++) {
        grain_x[i] = 100 * i / (total - 1);
        grain_y[i] = 50;
    }
}

void Input::debug(){
    qDebug("Start to Debug Input");
    qDebug("c%d, g%d, t%.2f, tt%d", control, grain, tension, total);
    for(int i = 0; i < control; i ++){
        qDebug("num%d, cx%.2f, cy%.2f", i+1, point_x[i], point_y[i]);
    }
    for(int i = 0; i < total; i ++){
        qDebug("num%d,gx%.2f, gy%.2f", i+1, grain_x[i], grain_y[i]);
    }
}

void Input::update_pointX(int i, int x) {
    point_x[i] = x;
}

void Input::update_pointY(int i, int y) {
    point_y[i] = y;
}

void Input::update_tension(double t) {
    tension = t;
}

void Input::update_number(int c, int g) {
    control = c;
    grain = g;
    total = (c - 1) * g;
    for (int i = 0; i < c; i ++) {
        point_x[i] = 100 * i / (c - 1);
        point_y[i] = 50;
    }
    for (int i = 0; i < total; i ++) {
        grain_x[i] = 100 * i / (total - 1);
        grain_y[i] = 50;
    }
}

void Input::update_grain(){
    CSpline cspline(point_x, point_y, grain, tension, control);
    for(int i = 0; i < total; i ++) {
        grain_x[i] = cspline.Spline[i].x;
        grain_y[i] = cspline.Spline[i].y;
    }
}
