#ifndef BUFFBULLET_H
#define BUFFBULLET_H

#include "Buff.h"

class BuffBullet : public Buff{

public:
    BuffBullet(int degree_, double speed, string pic, double scale);
    void changeOfBuff(QGraphicsItem* collides);
};


#endif // BUFFBULLET_H

