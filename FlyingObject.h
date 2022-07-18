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
    void move(); // call it to make the FlyingObject can move on the screen
    virtual bool collide() = 0; // define how it behave after collding
    double getScale() const; // get scale of picture
    virtual ~FlyingObject();

public slots:

    virtual void movement() = 0; //define how it move

protected:
    void rotatePic(); // define to rotate the picture
    Status<int>* health; // composition
    Status<double>* velocity; // composition
    double scale;

};

#endif // FLYINGOBJECT_H
