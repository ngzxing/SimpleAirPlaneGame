#ifndef BUFFHEALTH_H
#define BUFFHEALTH_H

#include "FlyingObject.h"
#include "Buff.h"

class BuffHealth : public Buff{

public:
    BuffHealth(int degree_, double speed, string pic, double scale);
    void changeOfBuff(QGraphicsItem* collides);
    ~BuffHealth();
};

#endif // BUFFHEALTH_H
