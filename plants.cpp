

#include "plants.h"
#include "world.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
plants::plants(QPoint pos,QString pixFileName):pixmap(pixFileName)
{
    _pos=pos;


}
void plants::draw(QPainter* painter){
    painter->drawPixmap(_pos,pixmap);
}


int plants::damage(){return World::plant_information_table[index].damage;}
 int plants::attack_times(){return World::plant_information_table[index].attack_times;}
 int plants::level_up_index(){ return World::plant_information_table[index].level_up_index;}
 int plant_attack::damage(){return World::plant_information_table[index].damage;}
