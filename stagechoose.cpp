#include "stagechoose.h"
#include "mybutton.h"
#include <QPainter>

#include <QApplication>
StageChoose::StageChoose(QWidget *parent) : QMainWindow(parent)
{
    stage = nullptr;

   this->setFixedSize(1800,900);
    this->setWindowFlags(Qt::SubWindow);
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
    //Stage *mw= new Stage(this);

    connect(a1,&mybutton::clicked,this,[=](){
        //this->hide();
        if(!this->stage)
        {
            stage = new Stage(this);
            connect(stage, &Stage::reChooseSignal, this, [=](){stage->close();stage = NULL;});
            connect( stage,&Stage::returnSignal, this,  [=](){stage->close(); stage = NULL;emit chooseBack();});
        }
       stage->show();
    });
    connect(a2,&mybutton::clicked,this,&StageChoose::next_task);
    connect(a3,&mybutton::clicked,this,&StageChoose::next_task);
    connect(back_btn,&mybutton::clicked,this,[=](){
        emit chooseBack();
    });
}
void StageChoose::paintEvent(QPaintEvent*){
    QPainter painter(this);

         painter.setBrush(Qt::white);

         painter.drawRect(this->rect());
   /* QPainter painter(this);
    foreach(plants* plants,plants_list)
        plants->draw(&painter);
*/}
void StageChoose::next_task(){
    plants * newplants= new plants(QPoint(200,200),":pics/tongguan.jpg");
    plants_list.push_back(newplants);
    update();
}
