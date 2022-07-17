#ifndef BUFFVELOCITY_H
#define BUFFVELOCITY_H

#include "Buff.h"

class BuffVelocity : public Buff{

public:
    BuffVelocity(int degree_, double speed, string pic, double scale);
    void changeOfBuff(QGraphicsItem* collides);
    ~BuffVelocity();
};


#endif // BUFFVELOCITY_H
