#include "mywindow.h"
#include "mybutton.h"
#include <QPainter>
Mywindow::Mywindow(QWidget *parent) : QMainWindow(parent)
{
   this->setFixedSize(800,600);
    mybutton *back_btn=new mybutton(":pics/plant.jpg");
    back_btn->setParent(this);
    back_btn->move(40,40);
    mybutton *set_plants=new mybutton(":pics/plant.jpg");
    set_plants->setParent(this);
    set_plants->move(100,100);
    connect(set_plants,&mybutton::clicked,this,&Mywindow::set_plants);
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
    plants * newplants= new plants(QPoint(200,200),":pics/plant.jpg");
    plants_list.push_back(newplants);
    update();
}
