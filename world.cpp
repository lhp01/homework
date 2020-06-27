#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
using namespace std;
plant_information World::plant_information_table[10] = {{0,20,1,1},{1,20,2,2},{2,20,4,-1}};
World::World():phase(0),peroid(100),plant_attack_time(50),zombie_move_time(50),painter(0),line(6),times(0)
{

}

World::~World(){
    //delete this->_player;
    delete this->player;
    update_timer->stop();
    for(int i = 0; i<line;++i)
    {
        for(auto plant: plant_list[i])
        {
            delete plant;
        }
        for(auto zombie : zombie_list[i])
        {
            delete zombie;
        }
        for(auto attack : attack_list[i])
        {
            delete attack;
        }
    }

}

void World::initWorld(string mapFile){
    update_timer = new QTimer(this);
    connect( update_timer, &QTimer::timeout, this, &World::update_signal );
    update_timer->start(20);//周期的单位为10ms

    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/beijing.mp3"));
    player->setVolume(30);
    player->play();
qDebug()<<"here";

}

void World::update_map(QPainter* pa)
{

    painter = pa;
          ++phase;
    if(phase == 99)
    {
        ++times;
       }
        if( phase == peroid )
        {
             phase = 0;
        }
        if( phase < plant_attack_time )
        {
              generate_attack();
        }

        generate_zombie();
        for(int i = 0; i<line;++i)
        {
            for(auto plant: plant_list[i])
            {
                plant->show(pa);
            }
            for(auto zombie : zombie_list[i])
            {
                zombie->show(pa);
            }
            for(auto attack : attack_list[i])
            {
                attack->show(pa);
            }
        }

        move_attack();

        if( phase < zombie_move_time )
        {
            move_zombie();
        }
//qDebug()<<phase;
        check_plant_attack();
        check_zombie_attack();//qDebug()<<"1";
        check_die();

        for( int i = 0; i < line;++i)
        {
            for(auto zombie:zombie_list[i])
            {
                if(zombie->posX()<=0)
                {
                    QMessageBox::information(NULL, tr("提示"), tr("你输了"));
                    emit this->reChooseSignal();
                    return;
                }
            }
        }

    if(times >= 1000)
    {
        QMessageBox::information(NULL, tr("提示"),tr("你赢了"));
        emit this->reChooseSignal();
    }
}

void World::generate_attack()
{
    for(int i = 0; i < line; ++i )
    {
        if(zombie_list[i].size() == 0 )
        {
            continue;
        }
        for(auto plant: plant_list[i])
        {

            /*if(plant->attack_times() == 0 )
            {
                continue;
            }
            if(!phase%(peroid/plant->attack_times()) == 0 )*/
            if(phase == 10)
            {
                plant_attack *attack = new plant_attack(plant->index);
                attack_list[i].push_back(attack);
                attack->initObj("stone");


                attack->setPixelX(plant->pixelX()+ICON::GRID_SIZE/2);
                attack->setPixelY(plant->pixelY()+ICON::GRID_SIZE/2);
                //attack->show(painter);
            }
        }
    }
}
bool World::generate_plant(int x,int y)
{

    if( y < 1 || y > line)
    {
        return false;
    }
    if( x < 3 || x >= 12)
        return false;

    for(auto plant : plant_list[y-1])
    {
        if( plant->posX() == x*2 )
        {
            return false;
        }
    }
    plants* new_plant = new plants;
    new_plant->initObj("stone");
    new_plant->setPosX(x*2);
    new_plant->setPosY(y*2);
    plant_list[y-1].push_back(new_plant);
    qDebug()<<"hello"<<x<<" "<<y;
    return true;
}
void World::generate_zombie()
{
    if(phase == 1)
    for( int i = 0; i < line; ++i )
    {
        /*if(plant_list[i].length() == 0)
        {
        plants * plant = new plants;
        plant->initObj("stone");
        plant->initObj("stone");
        plant->setPosX(5);
        plant->setPosY(i*2+2);
        plant_list[i].push_back(plant);
        }*/
        RPGObj * zombie = new RPGObj;
        zombie->initObj("player");
        zombie->setPosX(24);
        zombie->setPosY(i*2+2);
        zombie_list[i].push_back(zombie);
    }
}
void World::check_plant_attack()
{
    for( int i = 0; i < line; ++i )
    {
        if(attack_list[i].length() == 0)
        {
            continue;
        }
        if( zombie_list[i].length() == 0)
        {
            continue;
        }
        if(attack_list[i].at(0)->pixelX() >= zombie_list[i].at(0)->pixelX())
        {
            //zombie_list[i].at(0)->lose_hp(attack_list[i].at(0)->damage());
            zombie_list[i].at(0)->lose_hp(40);
            attack_list[i].at(0)->lose_hp(attack_list[i].at(0)->hp());
        }
    }
}
void World::check_zombie_attack()
{
    if(phase == 20||phase == 70)
    for(int i = 0; i < line; ++i )
    {
        if(zombie_list[i].size() == 0)
        {
            continue;
        }
        int max = 0;
        for( auto plant:plant_list[i])
        {
            max = plant->pixelX()>max?plant->pixelX():max;
        }
        if(zombie_list[i].at(0)->pixelX() - max <= ICON::GRID_SIZE/2)
        {
            plant_list[i].at(0)->lose_hp(10);
        }
    }
}

void World::check_die()
{
    for( int i= 0; i <line;++i)
    {
        if(attack_list[i].length()>0)
            if(attack_list[i].at(0)->die())
            {
                delete attack_list[i].at(0);
                attack_list[i].removeAt(0);
            }
        if(zombie_list[i].length()>0)
            if(zombie_list[i].at(0)->die())
            {
                delete zombie_list[i].at(0);
                zombie_list[i].removeAt(0);
            }
        if(plant_list[i].length()>0)
            if(plant_list[i].at(0)->die())
            {
                delete plant_list[i].at(0);
                plant_list[i].removeAt(0);
            }
    }
}
void World::move_attack()
{
    for( int i = 0; i < line; ++i )
    {
        for( auto attack:attack_list[i])
        {
            attack->setPixelX(attack->pixelX()+5);
            //attack->show(painter);
        }
    }
}
void World::move_zombie()
{
    for( int i = 0; i < line; ++i )
    {
        for( auto zombie:zombie_list[i])
        {
            int max = 0;
            for( auto plant:plant_list[i])
            {
                max = plant->pixelX()>max?plant->pixelX():max;
            }
            if( zombie->pixelX() - max > ICON::GRID_SIZE/2)
            {
                zombie->setPixelX(zombie->pixelX()-1);
                zombie->show(painter);
            }
        }
    }
}
void World::show(QPainter * pa){
    /*if( this->painter ==  NULL )
    {
        this->painter = pa;

    }*/
    QImage image(":pics/bj.jpg");
    pa->drawImage(0,0,image);
    update_map(pa);
    //int n = this->_objs.size();
    //for (int i=0;i<n;i++){
      //  this->_objs[i]->show(painter);
    //}
    //this->_player->show(painter);



}

void World::eraseObj(int x, int y){
    vector<RPGObj*>::iterator it;
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()!="stone");
        int flag2 = ((*it)->posX() == x) && ((*it)->posY()==y);

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

