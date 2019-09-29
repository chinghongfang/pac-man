#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
// done
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    point(924),isPlay(false)
{
    ui->setupUi(this);
    gameObj[0] = &pacman;
    gameObj[1] = new Blinky(gameObj[0],1);
    gameObj[2] = new Pinky(gameObj[0],1);
    gameObj[3] = new Inky(gameObj[0],gameObj[1],1);
    gameObj[4] = new Clyde(gameObj[0],1);

    timer->setInterval(10);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    QLabel* back = new QLabel("background",ui->widget);
    back->setGeometry(0,0,448,576);
    back->setPixmap(QPixmap(":/new/pic/src/map2.png"));

    picture[0] = QPixmap(":/new/pic/src/no.png");       // map object
    picture[1] = QPixmap(":/new/pic/src/point2.png");
    picture[2] = QPixmap(":/new/pic/src/Power2.png");
    picture[3] = QPixmap(":/new/pic/src/man2.png");     // game object
    picture[4] = QPixmap(":/new/pic/src/Blinky2.png");
    picture[5] = QPixmap(":/new/pic/src/Pinky2.png");
    picture[6] = QPixmap(":/new/pic/src/Inky2.png");
    picture[7] = QPixmap(":/new/pic/src/Clyde2.png");
    picture[8] = QPixmap(":/new/pic/src/fright2.png");

    for (int i=0; i<33; ++i){           // map initialize
        for (int j = 0; j<28; ++j){
            point[i*28+j] = new QLabel(
                        QString().sprintf("pt%d",i*28+j),ui->widget);
            point[i*28+j]->setGeometry(j*16,i*16+48,16,16);
            if (pacman.map[i*28+j] == 1){
                point[i*28+j]->setPixmap(picture[1]);
            }else if (pacman.map[i*28+j] == 3){
                point[i*28+j]->setPixmap(picture[2]);
            }else{
                point[i*28+j]->setPixmap(picture[0]);
            }
        }
    }
qDebug()<<"1";
    gObj[0] = new QLabel("man",ui->widget);
    gObj[1] = new QLabel("Blinky",ui->widget);
    gObj[2] = new QLabel("Pinky",ui->widget);
    gObj[3] = new QLabel("Inky",ui->widget);
    gObj[4] = new QLabel("Clyde",ui->widget);

    for (int i = 0; i<5; ++i){
        int x,y;
        y = gameObj[i]->getLocate(0)*16-6+48;
        x = gameObj[i]->getLocate(1)*16-6;
        switch (gameObj[i]->getDirection()){
        case 1: y -= gameObj[i]->getStep()*2;break;
        case 2: x += gameObj[i]->getStep()*2;break;
        case 3: y += gameObj[i]->getStep()*2;break;
        case 4: x -= gameObj[i]->getStep()*2;break;
        }
        if (i == 0){gObj[i]->setGeometry(x,y,26,26);}
        else{gObj[i]->setGeometry(x,y,28,28);}
        gObj[i]->setPixmap(picture[gameObj[i]->getLook()+3]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update(){
    if (!isPlay) return;
    for (int i = 0; i<5; ++i){
        gameObj[i]->move();
    }
    for (int i = 0; i<5; ++i){
        int x,y;
        y = gameObj[i]->getLocate(0)*16-6+48;
        x = gameObj[i]->getLocate(1)*16-6;
        switch (gameObj[i]->getDirection()){
        case 1: y -= gameObj[i]->getStep()*2;break;
        case 2: x += gameObj[i]->getStep()*2;break;
        case 3: y += gameObj[i]->getStep()*2;break;
        case 4: x -= gameObj[i]->getStep()*2;break;
        }
        if (i == 0){gObj[i]->setGeometry(x,y,26,26);}
        else{
            gObj[i]->setGeometry(x,y,28,28);
            if (gameObj[i]->getLook()==-1){
                gObj[i]->setPixmap(picture[8]);
            }
            else{
                gObj[i]->setPixmap(picture[gameObj[i]->getLook()+3]);
            }
        }
    }
    if (pacman.eatPos){         // not so good...(0 can be a position..)
        point[pacman.eatPos]->setPixmap(picture[0]);
    }
    if (pacman.getPower() == 1){
        for (int i = 1; i<5; ++i){
            gameObj[i]->setLook(-1);
        }
    }else if (pacman.getPower() == 2){
        for (int i = 1; i<5; ++i){
            gameObj[i]->die(0);
        }
    }
    for (int i = 1; i<5; ++i){
        if (gameObj[0]->getLocate(0) == gameObj[i]->getLocate(0)    // die
                && gameObj[0]->getLocate(1) == gameObj[i]->getLocate(1)){
            if (gameObj[i]->getLook()>0) gameObj[0]->die(1);
            else if (gameObj[i]->getLook()<0) gameObj[i]->die(1);
        }
    }
    ui->label->setText(QString().sprintf("%d",pacman.getEaten()));
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up){
        if (gameObj[0]->getDirection()!=1)
        pacman.changeDir(1);
    }else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right){
        if (gameObj[0]->getDirection()!=2)
        pacman.changeDir(2);
    }else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down){
        if (gameObj[0]->getDirection()!=3)
        pacman.changeDir(3);
    }else if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left){
        if (gameObj[0]->getDirection()!=4)
        pacman.changeDir(4);
    }else if (event->key() == Qt::Key_B){
        isPlay = !isPlay;
    }
}
