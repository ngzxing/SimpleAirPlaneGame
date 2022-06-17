#ifndef ENEMIES_H
#define ENEMIES_H

#include "FlyingObject.h"
#include "BulletEnemies.h"

class Enemies : public FlyingObject{

    Q_OBJECT

public:

    void movement();
    static Enemies* selectEnemies(int index);

public slots:
    void emitBullet();

private:
    Enemies(int life, double speed, string pic);
    BulletEnemies* bullet;
};

#endif // ENEMIES_H
