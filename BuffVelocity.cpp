#include "BuffVelocity.h"
#include "Player.h"

BuffVelocity::BuffVelocity(int degree_, double speed, string pic, double scale) : Buff(degree_, speed, pic, scale)
{

}

void BuffVelocity::changeOfBuff(QGraphicsItem *collides)
{
    Player* player = static_cast<Player*>(collides);

    *(player->getVelocity())+=degree;
    player->getVelocity()->showOnScreen();


}

BuffVelocity::~BuffVelocity()
{

}
