#ifndef STAGE_H
#define STAGE_H
#include <QList>

#include <QLabel>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include<QTimer>
#include <QTime>
#include<QPushButton>
#include <QMouseEvent>
#include "rpgobj.h"
#include "world.h"
#include <QMessageBox>
class Stage : public QWidget
{
    Q_OBJECT
public:
    Stage(QWidget *parent = 0);
    ~Stage();
    void paintEvent(QPaintEvent *e);
signals:
    void returnSignal();
    void reChooseSignal();
protected slots:
    void mousePressEvent(QMouseEvent *event);
private:
    World *_game;
    QTimer *timer,*over_timer;
    bool generate_plant_mode;
};

#endif // MW1_H
