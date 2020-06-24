#include "stage.h"
//#include "ui_Stage.h"
#include "icon.h"
#include <QTime>
#include<QTimer>
#include <map>
#include <iostream>
#include "stagechoose.h"

using namespace std;
void Stage::set_plants1(){
    plants * newplants= new plants(QPoint(300,100),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants2(){
    plants * newplants= new plants(QPoint(300,200),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants3(){
    plants * newplants= new plants(QPoint(300,300),":pics/leaves.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants4(){
    plants * newplants= new plants(QPoint(300,400),":pics/leaves.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants5(){
    plants * newplants= new plants(QPoint(300,500),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants6(){
    plants * newplants= new plants(QPoint(300,600),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants11(){
    plants * newplants= new plants(QPoint(300,100),":pics/double.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants21(){
    plants * newplants= new plants(QPoint(300,200),":pics/double.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants31(){
    plants * newplants= new plants(QPoint(300,300),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants41(){
    plants * newplants= new plants(QPoint(300,400),":pics/single.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants51(){
    plants * newplants= new plants(QPoint(300,500),":pics/double.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants61(){
    plants * newplants= new plants(QPoint(300,600),":pics/double.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants12(){
    plants * newplants= new plants(QPoint(300,100),":pics/four.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants22(){
    plants * newplants= new plants(QPoint(300,200),":pics/four.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants32(){
    plants * newplants= new plants(QPoint(300,300),":pics/double.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants42(){
    plants * newplants= new plants(QPoint(300,400),":pics/double.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants52(){
    plants * newplants= new plants(QPoint(300,500),":pics/four.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::set_plants62(){
    plants * newplants= new plants(QPoint(300,600),":pics/four.jpg");
    plants_list.push_back(newplants);
    update();
}
void Stage::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    delete pa;
    QPainter painter(this);
foreach(plants* plants,plants_list)
    plants->draw(&painter);
}
Stage::Stage(QWidget *parent) :
    QWidget(parent)
    //,ui(new Ui::Stage)
{
    //ui->setupUi(this);

    //init game world

    setAttribute(Qt::WA_DeleteOnClose);
    QPushButton *rechooseButton  = new QPushButton(this);
    rechooseButton->setText(tr("重新选择关卡"));
    rechooseButton->setFixedSize(120,50);
    rechooseButton->setParent(this);
    rechooseButton->move(0,0);
    connect( rechooseButton, &QPushButton::clicked, this, &Stage::reChooseSignal);

    QPushButton * returnTitleButton = new QPushButton(this);
    returnTitleButton ->setFixedSize(120,50);
    returnTitleButton ->setParent(this);
    returnTitleButton ->move(0,50);
    returnTitleButton->setText(tr("返回标题"));
    connect( returnTitleButton, &QPushButton::clicked, this, &Stage::returnSignal);

    QPushButton *setplantsButton  = new QPushButton(this);
    setplantsButton->setParent(this);
    setplantsButton->setText(tr("plant here"));
    setplantsButton->setFixedSize(100,100);
    setplantsButton->move(200,100);
    connect( setplantsButton, &QPushButton::clicked, this, &Stage::set_plants1);
    QPushButton *setplantsButton11 = new QPushButton(this);
    setplantsButton11->setParent(this);
    setplantsButton11->setText(tr("update"));
    setplantsButton11->setFixedSize(100,30);
    setplantsButton11->move(200,100);
    connect( setplantsButton11, &QPushButton::clicked, this, &Stage::set_plants11);
    QPushButton *setplantsButton12 = new QPushButton(this);
    setplantsButton12->setParent(this);
    setplantsButton12->setText(tr("update++"));
    setplantsButton12->setFixedSize(100,30);
    setplantsButton12->move(200,170);
    connect( setplantsButton12, &QPushButton::clicked, this, &Stage::set_plants12);

    QPushButton *setplantsButton2  = new QPushButton(this);
    setplantsButton2->setParent(this);
    setplantsButton2->setText(tr("plant here"));
    setplantsButton2->setFixedSize(100,100);
    setplantsButton2->move(200,200);
    connect( setplantsButton2, &QPushButton::clicked, this, &Stage::set_plants2);
    QPushButton *setplantsButton21  = new QPushButton(this);
    setplantsButton21->setParent(this);
    setplantsButton21->setText(tr("update"));
    setplantsButton21->setFixedSize(100,30);
    setplantsButton21->move(200,200);
    connect( setplantsButton21, &QPushButton::clicked, this, &Stage::set_plants21);
    QPushButton *setplantsButton22  = new QPushButton(this);
    setplantsButton22->setParent(this);
    setplantsButton22->setText(tr("update++"));
    setplantsButton22->setFixedSize(100,30);
    setplantsButton22->move(200,270);
    connect( setplantsButton22, &QPushButton::clicked, this, &Stage::set_plants22);

    QPushButton *setplantsButton3  = new QPushButton(this);
    setplantsButton3->setParent(this);
    setplantsButton3->setText(tr("plant here"));
    setplantsButton3->setFixedSize(100,100);
    setplantsButton3->move(200,300);
    connect( setplantsButton3, &QPushButton::clicked, this, &Stage::set_plants3);
    QPushButton *setplantsButton31  = new QPushButton(this);
    setplantsButton31->setParent(this);
    setplantsButton31->setText(tr("update"));
    setplantsButton31->setFixedSize(100,30);
    setplantsButton31->move(200,300);
    connect( setplantsButton31, &QPushButton::clicked, this, &Stage::set_plants31);
    QPushButton *setplantsButton32  = new QPushButton(this);
    setplantsButton32->setParent(this);
    setplantsButton32->setText(tr("update++"));
    setplantsButton32->setFixedSize(100,30);
    setplantsButton32->move(200,370);
    connect( setplantsButton32, &QPushButton::clicked, this, &Stage::set_plants32);

    QPushButton *setplantsButton4 = new QPushButton(this);
    setplantsButton4->setParent(this);
    setplantsButton4->setText(tr("plant here"));
    setplantsButton4->setFixedSize(100,100);
    setplantsButton4->move(200,400);
    connect( setplantsButton4, &QPushButton::clicked, this, &Stage::set_plants4);
    QPushButton *setplantsButton41 = new QPushButton(this);
    setplantsButton41->setParent(this);
    setplantsButton41->setText(tr("update"));
    setplantsButton41->setFixedSize(100,30);
    setplantsButton41->move(200,400);
    connect( setplantsButton41, &QPushButton::clicked, this, &Stage::set_plants41);
    QPushButton *setplantsButton42 = new QPushButton(this);
    setplantsButton42->setParent(this);
    setplantsButton42->setText(tr("update++"));
    setplantsButton42->setFixedSize(100,30);
    setplantsButton42->move(200,470);
    connect( setplantsButton42, &QPushButton::clicked, this, &Stage::set_plants42);


    QPushButton *setplantsButton5  = new QPushButton(this);
    setplantsButton5->setParent(this);
    setplantsButton5->setText(tr("plant here"));
    setplantsButton5->setFixedSize(100,100);
    setplantsButton5->move(200,500);
    connect( setplantsButton5, &QPushButton::clicked, this, &Stage::set_plants5);
    QPushButton *setplantsButton51  = new QPushButton(this);
    setplantsButton51->setParent(this);
    setplantsButton51->setText(tr("update"));
    setplantsButton51->setFixedSize(100,30);
    setplantsButton51->move(200,500);
    connect( setplantsButton51, &QPushButton::clicked, this, &Stage::set_plants51);
    QPushButton *setplantsButton52  = new QPushButton(this);
    setplantsButton52->setParent(this);
    setplantsButton52->setText(tr("update++"));
    setplantsButton52->setFixedSize(100,30);
    setplantsButton52->move(200,570);
    connect( setplantsButton52, &QPushButton::clicked, this, &Stage::set_plants52);

    QPushButton *setplantsButton6  = new QPushButton(this);
    setplantsButton6->setParent(this);
    setplantsButton6->setText(tr("plant here"));
    setplantsButton6->setFixedSize(100,100);
    setplantsButton6->move(200,600);
    connect( setplantsButton6, &QPushButton::clicked, this, &Stage::set_plants6);
    QPushButton *setplantsButton61  = new QPushButton(this);
    setplantsButton61->setParent(this);
    setplantsButton61->setText(tr("update"));
    setplantsButton61->setFixedSize(100,30);
    setplantsButton61->move(200,600);
    connect( setplantsButton61, &QPushButton::clicked, this, &Stage::set_plants61);
    QPushButton *setplantsButton62 = new QPushButton(this);
    setplantsButton62->setParent(this);
    setplantsButton62->setText(tr("update++"));
    setplantsButton62->setFixedSize(100,30);
    setplantsButton62->move(200,670);
    connect( setplantsButton62, &QPushButton::clicked, this, &Stage::set_plants62);

    _game.initWorld("");
    this->setFixedSize(1800,900);
    this->setWindowFlags(Qt::SubWindow);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(randomMove()));
        //randomMove()为自定义槽函数

    timer->start(50);
    timer->setInterval(500);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机种子
}

Stage::~Stage()
{
    //delete ui;
}

void Stage::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);

    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);

    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);

    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);

    }
    this->repaint();
}

void Stage::randomMove(){

    int d = 1 + rand()%3;//生成随机运动的方向
    this->_game.handlePlayerMove(d,1);
    this->repaint();
}



