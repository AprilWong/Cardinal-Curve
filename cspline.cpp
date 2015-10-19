#include "cspline.h"

CSpline::CSpline(double x[100], double y[100], int grain, double tension, int n) {

  for (int i = 1; i <= n; i ++) {
    Ppoint[i].x = x[i - 1];
    Ppoint[i].y = y[i - 1];
  }

  Ppoint[0].x = x[0];
  Ppoint[0].y = y[0];

  Ppoint[n + 1].x = x[n - 1];
  Ppoint[n + 1].y = y[n - 1];

  CubicSpline(n + 2, grain, tension);
};


void CSpline::CubicSpline(int n, int grain, double tension) {

  GetCardinalMatrix(tension);

  CPT *s, *k;
  s = Spline;
  k = Ppoint;

  for (int i = 1; i < n; i ++) {
    for (int j = 0; j < grain; j ++) {
      s->x = Matrix(k->x, (k + 1)->x, (k + 2)->x, (k + 3)->x, ((double)j) / grain);
      s->y = Matrix(k->y, (k + 1)->y, (k + 2)->y, (k + 3)->y, ((double)j) / grain);
      s ++;
    }
    k ++;
  }
};

void CSpline::GetCardinalMatrix(double t) {
  m[0] = - t;     m[1] = 2 - t;   m[2] = t - 2;     m[3] = t;
  m[4] = 2 * t;   m[5] = t - 3;   m[6] = 3 - 2 * t; m[7] = -t;
  m[8] = - t;     m[9] = 0;       m[10] = t;        m[11] = 0;
  m[12] = 0;      m[13] = 1;      m[14] = 0;        m[15] = 0;
};

double CSpline::Matrix(double a, double b, double c, double d, double alpha) {
  double p[4];
  for (int i = 0; i < 4; i ++) {
    p[i] = m[i * 4 + 0] * a + m[i * 4 + 1] * b + m[i * 4 + 2] * c + m[i * 4 + 3] * d;
  }
  return (p[3] + alpha * (p[2] + alpha * (p[1] + alpha * p[0])));
};
