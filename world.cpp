#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QLabel>
using namespace std;
//plant_information World::plant_information_table[10] = {{0,20,1,1},{1,20,2,2},{2,20,4,-1}};
World::World():over(0),gold(1000),line(6),phase(0),peroid(100),plant_attack_time(50),zombie_move_time(50),times(0),painter(0)
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

void World::initWorld(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    update_timer = new QTimer(this);
    connect( update_timer, &QTimer::timeout, this, &World::update_signal );
    update_timer->start(3);

    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/beijing.mp3"));
    player->setVolume(30);
    player->play();

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

        check_plant_attack();
        check_zombie_attack();
        check_die();

        for( int i = 0; i < line;++i)
        {

            for(auto zombie:zombie_list[i])
            {
                if(zombie->posX()<=0)
                {
                    over = 1;
                    return;
                }
            }
        }

    if(times >= 1000)
    {


        over = 2;

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
            int exist_zombie = 0;
            for( auto zombie:zombie_list[i])
            {
                if( zombie->pixelX()  > plant->pixelX())
                {
                    exist_zombie = 1;
                }
            }
            if(!exist_zombie)
            {
                continue;
            }
            if(phase/10< plant->attack_times && phase/10*10==phase)
            {
                RPGObj *attack = new RPGObj();
                attack_list[i].push_back(attack);
                attack->initObj("douzi");
                //设置attack图片为豌豆

                attack->setPixelX(plant->pixelX()+ICON::GRID_SIZE/2);//待调整
                attack->setPixelY(plant->pixelY()+ICON::GRID_SIZE/2);//待调整
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
qDebug()<<"hello"<<x<<" "<<y;
    for(auto plant : plant_list[y-1])
    {
        if( plant->posX() == x*2 )
        {
            if(plant->pic_name == "leaves")
            {

                plant->initObj("leaves_s");
                gold -= 100;
                return true;
            }
            else if(plant->pic_name == "stone")
            {
                plant->initObj("double");gold -= 100;
                return true;
            }
            else if(plant->pic_name == "double")
            {
                plant->initObj("four");gold -= 100;
                return true;
            }
            else if(plant->pic_name == "leaves_s")
            {
                plant->initObj("leaves_d");gold -= 100;
                return true;
            }
            else if(plant->pic_name == "leaves_d")
            {
                plant->initObj("leaves_f");gold -= 100;
                return true;
            }
            return false;

        }
    }
    RPGObj* new_plant = new RPGObj;
    if( y == 3 || y == 4 )
    {
        new_plant->initObj("leaves");
    }
    else
    {
        new_plant->initObj("stone");
    }
gold -= 100;
    new_plant->setPosX(x*2);
    new_plant->setPosY(y*2);
    plant_list[y-1].push_back(new_plant);

    return true;
}
void World::generate_zombie()
{
    if(phase == 1)
    for( int i = 0; i < line; ++i )
    {if(i==qrand()%6)

        {
        RPGObj * zombie = new RPGObj;
        zombie->initObj("player");
        zombie->setPosX(24);
        zombie->setPosY(i*2+2);
        zombie_list[i].push_back(zombie);
        }
    }
}
void World::check_plant_attack()
{
    for( int i = 0; i < line; ++i )
    {

        for( auto attack: attack_list[i])
        {
            for(auto zombie:zombie_list[i])
            {
                if( attack->pixelX() - zombie->pixelX() <= 6 && attack->pixelX() - zombie->pixelX() >= -6 )
                {
                    zombie->lose_hp(attack->damage);
                    attack->lose_hp(attack->hp());
                    break;
                }
            }
        }


    }
}
void World::check_zombie_attack()
{
    if(phase == 20||phase == 70)
    for(int i = 0; i < line; ++i )
    {
        for(auto zombie : zombie_list[i])
        {
            for( auto plant:plant_list[i])
            {
                if( zombie->pixelX() - plant->pixelX() >=  0 && zombie->pixelX() - plant->pixelX() <=  ICON::GRID_SIZE/2)
                {
                    plant->lose_hp(zombie->damage);
                }
            }
        }
    }
}

void World::check_die()
{
    for( int i= 0; i <line;++i)
    {
        foreach( auto attack, attack_list[i] )
        {
            if(attack->die())
            {
                delete attack;
                attack_list[i].removeOne(attack);
            }
        }
        foreach( auto zombie, zombie_list[i] )
        {
            if(zombie->die())
            {
                gold += 50;
                delete zombie;
                zombie_list[i].removeOne(zombie);
            }
        }
        foreach( auto plant, plant_list[i] )
        {
            if(plant->die())
            {
                delete plant;
                plant_list[i].removeOne(plant);
            }
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
        }
    }
}
void World::move_zombie()
{
    for( int i = 0; i < line; ++i )
    {
        for( auto zombie:zombie_list[i])
        {
            //int max = 0;
            int not_move = 0;
            for( auto plant:plant_list[i])
            {
                if(zombie->pixelX() - plant->pixelX() <= ICON::GRID_SIZE/2 && zombie->pixelX() - plant->pixelX() >= 0 )
                {
                    not_move = 1;
                    break;
                }
            }
            if( !not_move)
            {
                zombie->setPixelX(zombie->pixelX()-1);
                zombie->show(painter);
            }
        }
    }
}
void World::show(QPainter * pa){

    QImage image(":pics/bj.jpg");
    pa->drawImage(0,0,image);
    update_map(pa);

}



