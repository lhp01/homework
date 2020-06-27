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
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}

    bool canCover() const{return this->_coverable;}
    bool canEat() const{return this->_eatable;}

    int getNextX(int direction);
    int getNextY(int direction);
    int hp(){return _hp;}
    void lose_hp(int damage ){_hp -= damage;}
    bool die(){ return _hp <= 0 ? 1 : 0;}
    virtual void onErase();

    string getObjType() const{return this->_icon.getTypeName();}//返回类名

protected:
    //所有坐标，单位均为游戏中的格

    int gSize;
    int _pixel_x, _pixel_y;

    QImage _pic;

    int _hp;
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    bool _coverable;
    bool _eatable;
};

#endif // RPGOBJ_H
