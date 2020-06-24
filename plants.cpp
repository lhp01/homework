#include "plants.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
plants::plants(QPoint pos,QString pixFileName):QObject(0),pixmap(pixFileName)
{
    _pos=pos;
    QTimer * t = new QTimer(this);

    t->start(1000);//改时间来改变发射频率

}
void plants::draw(QPainter* painter){
    painter->drawPixmap(_pos,pixmap);
}

