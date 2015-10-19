#ifndef CAR_H
#define CAR_H
#include <QDebug>
class Car
{
public:
    Car(int i);
    bool tacShow();
    bool tacStart();
    bool show;
    bool start;
    int speed;
    int position;
    int position_x;
    int position_y;
    int shape[11][2] = {{4,0},{4,-2},{2,-2},{2,-4},{-2,-4},{-2,-2},{-4,-2},{-4,0},{-2,0},{2,0},{1,0}};
};

#endif // CAR_H
