#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include "ghost.h"
#include "pacman.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QTimer *timer = new QTimer(this);
    Pacman pacman;
    GameObj* gameObj[5];
    int sec = 0;
    QPixmap picture[9];
    QVector<QLabel*> point;
    QLabel* gObj[5];
    bool isPlay;
private slots:
    void update();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
