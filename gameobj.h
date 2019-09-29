#ifndef GAMEOBJ_H
#define GAMEOBJ_H


class GameObj
{
public:
    GameObj();
    virtual ~GameObj();
    virtual void move() = 0;
    virtual void die(int) = 0;
    void setLook(int);
    int getLocate(int)const;
    int getLook()const;
    int getDirection()const;
    int getStep()const;

protected:
    int locate[2];        // 1*2 int array
    int looklike;
    int movespeed;      // frames per move (the more, the slower)
    int speedTimer;     // frames
    int direction;      // 0: x, 1: ^, 2: >, 3: v, 4: <
    int step;           // -4 <= step <= 4 to compute where to put my picture
};

#endif // GAMEOBJ_H
