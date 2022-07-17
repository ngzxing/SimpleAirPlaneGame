#include "Buff.h"
#include "Player.h"


Buff::Buff(int degree_, double speed, string pic, double scale) : FlyingObject(0, speed, pic, scale), degree(degree_){

    int randPos = rand()%int(1440-boundingRect().width()*scale);
    setPos(randPos,-1*boundingRect().height()*scale);
    setScale(scale);
}

void Buff::movement()
{
    setPos(x(), y() + velocity->getFlag()*10);

    if (collide())
        return;

    if(y()>=810){

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

Buff::~Buff()
{

}




