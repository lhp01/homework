#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
class Pushbutton : public QPushButton
{
public:
    Pushbutton();
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
private:
    int originX;
    int originY;
};

#endif // PUSHBUTTON_H
