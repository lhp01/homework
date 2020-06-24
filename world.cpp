#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include <iostream>
using namespace std;

World::~World(){
    delete this->_player;
}

void World::initWorld(string mapFile){
    player = new QMediaPlayer;
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

