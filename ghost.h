#ifndef GHOST_H
#define GHOST_H
#include"gameobj.h"

class Ghost : public GameObj
{
public:
    Ghost();
    virtual ~Ghost();

protected:
    virtual void move();
    virtual void die(int);
    virtual void scatter();
    virtual void fright();
    virtual void chase();
    virtual void findDir();

    int map[924];     // 0: Wall, 1: road, 2: cross
    GameObj* target;
    int destination[2];     // where he/she want to go
    int timer;              // time spent in a stage
    int scatterMode;        // which corner
    int isfright;           // fright at once
    int frightTimer;
    int frightTime;
};


class Blinky : public Ghost
{
public:
    Blinky(GameObj*,int);
    virtual ~Blinky();
    virtual void die(int);
private:

};

class Pinky : public Ghost{
public:
    Pinky(GameObj*,int);
    ~Pinky();
    void chase();
    void die(int);
};
class Inky : public Ghost{
public:
    Inky(GameObj*,GameObj*,int);
    ~Inky();
    void chase();
    void die(int);
protected:
    GameObj* blinky;
};
class Clyde : public Ghost{
public:
    Clyde(GameObj*,int);
    ~Clyde();
    void chase();
    void die(int);
};

#endif // GHOST_H
