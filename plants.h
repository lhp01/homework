#ifndef PLANTS_H
#define PLANTS_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
class plants : public QObject
{
    Q_OBJECT
public:
    plants(QPoint pos,QString pixFileName);
    void draw(QPainter *painter);
private:
    QPoint _pos;
    QPixmap pixmap;
signals:

};

#endif // PLANTS_H
