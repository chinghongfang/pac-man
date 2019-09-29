#include "gameobj.h"
GameObj::GameObj()
{

}
GameObj::~GameObj(){}
void GameObj::setLook(int in){
    looklike = in;
}
int GameObj::getLocate(int in)const{
    if (in == 0){
        return locate[in];
    }else if(in == 1){
        return locate[in];
    }
    return locate[0];
}
int GameObj::getLook()const{return looklike;}
int GameObj::getDirection()const{return direction;}
int GameObj::getStep() const{return step;}
