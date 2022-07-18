#ifndef ENEMIES_H
#define ENEMIES_H

#include "FlyingObject.h"
#include "BulletEnemies.h"
#include <QTimer>

class Enemies : public FlyingObject{

    Q_OBJECT

public:

    void movement(); // define how it move
    bool collide(); // define how it behave after collides with BulletPlayer and Player
    static Enemies* selectEnemies(int index); // define how to select specific type of enemies
    ~Enemies();

public slots:
    void emitBullet(); // define how the enemies emit the BulletEnemies

private:
    Enemies(int life, double speed, string pic, double scale_, double emitTime, int bulletIndex_);
    BulletEnemies* bullet; // aggregation
    int bulletIndex;
};

#endif // ENEMIES_H
