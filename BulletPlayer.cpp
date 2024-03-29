#include "BulletPlayer.h"
#include "Enemies.h"
using namespace std;

BulletPlayer::BulletPlayer(string pic, int attack_, double speed, double scale_) : FlyingObject(0, speed, pic,scale_)
{

    attack = new Status<int>("attack", attack_);
}

void BulletPlayer::movement()
{
    setPos(x(), y() - velocity->getFlag()*10);

    if(y()<0){

        scene()->removeItem(this);
        delete this;
    }
}

bool BulletPlayer::collide()
{
    return 0;
}

Status<int> *BulletPlayer::getAttack()
{
    return attack;
}

BulletPlayer *BulletPlayer::selectBullet(int index)
{
    BulletPlayer* bullet;

    if(index == 1){

        bullet = new BulletPlayer("/images/image/Smoke.png", 1, 0.2, 1);
        return bullet;
    }
    else if(index==2){

        bullet = new BulletPlayer("/images/image/laserBullet.png",2, 0.25, 0.07);
        bullet->rotatePic();

        return bullet;
    }
    else if(index==3){

        bullet = new BulletPlayer("/images/image/bullet.png", 3, 0.3,0.1);
        bullet->rotatePic();

        return bullet;
    }
    else{

        return NULL;
    }
}

BulletPlayer::~BulletPlayer()
{
    delete attack;
}


