#ifndef PLANTS_H
#define PLANTS_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
class plants : public QObject
{
    Q_OBJECT
public:
    plants(QPoint pos,QString pixFileName);
    void draw(QPainter *painter);
    void attack();//创造一个类似于僵尸的豌豆对象，仿照僵尸的移动进行单向移动。同时改变僵尸的定义，每次移动后更新每一行最靠前的僵尸的坐标（简单粗暴的全局变量即可，或面向对象）
    //然后豌豆对象每次移动对比该行僵尸位置，当坐标差变符号时销毁对象，僵尸掉血
    //定时功能已完成
private:
    QPoint _pos;
    QPixmap pixmap;
signals:

};

#endif // PLANTS_H
