#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);
    mybutton(QString pix, QWidget *parent = nullptr);
signals:

public slots:
};

#endif // MYBUTTON_H
