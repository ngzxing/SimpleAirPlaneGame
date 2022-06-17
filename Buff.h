#ifndef BUFF_H
#define BUFF_H

#include "FlyingObject.h"

class Buff : public FlyingObject{

public:
    Buff(int degree_ = 0, double speed = 0, string pic = "/", double scale = 1);
    void movement();
    bool collide();
    virtual void changeOfBuff(QGraphicsItem* collides);

protected:
    int degree;

};

#endif // BUFF_H
