#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include<iostream>
using namespace std;

World::~World(){
    delete this->_player;
}

void World::initWorld(string mapFile){
    //player 5 5
    this->_player->initObj("player");
    this->_player->setPosX(16);
    this->_player->setPosY(7);

    RPGObj *p1 = new RPGObj;
    p1->initObj("stone");
    p1->setPosX(7);
    p1->setPosY(4);

    RPGObj *p21 = new RPGObj;
    p21->initObj("stone");
    p21->setPosX(7);
    p21->setPosY(7);

    RPGObj *p22 = new RPGObj;
    p22->initObj("stone");
    p22->setPosX(7);
    p22->setPosY(10);

    RPGObj *p23 = new RPGObj;
    p23->initObj("stone");
    p23->setPosX(7);
    p23->setPosY(13);

    RPGObj *p24 = new RPGObj;
    p24->initObj("stone");
    p24->setPosX(7);
    p24->setPosY(13);

    RPGObj *p25= new RPGObj;
    p25->initObj("stone");
    p25->setPosX(7);
    p25->setPosY(16);

    RPGObj *p20= new RPGObj;
    p20->initObj("stone");
    p20->setPosX(7);
    p20->setPosY(1);
    RPGObj *p30 = new Fruit;
    p30->initObj("fruit");
    p30->setPosX(4);
    p30->setPosY(1);
    RPGObj *p31 = new Fruit;
    p31->initObj("fruit");
    p31->setPosX(4);
    p31->setPosY(4);

    RPGObj *p32 = new Fruit;
    p32->initObj("fruit");
    p32->setPosX(4);
    p32->setPosY(7);

    RPGObj *p33 = new Fruit;
    p33->initObj("fruit");
    p33->setPosX(4);
    p33->setPosY(10);
    RPGObj *p34 = new Fruit;
    p34->initObj("fruit");
    p34->setPosX(4);
    p34->setPosY(13);
    RPGObj *p35 = new Fruit;
    p35->initObj("fruit");
    p35->setPosX(4);
    p35->setPosY(16);
    this->_objs.push_back(p1);
    this->_objs.push_back(p20);
    this->_objs.push_back(p22);
    this->_objs.push_back(p23);
    this->_objs.push_back(p24);
    this->_objs.push_back(p25);
    this->_objs.push_back(p21);
    this->_objs.push_back(p31);
    this->_objs.push_back(p32);
    this->_objs.push_back(p33);
    this->_objs.push_back(p35);
    this->_objs.push_back(p34);
     this->_objs.push_back(p30);
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/beijing.mp3"));
    player->setVolume(30);
    player->play();


}


void World::show(QPainter * painter){
    QImage image(":pics/bj.jpg");
    painter->drawImage(0,0,image);
    int n = this->_objs.size();
    for (int i=0;i<n;i++){
        this->_objs[i]->show(painter);
    }
    this->_player->show(painter);



}

void World::eraseObj(int x, int y){
    vector<RPGObj*>::iterator it;
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()!="stone");
        int flag2 = ((*it)->getPosX() == x) && ((*it)->getPosY()==y);

        if (flag1 && flag2){
            cout<<(*it)->getObjType()<<endl;
            (*it)->onErase();
            delete (*it);
            it = this->_objs.erase(it);
            break;
         }
        else{
            it++;
        }
    }

}

void World::handlePlayerMove(int direction, int steps){
    int x = this->_player->getNextX(direction);
    int y = this->_player->getNextY(direction);
    this->eraseObj(x,y);
    this->_player->move(direction, steps);
}

