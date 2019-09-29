#include "pacman.h"
#include <QDebug>
Pacman::Pacman()
{
    int tmp[924] = {        // 1: road with point, 2: road, 3: power!!
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
        0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
        0,3,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,3,0,
        0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
        0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
        0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
        2,2,2,2,2,2,1,2,2,2,0,0,0,0,0,0,0,0,2,2,2,1,2,2,2,2,2,2,
        0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,
        0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
        0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
        0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
        0,3,1,1,0,0,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,0,0,1,1,3,0,
        0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
        0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
        0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
        0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
        0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
        0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i<924; ++i){
        map[i] = tmp[i];
    }
    locate[0] = 23;
    locate[1] = 13;
    looklike = 0;
    direction = 4;
    step = -3;
    speedTimer = 0;
    movespeed = 3;
    powerTime = 0;
}
Pacman::~Pacman(){}
void Pacman::move(){
    if (timer == powerTime){powerTime = 0;}
    if (speedTimer<movespeed){
        ++timer;
        ++speedTimer;
        return;         // because you are too slow to move!!
    }
    speedTimer = 0;
    switch (preDir) {
    case 1:
        if (map[locate[0]*28-28+locate[1]]){
            preDir = 0;
            direction = 1;
            step = 3;
        }
        break;
    case 2:
        if (map[locate[0]*28+1+locate[1]]){
            preDir = 0;
            direction = 2;
            step = 3;
        }
        break;
    case 3:
        if (map[locate[0]*28+28+locate[1]]){
            preDir = 0;
            direction = 3;
            step = 3;
        }
        break;
    case 4:
        if (map[locate[0]*28-1+locate[1]]){
            preDir = 0;
            direction = 4;
            step = 3;
        }
        break;
    case 0:
        break;
    }
    if (!direction){return;}
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
        if (map[locate[0]*28+locate[1]] == 1){      // eat
            eatPos = locate[0]*28+locate[1];
            map[locate[0]*28+locate[1]] = 2;
            ++eaten;
        }else if (map[locate[0]*28+locate[1]] == 3) {    // get power
            eatPos = locate[0]*28+locate[1];
            map[locate[0]*28+locate[1]] = 2;
            powerTime = timer+850;
            ++eaten;
        }
    }else if (step == 0 && locate[1]>0 && locate[1]<27){
        switch (direction) {
        case 1:
            if (!map[locate[0]*28-28+locate[1]]){
                direction = 0;
            }
            break;
        case 2:
            if (!map[locate[0]*28+1+locate[1]]){
                direction = 0;
            }
            break;
        case 3:
            if (!map[locate[0]*28+28+locate[1]]){
                direction = 0;
            }
            break;
        case 4:
            if (!map[locate[0]*28-1+locate[1]]){
                direction = 0;
            }
            break;
        case 0:
            break;
        }
        if (direction){++step;}
    }else{
        ++step;
    }
}
void Pacman::changeDir(int in){
    if (in<5 && in>0)
    preDir = in;
}
int Pacman::getEaten(){return eaten;}
int Pacman::getPower(){     // 2: power end  1: power start  0: normal
    if (powerTime == timer){return 2;}
    else if (powerTime && timer==powerTime-850){return 1;}
    else {return 0;}
}
void Pacman::die(int in){
    locate[0] = 23;
    locate[1] = 13;
    direction = 4;
    step = -3;
}
