#ifndef BULLETPLAYER_H
#define BULLETPLAYER_H

#include "FlyingObject.h"
#include "Status.h"
#include <QGraphicsScene>

class BulletPlayer : public FlyingObject{

public:
    void movement(); //define how it move
    bool collide(); //define how it behave after collides with enemies
    Status<int> *getAttack(); //get attack status

    static BulletPlayer* selectBullet(int index); //define how to select the specific type of bullet
    ~BulletPlayer();

private:
    BulletPlayer(string pic, int attack_, double speed, double scale_);
    Status<int>* attack; // composition
};


#endif // BULLETPLAYER_H
