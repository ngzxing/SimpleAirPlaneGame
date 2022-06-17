#include "FlyingObject.h"
using namespace std;

FlyingObject::FlyingObject(int life, double speed, string pic, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    velocity = new Status<double>("velocity", speed);
    health = new Status<int>("Health", life);
    setPixmap(QPixmap( (":" + pic).c_str() ));

}

void FlyingObject::move()
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(movement()));
    timer->start(10);
}

bool FlyingObject::collide(){

    return 0;
}

void FlyingObject::movement(){}

void FlyingObject::rotatePic()
{
    setTransformOriginPoint( boundingRect().width()/2, boundingRect().height()/2 );
    setRotation(180);
}


