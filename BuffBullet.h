#ifndef BUFFBULLET_H
#define BUFFBULLET_H

#include "Buff.h"

class BuffBullet : public Buff{

public:
    static BuffBullet *selectBuffBullet(int index); //define the selection of different type of buff bullet
    void changeOfBuff(QGraphicsItem* collides); //define how buffBullet change player's bullet equipped after colliding
    ~BuffBullet();

private:
    BuffBullet(int degree_, double speed, string pic, double scale);

};


#endif // BUFFBULLET_H

