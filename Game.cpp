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
    addAnm("/images/image/game.gif");
    player = new Player("/images/image/player.png", 0.25);
    player->setPos((1440-player->boundingRect().width()*player->getScale())/2,(810-player->boundingRect().height()*player->getScale()));
    scene->addItem(player);

    addPic("/images/image/score_health.png", 0, 0, 0.3);
    score = new Status<int>("score", 3);
    score->setTextFont(225, 10, "white", 22);
    score->showOnScreen();
    scene->addItem(score);

    Status<int>* health = player->getHealth();
    health->setTextFont(225,50, "red", 22);
    health->showOnScreen();
    scene->addItem(health);


    timerEnemies = new QTimer();
    connect(timerEnemies, SIGNAL(timeout()), this, SLOT(spawn()));
    timerEnemies->start(5000);


    timerBuffHealth = new QTimer();
    connect(timerBuffHealth, SIGNAL(timeout()), this, SLOT(callBuffHealth()));
    timerBuffHealth->start(15000);


    timerBuffVelocity = new QTimer();
    connect(timerBuffVelocity, SIGNAL(timeout()), this, SLOT(callBuffVelocity()));
    timerBuffVelocity->start(20000);


    timerBuffBullet = new QTimer();
    connect(timerBuffBullet, SIGNAL(timeout()), this, SLOT(callBuffBullet()));
    timerBuffBullet->start(20000);


    detectTrigger();
}

Game::~Game()
{
    cleanClock();
}

// difficulty
void Game::spawn()
{
    if(score->getFlag() < 35){

        enemy = Enemies::selectEnemies(1);
    }
    else if(score->getFlag() < 65){

        enemy = Enemies::selectEnemies(2);
    }
    else if(score->getFlag() < 100){

        enemy = Enemies::selectEnemies(3);
    }
    scene->addItem(enemy);
    enemy->move();

    timerEnemies->stop();
    timerEnemies->start(5000/sqrt(score->getFlag()/ 10 + 1 ));


}

void Game::callBuffHealth()
{
    buffHealth = new BuffHealth(1+score->getFlag()/20, 0.2 + int(score->getFlag()/20)*0.1, "/images/image/health_buff.png", 0.2);
    scene->addItem(buffHealth);
    buffHealth->move();
    
    timerBuffHealth->stop();
    timerBuffHealth->start(15000/sqrt(score->getFlag()/ 20 + 1));

}

void Game::callBuffVelocity()
{   
    buffVelocity = new BuffVelocity(1, 0.3 + int(score->getFlag()/20)*0.1, "/images/image/speed_buff.png", 0.15);
    scene->addItem(buffVelocity);
    buffVelocity->move();
    
    timerBuffVelocity->stop();
    timerBuffVelocity->start(20000/sqrt(score->getFlag()/ 20 + 1));
    
}

void Game::callBuffBullet()
{

    if(score->getFlag() < 25){

        timerBuffBullet->stop();
        timerBuffBullet->start(20000/sqrt(score->getFlag()/ 10 + 1));
        return;

    }
    else if(score->getFlag() < 55){

        buffBullet = BuffBullet::selectBuffBullet(2);
    }
    else if(score->getFlag() < 100){

        buffBullet = BuffBullet::selectBuffBullet(3);
    }

    buffBullet = BuffBullet::selectBuffBullet(2);
    scene->addItem(buffBullet);
    buffBullet->move();
    
    timerBuffBullet->stop();
    timerBuffBullet->start(2000/sqrt(score->getFlag()/ 10 + 1));
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





