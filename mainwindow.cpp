#include "mainwindow.h"
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
    this->setFixedSize(1800,900);
    ui->setupUi(this);
    mybutton *btn =new mybutton(":pics/begin.jpg");
    btn->setFixedSize(400,200);
    btn->setParent(this);
    btn->move(250,40);
    Mywindow *scene=new Mywindow;
    connect(btn,&QPushButton::clicked,this,[=](){
            this->hide();
            scene->show();
        });
   connect(scene,&Mywindow::chooseBack,this,[=](){
                scene->hide();
                this->show();
            });
   //mywindow back_btn clicked emit chooseBackz
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

