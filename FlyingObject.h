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


    FlyingObject(int life, double speed, string pic, double scale_, QGraphicsItem* parent = NULL);
    void move();
    virtual bool collide() = 0;
    double getScale() const;
    virtual ~FlyingObject();

public slots:

    virtual void movement() = 0;

protected:
    void rotatePic();
    Status<int>* health;
    Status<double>* velocity;
    double scale;

};

#endif // FLYINGOBJECT_H
