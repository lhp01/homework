#ifndef WORLD_H
#define WORLD_H

#include "rpgobj.h"
#include <QVector>
#include <vector>
#include <string>
#include <QPainter>
#include <QTimer>
#include <QMediaPlayer>
#include <QObject>
class plant_information;
class plants;
class plant_attack;
class World : public QObject
{
    Q_OBJECT


public:
    World();
    ~World();
    void initWorld();
    void show(QPainter * painter);
    bool generate_plant(int x, int y);
    void update_map(QPainter *pa);
    int over;
    int gold;
signals:
    void update_signal();
    void reChooseSignal();

protected:


    void generate_attack();
    void generate_zombie();
    void move_attack();
    void move_zombie();
    void check_plant_attack();
    void check_zombie_attack();
    void check_die();

private:

    QList<RPGObj *> zombie_list[6];
    QList<RPGObj *> plant_list[6];
    QList<RPGObj *> attack_list[6];
    QTimer * update_timer;

    int line;
    int phase;
    int peroid;
    int plant_attack_time;
    int zombie_move_time;
    int times;
    QMediaPlayer * player;
    QPainter* painter;
};

#endif // WORLD_H
