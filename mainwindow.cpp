#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QToolBar>
#include <QPaintEvent>
#include <QPolygon>
#include <QPainter>
#include "QMouseEvent"
#include <QPoint>
#include <QDebug>
//#include <vector>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StaticContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    drawing = true;
    startPosition = event->pos();
    endPosition = startPosition;
    update();

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(drawing)
    {
        endPosition = event->pos();
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(drawing)
    {
        drawing = false;
        endPosition = event->pos();
        qDebug()<<startPosition<<" "<<endPosition;
        QRect rect(startPosition, endPosition);
        rectangles.push_back(rect);
        update();
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    QRect currentRect(startPosition, endPosition);
    if(n==1)
    {
            QRect currentRect(startPosition, endPosition);
        for (const auto& recttt : rectangles)
        {
            painter.drawRect(recttt);
        }

        if (drawing)
        {
            painter.drawRect(currentRect);
        }

    }
    if(n==2)
    {
            QRect currentRect(startPosition, endPosition);
        painter.drawEllipse(currentRect);
    }
    if(n==3)
    {
            QRect currentRect(startPosition, endPosition);
        painter.drawLine(startPosition, endPosition);
    }
    if(n==4)
    {
            QRect currentRect(startPosition, endPosition);
        painter.drawRoundRect(currentRect);
    }
    if(n==5)
    {
        QPolygon poly;
        poly<<QPoint(40,560);//550
        poly<<QPoint(120,580);
        poly<<QPoint(120,590);
        poly<<QPoint(50,600);
        painter.drawPolygon(poly);
    }
}

void MainWindow::on_pushButtonRect_clicked()
{
    n = 1;
    update();
}


void MainWindow::on_pushButtonEllipse_clicked()
{
    n = 2;
    update();
}


void MainWindow::on_pushButtonLine_clicked()
{
    n = 3;
    update();
}


void MainWindow::on_pushButtonRoundRect_clicked()
{
    n = 4;
    update();
}


void MainWindow::on_pushButtonPolygon_clicked()
{
    n = 5;
    qDebug()<<n<<endl;
    update();
}

