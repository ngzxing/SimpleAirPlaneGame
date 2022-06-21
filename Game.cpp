#include "Game.h"
#include "LossPage.h"
#include "WinPage.h"
#include <cmath>


extern Status<int>* score;
extern LossPage* lossPage;
extern WinPage* winPage;

Game::Game() : Scene(){}

void Game::createPage()
{
    setBackgroundPic("/images/image/Gay_Pride_Flag.png");
    player = new Player("/images/image/rx.png", 1);
    player->setPos(500,650 - player->boundingRect().height());
    scene->addItem(player);

    score->setTextFont(0, 0);
    score->setPos(0, 0);
    score->showOnScreen();
    scene->addItem(score);

    Status<int>* health = player->getHealth();
    health->setTextFont(0, score->boundingRect().height());
    health->setPos( 0, score->boundingRect().height()+10);
    health->showOnScreen();
    scene->addItem(health);


    timerEnemies = new QTimer();
    connect(timerEnemies, SIGNAL(timeout()), this, SLOT(spawn()));
    timerEnemies->start(5000);

    timerBuffHealth = new QTimer();
    connect(timerBuffHealth, SIGNAL(timeout()), this, SLOT(callBuffHealth()));
    timerBuffHealth->start(20000);

    timerBuffVelocity = new QTimer();
    connect(timerBuffVelocity, SIGNAL(timeout()), this, SLOT(callBuffVelocity()));
    timerBuffVelocity->start(20000);

    timerBuffBullet = new QTimer();
    connect(timerBuffBullet, SIGNAL(timeout()), this, SLOT(callBuffBullet()));
    timerBuffBullet->start(20000);

    detectTrigger();
}

// difficulty
void Game::spawn()
{

    enemy = Enemies::selectEnemies(1);
    scene->addItem(enemy);
    enemy->move();

    timerEnemies->stop();
    timerEnemies->start(5000/sqrt(score->getFlag()/ 10 + 1 ));


}

void Game::callBuffHealth()
{
    buffHealth = new BuffHealth(1, 0.1, "/images/image/buffHealth.png", 0.2);
    scene->addItem(buffHealth);
    buffHealth->move();
    
    timerBuffHealth->stop();
    timerBuffHealth->start(20000/sqrt(score->getFlag()/ 10 + 1));

}

void Game::callBuffVelocity()
{   
    buffVelocity = new BuffVelocity(1, 0.1, "/images/image/buffHealth.png", 0.2);
    scene->addItem(buffVelocity);
    buffVelocity->move();
    
    timerBuffHealth->stop();
    timerBuffHealth->start(20000/sqrt(score->getFlag()/ 10 + 1));
    
}

void Game::callBuffBullet()
{
    buffBullet = new BuffBullet(1, 0.1, "/images/image/buffHealth.png", 0.2);
    scene->addItem(buffBullet);
    buffBullet->move();
    
    timerBuffBullet->stop();
    timerBuffBullet->start(20000/sqrt(score->getFlag()/ 10 + 1));
}

void Game::detectTrigger()
{
    timerGameOver = new QTimer();
    connect(timerGameOver, SIGNAL(timeout()), this, SLOT(JumpByTrigger()) );
    timerGameOver->start(100);
}

void Game::cleanClock()
{
    scene->clear();
    timerBuffHealth->stop();
    delete timerBuffHealth;
    timerBuffBullet->stop();
    delete timerBuffBullet;
    timerBuffVelocity->stop();
    delete timerBuffVelocity;
    timerEnemies->stop();
    delete timerEnemies;
    timerGameOver->stop();
    delete timerGameOver;
}

void Game::JumpByTrigger()
{
    if( (score->getFlag() <=0) || (player->getHealth()->getFlag() <=0) ){

        cleanClock();
        lossPage->createPage();
    }
    else if(score->getFlag() >=100){

        cleanClock();
        winPage->createPage();
    }

}





