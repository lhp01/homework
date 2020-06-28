#include "stage.h"
//#include "ui_Stage.h"
#include "icon.h"
#include <map>
#include <iostream>
#include "stagechoose.h"

void Stage::paintEvent(QPaintEvent *){
    if(!_game->over)
    {
    QPainter *pa = new QPainter;
    pa->begin(this);

        this->_game->show(pa);
    pa->end();

    }

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
{

    qDebug()<<"stage start";
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
    generatePlantButton->setText(tr("放置/升级植物"));
    connect(generatePlantButton,&QPushButton::clicked,this,[=](){this->generate_plant_mode = true;});

    _game->initWorld();qDebug()<<"stage success";
    this->setFixedSize(1800,900);
    this->setWindowFlags(Qt::SubWindow);

    QLabel * gold_label = new QLabel(this);
    gold_label->setText("金币"+QString::number(_game->gold));
    gold_label->setFixedSize(100,50);
    gold_label->move(0,150);

    over_timer = new QTimer();
    connect(over_timer, &QTimer::timeout, this, [=](){
              gold_label->setText("金币"+QString::number(_game->gold));
            if(_game->over == 1)
            {
                QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl("qrc:/sounds/biu.wav"));
                player->setVolume(30);
                player->play();
                QMessageBox::information(this, tr("提示"), tr("满身疮痍"));
                over_timer->stop();

                emit reChooseSignal();

            }
            else if(_game->over == 2)
            {
                QMediaPlayer *player = new QMediaPlayer;
                player->setMedia(QUrl("qrc:/sounds/spell_clear.wav"));
                player->setVolume(30);
                player->play();
                QMessageBox::information(this, tr("提示"),tr("Stage Cleared"));
                over_timer->stop();
                emit reChooseSignal();
            }

    });
    over_timer->start(3);

    connect( _game, &World::update_signal, this, static_cast<void (Stage::*)()>(&Stage::repaint));

}

Stage::~Stage()
{
    //delete ui;
    delete _game;
}


