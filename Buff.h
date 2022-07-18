#ifndef BUFF_H
#define BUFF_H

#include "FlyingObject.h"

class Buff : public FlyingObject{

public:
    Buff(int degree_ = 0, double speed = 0, string pic = "/", double scale = 1);
    void movement(); //define how buff move
    bool collide(); //define how buff behave after collides with player
    virtual void changeOfBuff(QGraphicsItem* collides) = 0; //define how buff change player's status after colliding
    virtual ~Buff();

protected:
    int degree;
};

#endif // BUFF_H
