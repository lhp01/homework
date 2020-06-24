#include "mybutton.h"
#include <QPixmap>
mybutton::mybutton(QString pix,QWidget *parent) : QPushButton(parent){
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

