#include "ghost.h"
#include <QDebug>
Ghost::Ghost(){
    int tmp[924] =
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,2,1,1,1,1,2,1,1,1,1,1,2,0,0,2,1,1,1,1,1,2,1,1,1,1,2,0,
            0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
            0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
            0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
            0,2,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,2,0,
            0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
            0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
            0,2,1,1,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,1,1,2,0,
            0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,2,1,1,2,1,1,2,1,1,2,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
            1,1,1,1,1,1,2,1,1,2,0,1,1,1,1,1,1,0,2,1,1,2,1,1,1,1,1,1,
            0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,2,1,1,1,1,1,1,1,1,2,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
            0,2,1,1,1,1,2,1,1,2,1,1,2,0,0,2,1,1,2,1,1,2,1,1,1,1,2,0,
            0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
            0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
            0,2,1,2,0,0,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,0,0,2,1,2,0,
            0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
            0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
            0,2,1,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,1,2,0,
            0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
            0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
            0,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i<924; ++i){
        map[i] = tmp[i];
    }
    movespeed = 3;
    locate[0] = 11;  locate[1] = 13;
    direction = 4;
    scatterMode = 1;
    step = 0;
    frightTimer = 0;
    frightTime = 850;
    isfright = 0;
}
Ghost::~Ghost(){}
void Ghost::move(){
    if (speedTimer<movespeed){
        ++timer;
        ++speedTimer;
        return;         // because you are too slow to move!!
    }
    if (looklike < 0){
        fright();
    }else if (timer <= 700){
        scatter();
    }else if (2700 < timer && timer <= 3400){
        scatter();
    }else if (5400 < timer && timer <= 5900){
        scatter();
    }else if (7900 < timer && timer <= 8400){
        scatter();
    }else{
        if (step == 0 && map[locate[0]*28+locate[1]] == 2)  // can turn
        chase();
    }               // set destination(direction)
    ++timer;
    if (timer>2100000000){timer = 0;}
    if (step == 4){     // to step in a new block
        switch (direction)
        {
        case 0:
            break;
        case 1:
            locate[0]-=1;
            break;
        case 2:
            (locate[1]+1>27) ? locate[1]=0 : locate[1]+=1;
            break;
        case 3:
            locate[0]+=1;
            break;
        case 4:
            (locate[1]-1<0) ? locate[1]=27 : locate[1]-=1;
            break;
        }
        step = -3;
    }else{
        ++step;
    }
    speedTimer = 0;
}
void Ghost::die(int in){
    looklike = 1;
    if (in == 1){
        locate[0] = 11;  locate[1] = 13;
        direction = 4;
    }
    frightTimer = 0;
    isfright = 0;
}
void Ghost::scatter(){
    looklike = scatterMode;
    switch (scatterMode){
    case 1:
        destination[0] = 1;
        destination[1] = 26;
        break;
    case 2:
        destination[0] = 1;
        destination[1] = 1;
        break;
    case 3:
        destination[0] = 31;
        destination[1] = 26;
        break;
    case 4:
        destination[0] = 31;
        destination[1] = 1;
        break;
    case 0:
        break;
    }
    findDir();
};
void Ghost::fright(){
    if (isfright == 0){
        ++isfright;
        switch(direction){
        case 1: direction = 3;break;
        case 2: direction = 4;break;
        case 3: direction = 1;break;
        case 4: direction = 2;break;
        }
        while (true){       // this code is dangerous
            if (direction==1 && !map[locate[0]*28-28+locate[1]]){++direction;}
            else{if (direction==1)break;}
            if (direction==2 && locate[1]<27 &&
                    !map[locate[0]*28+1+locate[1]]){++direction;}
            else{if (direction==2)break;}
            if (direction==3 && !map[locate[0]*28+28+locate[1]]){++direction;}
            else{if (direction==3)break;}
            if (direction==4 && locate[1]>0 &&
                    !map[locate[0]*28-1+locate[1]]){direction = 1;}
            else{if (direction==4)break;}
        }
        step = -1;
    }else if (isfright == 1){
        if (step == 0 && map[locate[0]*28+locate[1]] == 2){ // can turn
            int tmpdir = qrand()%4;
            //qDebug()<<"start"<<tmpdir;
            while (true){
                if (tmpdir==0 && !map[locate[0]*28-28+locate[1]]){++tmpdir;}
                else{if (tmpdir == 0)break;}
                if (tmpdir==1 && locate[1]<27 &&
                        !map[locate[0]*28+1+locate[1]]){++tmpdir;}
                else{if (tmpdir == 1)break;}
                if (tmpdir==2 && !map[locate[0]*28+28+locate[1]]){++tmpdir;}
                else{if (tmpdir == 2)break;}
                if (tmpdir==3 && locate[1]>0 &&
                        !map[locate[0]*28-1+locate[1]]){tmpdir = 0;}
                else{if (tmpdir == 3)break;}
            }
            direction = tmpdir+1;
        }
    }
};
void Ghost::chase(){        // defult ghost: "Blinky"
    looklike = scatterMode;
    destination[0] = target->getLocate(0);
    destination[1] = target->getLocate(1);
    findDir();
}
void Ghost::findDir(){
    if (step!=0) {return;}
    int distance[4] = {0,0,0,0};        // ^ -> v <-
    distance[0] = (locate[0]-1-destination[0])*(locate[0]-1-destination[0])
            +(locate[1]-destination[1])*(locate[1]-destination[1]);
    distance[1] = (locate[0]-destination[0])*(locate[0]-destination[0])
            +(locate[1]+1-destination[1])*(locate[1]+1-destination[1]);
    distance[2] = (locate[0]+1-destination[0])*(locate[0]+1-destination[0])
            +(locate[1]-destination[1])*(locate[1]-destination[1]);
    distance[3] = (locate[0]-destination[0])*(locate[0]-destination[0])
            +(locate[1]-1-destination[1])*(locate[1]-1-destination[1]);
    switch (direction)      // where you come from
    {
    case 0:
        break;
    case 1:
        distance[2]=26962;      // 28^2 + 33^2 = 26961
        break;
    case 2:
        distance[3]=26962;
        break;
    case 3:
        distance[0]=26962;
        break;
    case 4:
        distance[1]=26962;
        break;
    }
    if (!map[locate[0]*28-28+locate[1]]){distance[0]=26962;}    // wall
    if (locate[1]<27&&!map[locate[0]*28+locate[1]+1])  // not tunnel
        {distance[1]=26962;}
    if (!map[locate[0]*28+28+locate[1]]){distance[2]=26962;}
    if (locate[1]>0&&!map[locate[0]*28+locate[1]-1])
        {distance[3]=26962;}
    int tmp = 0;
    for (int i=1; i<4; ++i){
        if (distance[i]<distance[tmp]) tmp = i;
    }
    direction = tmp+1;
};

Blinky::Blinky(GameObj* tar,int look = 1){
    target = tar;
    looklike = look;
    scatterMode = 1;
}
Blinky::~Blinky(){}
void Blinky::die(int in){
    looklike = 1;
    if (in == 1){
        locate[0] = 11;  locate[1] = 13;
        direction = 4;
    }
    frightTimer = 0;
    isfright = 0;
}
Pinky::Pinky(GameObj* tar,int look = 2){
    target = tar;
    looklike = look;
    scatterMode = 2;
}
Pinky::~Pinky(){};
void Pinky::chase(){
    looklike = scatterMode;
    int x,y;
    y = target->getLocate(0);
    x = target->getLocate(1);
    switch (target->getDirection()){
    case 1:
        y = y-4;
        break;
    case 2:
        x = x+4;
        break;
    case 3:
        y = y+4;
        break;
    case 4:
        x = x-4;
        break;
    case 0:
        break;
    }
    destination[0] = y;
    destination[1] = x;
    findDir();
}
void Pinky::die(int in){
    looklike = 2;
    if (in == 1){
        locate[0] = 11;  locate[1] = 13;
        direction = 4;
    }
    frightTimer = 0;
    isfright = 0;
}

Inky::Inky(GameObj* tar, GameObj* blink, int in){
    target = tar;
    blinky = blink;
    looklike = in;
    scatterMode = 3;
}
Inky::~Inky(){}
void Inky::chase(){
    looklike = scatterMode;
    int tarx,tary,bx,by;
    tary = target->getLocate(0);
    tarx = target->getLocate(1);
    bx = target->getLocate(0);
    by = target->getLocate(1);
    switch (target->getDirection()){
    case 1:
        tary = 2*tary-by-4;
        tarx = 2*tarx-bx;
        break;
    case 2:
        tarx = 2*tarx-bx+4;
        tary = 2*tary-by;
        break;
    case 3:
        tary = 2*tary-by+4;
        tarx = 2*tarx-bx;
        break;
    case 4:
        tarx = 2*tarx-bx-4;
        tary = 2*tary-by;
        break;
    case 0:
        break;
    }
    destination[0] = tary;
    destination[1] = tarx;
    findDir();
}
void Inky::die(int in){
    looklike = 3;
    if (in == 1){
        locate[0] = 11;  locate[1] = 13;
        direction = 2;
    }
    frightTimer = 0;
    isfright = 0;
}

Clyde::Clyde(GameObj* tar,int look){
    target = tar;
    looklike = look;
    scatterMode = 4;
}
Clyde::~Clyde(){}
void Clyde::chase(){
    int x,y;
    y = target->getLocate(0)-locate[0];
    x = target->getLocate(1)-locate[1];
    if (x*x+y*y>64){
        destination[0] = target->getLocate(0);
        destination[1] = target->getLocate(1);
        findDir();
    }else{
        scatter();
    }
}
void Clyde::die(int in){
    looklike = 4;
    if (in == 1){
        locate[0] = 11;  locate[1] = 13;
        direction = 2;
    }
    frightTimer = 0;
    isfright = 0;
}
