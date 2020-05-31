#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)    :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);}
MainWindow::~MainWindow(){    delete ui;}
void MainWindow::paintEvent(QPaintEvent *)
{   QPainter p(this);
    p.begin(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/pics/bj.jpg"));
}
