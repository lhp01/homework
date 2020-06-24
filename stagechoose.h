#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QList>
#include "plants.h"
#include "stage.h"
class StageChoose : public QMainWindow
{
    Q_OBJECT
public:
    explicit StageChoose(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void next_task();
signals:
    void chooseBack();
protected:


private:
    QList<plants*> plants_list;
    Stage *stage;

};

#endif // MYWINDOW_H
