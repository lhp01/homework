#include "mainwindow.h"
#include "QPushButton"
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include "mybutton.h"
#include "stagechoose.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setFixedSize(1800,900);
    mybutton *btn =new mybutton(":pics/begin.jpg");
    btn->setFixedSize(400,200);
    btn->setParent(this);
    btn->move(250,40);
    StageChoose *scene=new StageChoose(this);
    scene->hide();
    connect(btn,&QPushButton::clicked,this,[=](){

            scene->show();
        });

   connect(scene,&StageChoose::chooseBack,this,[=](){
                scene->hide();

            });

}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pixmap(":pics/kaishi.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}

