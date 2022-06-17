#include "Buff.h"
#include "Player.h"


Buff::Buff(int degree_, double speed, string pic, double scale) : FlyingObject(0, speed, pic), degree(degree_){

    setScale(scale);
    int randPos = rand()%700;
    setPos(randPos,-50);
    setScale(0.2);
}

void Buff::movement()
{
    setPos(x(), y() + velocity->getFlag()*10);

    if (collide())
        return;

    if(y()>=650){

        scene()->removeItem(this);
        delete this;
        return;
    }

}

bool Buff::collide()
{
    QList<QGraphicsItem* >colliding = collidingItems();
    int n = colliding.size();

    for(int i=0; i<n; i++){

        if(typeid(*colliding[i]) == typeid(Player)){

            changeOfBuff(colliding[i]);
            scene()->removeItem(this);

            delete this;

            return 1;
        }
    }

    return 0;
}

void Buff::changeOfBuff(QGraphicsItem* collides){};


