#include "stage.h"
//#include "ui_Stage.h"
#include "icon.h"
#include <QDebug>
#include <map>
#include <iostream>
#include "stagechoose.h"

//using namespace std;

void Stage::paintEvent(QPaintEvent *e){
   /* QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game->show(pa);
    pa->end();
    delete pa;
    QPainter painter(this);
foreach(plants* plants,plants_list)
    plants->draw(&painter);*/
    //if(painter == NULL)
    //{
        //painter = new QPainter(this);
    //}
    QPainter *pa = new QPainter;
    pa->begin(this);
    this->_game->show(pa);
    pa->end();
    //painter->begin(this);
    //this->_game->show(painter);
    //this->_game->update_map();
    //painter->end();
//foreach(plants* plants,plants_list)
  //  plants->draw(&painter);
}
void Stage::mousePressEvent(QMouseEvent *event)
{
    if(this->generate_plant_mode)
    {
        int y = event->y()/50/2;
        int x = event->x()/50/2;
        bool  success = _game->generate_plant(x,y);
        if(success)
            generate_plant_mode = false;
    }
}
Stage::Stage(QWidget *parent) :
    QWidget(parent),generate_plant_mode(0)
    //,ui(new Ui::Stage)
{
    //ui->setupUi(this);

    //init game world
    qDebug()<<"stage start";
    painter = NULL;
    _game = new World;
    connect(_game,&World::reChooseSignal, this, &Stage::reChooseSignal);
    setAttribute(Qt::WA_DeleteOnClose);
    QPushButton *rechooseButton  = new QPushButton(this);
    rechooseButton->setText(tr("重新选择关卡"));
    rechooseButton->setFixedSize(120,50);
    rechooseButton->setParent(this);
    rechooseButton->move(0,0);
    connect( rechooseButton, &QPushButton::clicked, this, &Stage::reChooseSignal);

    QPushButton * returnTitleButton = new QPushButton(this);
    returnTitleButton ->setFixedSize(120,50);
   // returnTitleButton ->setParent(this);
    returnTitleButton ->move(0,50);
    returnTitleButton->setText(tr("返回标题"));
    connect( returnTitleButton, &QPushButton::clicked, this, &Stage::returnSignal);
    QPushButton * generatePlantButton = new QPushButton(this);
    generatePlantButton->setFixedSize(120,50);
    generatePlantButton->move(0,100);
    generatePlantButton->setText(tr("放置植物￥150"));
    connect(generatePlantButton,&QPushButton::clicked,this,[=](){this->generate_plant_mode = true;});

    QPushButton * updatePlantButton = new QPushButton(this);
    updatePlantButton->setFixedSize(120,50);
    updatePlantButton->move(0,150);
    updatePlantButton->setText(tr("升级植物￥300"));
    connect(updatePlantButton,&QPushButton::clicked,this,[=](){this->generate_plant_mode = true;});


    _game->initWorld("");qDebug()<<"stage success";
    this->setFixedSize(1800,900);
    this->setWindowFlags(Qt::SubWindow);
    //timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(randomMove()));
        //randomMove()为自定义槽函数

    //timer->start(3);
    //timer->setInterval(500);

    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机种子


    connect( _game, &World::update_signal, this, static_cast<void (Stage::*)()>(&Stage::repaint));

}

Stage::~Stage()
{
    //delete ui;
    delete _game;
}


