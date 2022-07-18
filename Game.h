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
    void createPage(); //define how the page shown
    ~Game();


public slots:
    // call something out;
    void spawn(); //call the routine of release enemies 
    void callBuffHealth(); //call the routine of release buffHealth
    void callBuffVelocity(); //call the routine of release buffVelocity
    void callBuffBullet(); //call the routine of release buffBullet
    void JumpByTrigger(); //define the page to jump after score>100 or <0 or  health<0

private:
    void detectTrigger(); //check repeatly whether score>100 or <0 or health<0
    void cleanClock(); //clear all counting clock

    Enemies* enemy; //aggregation
    BuffHealth* buffHealth; //aggregation
    BuffVelocity* buffVelocity; //aggregation
    BuffBullet* buffBullet; //aggregation
    QTimer* timerEnemies, *timerBuffHealth, *timerBuffVelocity, *timerBuffBullet, *timerGameOver; //composition
    Player* player; //composition

};


#endif // GAME_H
