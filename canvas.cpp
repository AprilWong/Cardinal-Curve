#include "canvas.h"
#include "ui_canvas.h"

Input input(5, 0, 0);
Car car(0);

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    ui->controlPointInput->setValidator(new QIntValidator(0,20,this));
    ui->grainInput->setValidator(new QIntValidator(0,100,this));
    ui->editPointNum->setRange(1, input.control);
    input.update_grain();
    animationTimer = new QTimer(this);
    connect( animationTimer,SIGNAL(timeout()), this, SLOT(updateAnimation()) );
    car.position_x = input.grain_x[0];
    car.position_y = input.grain_y[0];
}

void Canvas::paintEvent(QPaintEvent *)
{
    paint = new QPainter;
    paint->begin(this);
    paint->setPen(QPen(QColor(150, 150, 150), 2));
    paint->drawRect(20, 70, 460, 250);

    QPoint grain_point[1024];
    for(int i = 0; i < input.total; i ++) {
        grain_point[i].setX(40 + input.grain_x[i] * 400 / 100);
        grain_point[i].setY(100 + input.grain_y[i] * 180 / 100);
    }
    paint->setPen(QPen(QColor(150,150,150),2));
    paint->drawPoints(grain_point, input.total);

    QPoint control_point[100];
    for(int i = 0; i < input.control; i ++) {
        control_point[i].setX(input.point_x[i] * 400 / 100 + 40);
        control_point[i].setY(input.point_y[i] * 180 / 100 + 100);
    }
    paint->setPen(QPen(QColor(255,0,0),8));
    paint->drawPoints(control_point, input.control);
    

    if(car.show == true) {

        paint->setPen(QPen(QColor(100,100,100),2));
        paint->setBrush(QColor(100,180,255));

        QPolygon car_shape;
        for(int i = 0; i < 8; i++) {
            car_shape<<QPoint(car.shape[i][0] + car.position_x * 400 / 100 + 40, car.shape[i][1] + car.position_y * 180 / 100 + 100);
        }


        paint->drawPolygon(car_shape, Qt::WindingFill);
        paint->drawEllipse(car.shape[8][0] + car.position_x * 400 / 100 + 40,car.shape[8][1] + car.position_y * 180 / 100 + 100, car.shape[10][0] * 10, car.shape[10][0] * 10);
        paint->drawEllipse(car.shape[9][0] + car.position_x * 400 / 100 + 40,car.shape[9][1] + car.position_y * 180 / 100 + 100, car.shape[10][0] * 10, car.shape[10][0] * 10);
    }

    paint->end();
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::on_update_clicked()
{
    bool ok;
    input.update_number(ui->controlPointInput->text().toInt(&ok, 10), ui->grainInput->text().toInt(&ok, 10));
    input.update_grain();
    car.position_x = input.grain_x[0];
    car.position_y = input.grain_y[0];
    ui->editPointNum->setRange(1, input.control);
    int arg1 = ui->editPointNum->value();
    ui->editPointX->setValue(input.point_x[arg1-1]);
    ui->editPointY->setValue(input.point_y[arg1-1]);
    repaint();
}

void Canvas::on_tensionSlider_valueChanged(int value)
{
    ui->tensionText->setText(QString::number(((double)value) / 100));
}

void Canvas::on_tensionSlider_sliderReleased()
{
    input.update_tension(((double)ui->tensionSlider->value())/100);

    input.update_grain();
    repaint();
}

void Canvas::on_editPointX_sliderReleased()
{
    input.update_pointX(ui->editPointNum->value() - 1, ui->editPointX->value());
    input.update_grain();
    car.position_x = input.grain_x[0];
    car.position_y = input.grain_y[0];
    repaint();
}

void Canvas::on_editPointY_sliderReleased()
{
    input.update_pointY(ui->editPointNum->value() - 1, ui->editPointY->value());
    input.update_grain();
    car.position_x = input.grain_x[0];
    car.position_y = input.grain_y[0];
    repaint();
}

void Canvas::on_editPointNum_valueChanged(int arg1)
{
    ui->editPointX->setValue(input.point_x[arg1-1]);
    ui->editPointY->setValue(input.point_y[arg1-1]);
}

void Canvas::on_addCar_clicked()
{
    if(car.tacShow()) {
        ui->addCar->setText("add");
        car.start = false;
        ui->startCar->setText("start");
    }
    else ui->addCar->setText("remove");
    repaint();
}

void Canvas::updateAnimation(){
    car.position ++;
    if(car.position > input.total) {
        if (animationTimer->isActive())
            animationTimer->stop();
        car.start = false;
        ui->startCar->setText("start");
        car.position = 0;
        car.position_x = input.grain_x[0];
        car.position_y = input.grain_y[0];
        repaint();
     }
    else {
        car.position_x = input.grain_x[car.position];
        car.position_y = input.grain_y[car.position];
        repaint();
    }
}

void Canvas::on_startCar_clicked()
{
    if(car.tacStart()) {
        ui->startCar->setText("start");
        if (animationTimer->isActive() )
            animationTimer->stop();
        car.position = 0;
        car.position_x = input.grain_x[0];
        car.position_y = input.grain_y[0];
    }
    else {
        ui->startCar->setText("stop");
        animationTimer->start(600 - 5 * car.speed);
    }
}

void Canvas::on_carSpeed_sliderReleased()
{
    car.speed = ui->carSpeed->value();
}
