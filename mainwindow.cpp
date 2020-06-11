#include "mainwindow.h"
#include "ui_mywidget.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include <QPainter>
#include <QDebug>
#include <QPaintEvent>
#include <QPixmap>
#include "mybutton.h"
#include "mywindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setFixedSize(1000,1000);
    ui->setupUi(this);
    mybutton *btn =new mybutton(":pics/plant.jpg");
    btn->setParent(this);
    btn->move(200,200);
    Mywindow *scene=new Mywindow;
    connect(btn,&QPushButton::clicked,this,[=](){
            this->hide();
            scene->show();
        });
   connect(scene,&Mywindow::chooseBack,this,[=](){
                scene->hide();
                this->show();
            });
//  QPushButton *btn=new QPushButton(this);
//  btn->setFixedSize(100,50);
//  btn->move(40,40);
//  connect(btn,&QPushButton::clicked,this,&QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pixmap(":pics/kaishi.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
