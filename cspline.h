#ifndef CSPLINE_H
#define CSPLINE_H

#include <QDebug>

struct CPT{double x; double y;};

class CSpline
{
public:
    CSpline(double x[100], double y[100], int grain, double tension, int n);
    CPT Spline[1024];
    void CubicSpline(int n, int grain, double tension);
private:
    CPT Ppoint[100];
    double m[16];
    double Matrix(double a, double b, double c, double d, double alpha);
    void GetCardinalMatrix(double a1);
};

#endif // CSPLINE_H
