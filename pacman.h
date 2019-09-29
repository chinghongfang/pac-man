#ifndef PACMAN_H
#define PACMAN_H
#include"gameobj.h"

class Pacman : public GameObj
{
public:
    Pacman();
    ~Pacman();
    void move();
    void changeDir(int);
    int getEaten();
    int getPower();
    virtual void die(int);
    int map[924];
    int eatPos;
protected:
    int preDir;
    int eaten;
    int timer;
    int powerTime;

};

#endif // PACMAN_H
