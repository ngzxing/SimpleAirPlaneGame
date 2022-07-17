#ifndef ENEMIES_H
#define ENEMIES_H

#include "FlyingObject.h"
#include "BulletEnemies.h"
#include <QTimer>

class Enemies : public FlyingObject{

    Q_OBJECT

public:

    void movement();
    bool collide();
    static Enemies* selectEnemies(int index);
    ~Enemies();

public slots:
    void emitBullet();

private:
    Enemies(int life, double speed, string pic, double scale_, double emitTime, int bulletIndex_);
    BulletEnemies* bullet;
    int bulletIndex;
};

#endif // ENEMIES_H
