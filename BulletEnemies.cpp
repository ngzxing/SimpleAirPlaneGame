#include "BulletEnemies.h"
#include "Player.h"

BulletEnemies::BulletEnemies(string pic, int attack_, double speed) : FlyingObject(0, speed, pic)
{
    attack = new Status<int>("attack", attack_);
    rotatePic();
}

void BulletEnemies::movement()
{
    setPos(x(), y()+velocity->getFlag()*10);

    if(collide()){

        return;
    }


    if(y()>=650){

        scene()->removeItem(this);
        delete this;
    }
}

bool BulletEnemies::collide()
{
    QList<QGraphicsItem* >colliding = collidingItems();
    int n = colliding.size();
    for(int i=0; i<n; i++){

        if(typeid(*colliding[i]) == typeid(Player)){

            *(static_cast<Player*>(colliding[i])->getHealth())-=(attack->getFlag());
            static_cast<Player*>(colliding[i])->getHealth()->showOnScreen();

            scene()->removeItem(this);
            delete this;
            return 1;
        }
    }

    return 0;
}

BulletEnemies *BulletEnemies::selectBullet(int index)
{
    BulletEnemies* bullet;

    if(index == 1){

        bullet = new BulletEnemies("/images/image/Smoke.png", 1, 0.2);
        return bullet;
    }
    else if(index==2){

        bullet = new BulletEnemies("/images/image/laserBullet.png", 2, 0.01);
        bullet->rotatePic();

        return bullet;
    }
    else{

        return NULL;
    }
}






