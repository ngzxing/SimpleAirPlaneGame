#include "FlyingObject.h"
using namespace std;

FlyingObject::FlyingObject(int life, double speed, string pic, double scale_, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), scale(scale_)
{
    velocity = new Status<double>("velocity", speed);
    health = new Status<int>("Health", life);
    setPixmap(QPixmap( (":" + pic).c_str() ));
    setScale(scale);

}

void FlyingObject::move()
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(movement()));
    timer->start(10);
}

double FlyingObject::getScale() const
{
    return scale;
}

FlyingObject::~FlyingObject()
{
    delete health;
    delete velocity;
}

void FlyingObject::rotatePic()
{
    setTransformOriginPoint( boundingRect().width()*scale/2, boundingRect().height()*scale/2 );
    setRotation(180);
}


