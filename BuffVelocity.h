#ifndef BUFFVELOCITY_H
#define BUFFVELOCITY_H

#include "Buff.h"

class BuffVelocity : public Buff{

public:
    BuffVelocity(int degree_, double speed, string pic, double scale);
    void changeOfBuff(QGraphicsItem* collides); // define BuffVelocity change player's velocity status after colliding
    ~BuffVelocity();
};


#endif // BUFFVELOCITY_H
