#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QtMath>
#define PI 314

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void calc(float t, int &x, int &y)
{
    float a = ( 1 + 0.9 * qCos(8*t) ) * ( 1 + 0.1*qCos(24*t)) * (0.9 + 0.05*qCos(200*t)) * (1 + qSin(t)) * 100.0;

    x = a * qCos(t);
    y = a * qSin(t);
}
void MainWindow::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    int w = width();
    int h = height();

    painter.setViewport(QRect(0,0,w,h));
    painter.setWindow(-PI, 400, 2*PI, -500);
    int i;
    //x axis
    painter.drawLine(-PI, 0, PI, 0);
    for(i = -3; i<=3; i++)
    {
        painter.drawLine(i*100, -5, i*100, 5);
        //painter.drawText(i*100+3,6,QString::number(i));
    }
    //y aix
    painter.drawLine(0, 400, 0, -100);


    painter.setPen(Qt::blue);
    for(i = 0; i<= 2*PI; i++)
    {
        float t1 = (float)i/100.0;
        float t2 = (float)(i-1)/100.0;
        int x1,y1,x2,y2;

        calc(t1,x1, y1);
        calc(t2,x2, y2);


        painter.drawLine(x1,y1,x2,y2);

    }
}
