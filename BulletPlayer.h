#ifndef BULLETPLAYER_H
#define BULLETPLAYER_H

#include "FlyingObject.h"
#include "Status.h"
#include <QGraphicsScene>

class BulletPlayer : public FlyingObject{

public:
    void movement();
    bool collide();
    Status<int> *getAttack();

    static BulletPlayer* selectBullet(int index);

private:
    BulletPlayer(string pic, int attack_ , double speed);
    Status<int>* attack;
};


#endif // BULLETPLAYER_H
