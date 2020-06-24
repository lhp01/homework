#ifndef MW1_H
#define MW1_H
#include <QList>
#include "plants.h"
#include <QWidget>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include<QTimer>
#include<QPushButton>
#include "rpgobj.h"
#include "world.h"
/*
namespace Ui {
class MW1;
}
*/

class Stage : public QWidget
{
    Q_OBJECT

public:
    explicit Stage(QWidget *parent = 0);
    ~Stage();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    void set_plants1();
        void set_plants11();
                void set_plants12();
    void set_plants2();
        void set_plants21();
                void set_plants22();
    void set_plants3();
        void set_plants31();
                void set_plants32();
    void set_plants4();
        void set_plants41();
                void set_plants42();
    void set_plants5();
        void set_plants51();
                void set_plants52();
    void set_plants6();
        void set_plants61();
                void set_plants62();
signals:
    void returnSignal();
    void reChooseSignal();
protected slots:
    void randomMove();

private:
    //Ui::MW1 *ui;
    World _game;
    QTimer *timer;
    QList<plants*> plants_list;
        Stage *stage;
};

#endif // MW1_H
