#include "BuffHealth.h"
#include "Player.h"


BuffHealth::BuffHealth(int degree_, double speed, string pic, double scale) : Buff(degree_, speed, pic, scale){};

void BuffHealth::changeOfBuff(QGraphicsItem* collides)
{
    Player* player = static_cast<Player*>(collides);

    *(player->getHealth())+=degree;
    player->getHealth()->showOnScreen();
}

BuffHealth::~BuffHealth()
{

}
