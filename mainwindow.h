#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MYWIDGET_H

