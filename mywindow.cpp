#include "mywindow.h"
#include "mybutton.h"
#include <QPainter>
#include "mw1.h"
#include <QApplication>
Mywindow::Mywindow(QWidget *parent) : QMainWindow(parent)
{
   this->setFixedSize(1800,900);
    mybutton *back_btn=new mybutton(":pics/exit.jpg");
    back_btn->setFixedSize(400,200);
    back_btn->setParent(this);
    back_btn->move(250,0);
    mybutton *a1=new mybutton(":pics/1.jpg");
    a1->setFixedSize(250,250);
    a1->setParent(this);
    a1->move(1000,0);
    mybutton *a2=new mybutton(":pics/2.jpg");
    a2->setFixedSize(250,250);
    a2->setParent(this);
    a2->move(1000,250);
    mybutton *a3=new mybutton(":pics/3.jpg");
    a3->setFixedSize(250,250);
    a3->setParent(this);
    a3->move(1000,500);
    connect(a1,&mybutton::clicked,this,[=](){
        this->hide();
       MW1 *mw= new MW1;
       mw->show();
    });
    connect(a2,&mybutton::clicked,this,&Mywindow::next_task);
    connect(a3,&mybutton::clicked,this,&Mywindow::next_task);
    connect(back_btn,&mybutton::clicked,this,[=](){
        emit chooseBack();
    });
}
void Mywindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    foreach(plants* plants,plants_list)
        plants->draw(&painter);
}
void Mywindow::set_plants(){
    plants * newplants= new plants(QPoint(200,200),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Mywindow::next_task(){
    plants * newplants= new plants(QPoint(200,200),":pics/tongguan.jpg");
    plants_list.push_back(newplants);
    update();
}
