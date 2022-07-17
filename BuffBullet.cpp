#include "BuffBullet.h"
#include "Player.h"

BuffBullet::BuffBullet(int index, double speed, string pic, double scale) : Buff(index, speed, pic, scale){};

BuffBullet *BuffBullet::selectBuffBullet(int index=2)
{

    if(index == 2){

        BuffBullet* buffBullet = new BuffBullet(2, 0.4, "/images/image/bullet_buff.png", 0.25);
        return buffBullet;
    }
    else if(index == 3){

        BuffBullet* buffBullet = new BuffBullet(3, 0.4, "/images/image/buff_buff.png", 0.25);
        return buffBullet;
    }

    return 0;
}

void BuffBullet::changeOfBuff(QGraphicsItem *collides)
{
    Player* player = static_cast<Player*>(collides);

    player->changeBulletIndex(degree);

}

BuffBullet::~BuffBullet()
{

}
