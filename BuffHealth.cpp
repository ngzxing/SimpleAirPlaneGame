#include "BuffHealth.h"
#include "Player.h"


BuffHealth::BuffHealth(int degree_, double speed, string pic, double scale) : Buff(degree_, speed, pic, scale){};

void BuffHealth::changeOfBuff(QGraphicsItem* collides)
{
    *(static_cast<Player*>(collides)->getHealth())+=degree;
    static_cast<Player*>(collides)->getHealth()->showOnScreen();
}
