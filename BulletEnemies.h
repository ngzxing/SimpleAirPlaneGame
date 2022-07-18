#ifndef BULLETENEMIES_H
#define BULLETENEMIES_H

#include "FlyingObject.h"
#include "Status.h"

class BulletEnemies : public FlyingObject{

public:
    void movement(); //define how it move
    bool collide(); //define how it behave after collides with player

    static BulletEnemies *selectBullet(int index); //define how to select the specific type of bullet
    ~BulletEnemies();

private:
    BulletEnemies(string pic, int attack_, double speed, double scale_);
    Status<int>* attack; // composition

};


#endif // BULLETENEMIES_H
