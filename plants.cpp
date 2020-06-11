#include "plants.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
plants::plants(QPoint pos,QString pixFileName):QObject(0),pixmap(pixFileName)
{
 _pos=pos;
}
void plants::draw(QPainter* painter){
    painter->drawPixmap(_pos,pixmap);
}

