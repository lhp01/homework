#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QList>
#include "plants.h"
class Mywindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mywindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void set_plants();
private:
    QList<plants*> plants_list;
signals:
    void chooseBack();
};

#endif // MYWINDOW_H
