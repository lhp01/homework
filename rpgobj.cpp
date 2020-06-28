#include "rpgobj.h"
#include <iostream>

RPGObj::RPGObj(): gSize(ICON::GRID_SIZE)
{}

void RPGObj::initObj(string type)
{
    pic_name = QString::fromStdString(type);
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("player")==0){
        this->_hp = 100;
        this->damage = 20;
        this->attack_times = 2;

    }
    else if (type.compare("stone")==0){
        this->_hp = 100;
        this->damage = 10;
        this->attack_times = 1;


    }
    else if(type.compare("double")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 100;
        this->damage = 10;
        this->attack_times = 2;

        return;
    }
    else if(type.compare("four")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 100;
        this->damage = 10;
        this->attack_times = 4;
        return;
    }
    else if(type.compare("douzi")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 1;
        this->damage = 10;
        this->attack_times = 1;
        return;
    }
    else if(type.compare("leaves")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 100;
        this->damage = 0;
        this->attack_times = 0;
        return;
    }
    else if(type.compare("leaves_s")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 100;
        this->damage = 10;
        this->attack_times = 1;
        return;
    }
    else if(type.compare("leaves_d")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 100;
        this->damage = 10;
        this->attack_times = 2;
        return;
    }
    else if(type.compare("leaves_f")==0)
    {
        this->_pic.load(QString(":/pics/")+pic_name+QString(".png"));
        this->_hp = 100;
        this->damage = 10;
        this->attack_times = 4;
        return;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }

    this->_icon = ICON::findICON(type);
    QImage all;

    all.load(":/pics/renwu.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}


void RPGObj::show(QPainter * pa){

    pa->drawImage(this->_pixel_x,this->_pixel_y,this->_pic);
}
