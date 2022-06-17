#ifndef GAME_H
#define GAME_H

#include "Scene.h"
#include "Enemies.h"
#include "BuffHealth.h"
#include <QObject>
#include "Status.h"

class Game : public Scene{

    Q_OBJECT

public:

    Game();
    void createPage();


public slots:
    // call something out;
    void spawn();
    void callBuffHealth();
    void JumpByTrigger();

private:
    void detectTrigger();
    void cleanClock();

    Enemies* enemy; 
    BuffHealth* buffHealth;
    QTimer* timerEnemies, *timerBuffHealth, *timerGameOver;

};


#endif // GAME_H
