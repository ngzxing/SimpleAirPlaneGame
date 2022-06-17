#include "Enemies.h"
#include "Player.h"
#include <QTimer>

extern Status<int>* score;

Enemies::Enemies(int life, double speed, string pic) : FlyingObject(life, speed, pic) {

    int randPos = rand()%700;
    setPos(randPos,-50);
    setScale(0.8);

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(emitBullet()));
    timer->start(500);

    //rotatePic();
}

void Enemies::movement()
{
    setPos(x(), y()+velocity->getFlag()*10);

    QList<QGraphicsItem* > colliding = collidingItems();
    int n = colliding.size();
    for(int i=0; i<n; i++){

        if( typeid(*(colliding[i])) == typeid(Player) ){

            *(static_cast<Player*>(colliding[i])->getHealth())-=1;
            static_cast<Player*>(colliding[i])->getHealth()->showOnScreen();

            scene()->removeItem(this);
            delete this;

            return;
       }
       else if( typeid(*(colliding[i])) == typeid(BulletPlayer)){

            *health -= (static_cast<BulletPlayer*>(colliding[i])->getAttack()->getFlag());
            if(health->getFlag() <=0){

                *score+=1;
                score->showOnScreen();


                scene()->removeItem(colliding[i]);
                scene()->removeItem(this);


                delete colliding[i];
                delete this;
            }
            else{

                scene()->removeItem(colliding[i]);
                delete colliding[i];
            }


            return;
       }
    }


    if(y()>=650){

        *score-=1;
        score->showOnScreen();

        scene()->removeItem(this);
        delete this;
    }
}

Enemies *Enemies::selectEnemies(int index)
{
    Enemies* enemies;

    if(index == 1){

        enemies = new Enemies(2, 0.1, "/images/image/loo.png");
        enemies->bullet = BulletEnemies::selectBullet(1);

        return enemies;

    }else if(index == 2){

        enemies = new Enemies(2, 0.1, "/images/image/loo.png");
        enemies->bullet = BulletEnemies::selectBullet(2);

        return enemies;
    }
    else{

        return NULL;
    }
}

void Enemies::emitBullet()
{
    bullet = BulletEnemies::selectBullet(1);
    scene()->addItem(bullet);
    bullet->setPos(x()+ (boundingRect().width()-bullet->boundingRect().width())/2, y() + boundingRect().height());
    bullet->move();
}


