#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QMediaPlayer>
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
using namespace std;
class RPGObj
{
public:


    RPGObj();
    RPGObj(QString);

    void initObj(string type);
    void show(QPainter * painter);

    void setPosX(int x){ _pixel_x = x * gSize;}
    void setPixelX(int x){ _pixel_x = x; }
    void setPixelY(int y){_pixel_y = y;}
    void setPosY(int y){ _pixel_y = y * gSize;}

    int posX() const{return _pixel_x/gSize;}
    int posY() const{return _pixel_y/gSize;}
    int pixelX() const{return  _pixel_x;}
    int pixelY() const{return  _pixel_y;}
    int hp(){return _hp;}
    void lose_hp(int damage ){_hp -= damage;}
    bool die(){ return _hp <= 0 ? 1 : 0;}
    int damage;
    int attack_times;
    QString pic_name;
protected:
    int gSize;
    int _pixel_x, _pixel_y;
    QImage _pic;
    int _hp;
    ICON _icon;
};

#endif // RPGOBJ_H
