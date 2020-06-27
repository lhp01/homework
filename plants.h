#ifndef PLANTS_H
#define PLANTS_H

#include <QObject>
#include <QPoint>
#include "world.h"
#include <QPixmap>
#include <QPainter>
#include <QTimer>
class World;
class plant_information
{
public:
    int index;
    int damage;
    int attack_times;
    int level_up_index;
};

class plants : public RPGObj
{
public:
    plants():RPGObj(){}
    plants(QPoint pos,QString pixFileName);
    void draw(QPainter *painter);

    int index;
    int damage();
    int attack_times();
    int level_up_index();


private:

    QPoint _pos;
    QPixmap pixmap;


};

class plant_attack :public RPGObj
{
public:
    int index;
    plant_attack(int id) :index(id){_hp=1;}
    int damage();
};

#endif // PLANTS_H
