#ifndef BUFFBULLET_H
#define BUFFBULLET_H

#include "Buff.h"

class BuffBullet : public Buff{

public:
    static BuffBullet *selectBuffBullet(int index);
    void changeOfBuff(QGraphicsItem* collides);
    ~BuffBullet();

private:
    BuffBullet(int degree_, double speed, string pic, double scale);

};


#endif // BUFFBULLET_H

