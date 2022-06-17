#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include <QGraphicsPixmapItem>
#include <string>
#include <QTimer>
#include "Status.h"
#include <QGraphicsScene>
using namespace std;

class FlyingObject : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:


    FlyingObject(int life, double speed, string pic, QGraphicsItem* parent = NULL);
    void move();
    virtual bool collide();

public slots:

    virtual void movement();

protected:
    void rotatePic();
    Status<int>* health;
    Status<double>* velocity;

};

#endif // FLYINGOBJECT_H
