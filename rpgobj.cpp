#include "rpgobj.h"
#include <iostream>

RPGObj::RPGObj(): gSize(ICON::GRID_SIZE),_hp(100)
{}

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("player")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("stone")==0){
        this->_coverable = false;
        this->_eatable = true;
    }
    else if (type.compare("fruit")==0){
        this->_coverable = false;
        this->_eatable = true;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }

    this->_icon = ICON::findICON(type);
    QImage all;

    all.load(":/pics/renwu.jpg");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}


void RPGObj::show(QPainter * pa){

    pa->drawImage(this->_pixel_x,this->_pixel_y,this->_pic);
}

int RPGObj::getNextX(int direction){
    switch (direction){
        case 1:
            return this->posX();
        case 2:
           return this->posY();
        case 3:
           return this->posX()-1;
    }
}

int RPGObj::getNextY(int direction){
    switch (direction){
        case 1:
            return this->posY() - 1;
        case 2:
           return this->posY() + 1;
        case 3:
           return this->posY();
    }
}

void RPGObj::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/jujue.mp3"));
    player->setVolume(30);
    player->play();
}

