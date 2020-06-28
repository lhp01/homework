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
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
   // void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家

    //void eraseObj(int x, int y);

    //static plant_information plant_information_table[10];
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
    //vector<RPGObj *> _objs;
    QMediaPlayer * player;
    //Player *_player;
    QPainter* painter;
};

#endif // WORLD_H
