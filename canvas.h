#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QPoint>
#include <QLineF>
#include <QDebug>
#include <QPolygon>
#include <QTime>
#include <QTimer>
#include "input.h"
#include "car.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

private slots:
    void on_update_clicked();

    void on_tensionSlider_valueChanged(int value);

    void on_tensionSlider_sliderReleased();

    void on_editPointX_sliderReleased();

    void on_editPointY_sliderReleased();

    void on_editPointNum_valueChanged(int arg1);

    void on_addCar_clicked();

    void on_startCar_clicked();

    void on_carSpeed_sliderReleased();

    void updateAnimation();

private:
    Ui::Canvas *ui;
    void paintEvent(QPaintEvent *);
    QPainter *paint;
    QTimer *animationTimer;

};

#endif // CANVAS_H
