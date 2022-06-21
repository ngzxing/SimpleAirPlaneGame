#ifndef GAME_H
#define GAME_H

#include "Scene.h"
#include "Enemies.h"
#include "BuffHealth.h"
#include "BuffVelocity.h"
#include "BuffBullet.h"
#include <QObject>
#include "Status.h"
#include "Player.h"

class Game : public Scene{

    Q_OBJECT

public:

    Game();
    void createPage();


public slots:
    // call something out;
    void spawn();
    void callBuffHealth();
    void callBuffVelocity();
    void callBuffBullet();
    void JumpByTrigger();

private:
    void detectTrigger();
    void cleanClock();

    Enemies* enemy; 
    BuffHealth* buffHealth;
    BuffVelocity* buffVelocity;
    BuffBullet* buffBullet;
    QTimer* timerEnemies, *timerBuffHealth, *timerBuffVelocity, *timerBuffBullet, *timerGameOver;
    Player* player;

};


#endif // GAME_H
