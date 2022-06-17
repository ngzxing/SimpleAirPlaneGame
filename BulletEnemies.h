#ifndef BULLETENEMIES_H
#define BULLETENEMIES_H

#include "FlyingObject.h"
#include "Status.h"

class BulletEnemies : public FlyingObject{

public:
    void movement();
    bool collide();

    static BulletEnemies *selectBullet(int index);

private:
    BulletEnemies(string pic, int attack_ , double speed);

    Status<int>* attack;

};


#endif // BULLETENEMIES_H
