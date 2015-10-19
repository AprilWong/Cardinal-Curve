#include "car.h"

Car::Car(int i)
{
    show = false;
    start = false;
    speed = 0;
    position = 0;
    position_x = 0;
    position_y = 0;
    for(int i = 0; i < 10; i++) {
        shape[i][0] = (shape[i][0] + 5 ) * 4 - 16 ;
        shape[i][1] = (shape[i][1] + 5 ) * 4 - 15;

    }
    shape[8][0] -= 4;
    shape[8][1] -= 5;
    shape[9][0] -= 4;
    shape[9][1] -=5;
//    shape[0] = {3,0};
//    shape[1] = {2,1};
//    shape[2] = {1,1};
//    shape[3] = {1,2};
//    shape[4] = {-1,2};
//    shape[5] = {-1,1};
//    shape[6] = {-2,1};
//    shape[7] = {-3,0};
//    shape[8] = {-1,0};
//    shape[9] = {1,0};
//    shape[10] = {1,0};
}

bool Car::tacShow()
{
    show = !show;
    if(show) return false;
    else return true;
}

bool Car::tacStart()
{
    start = !start;
    if(start) return false;
    else return true;
}

