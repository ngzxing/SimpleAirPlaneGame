#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "BulletPlayer.h"
#include "Status.h"

class Player : public QGraphicsPixmapItem{

public:
    Player(string pic, double scale, QGraphicsItem* parent = 0);
    void keyPressEvent(QKeyEvent* event);
    Status<int>* getHealth();
    Status<double>* getVelocity();
    Status<int>* getScore();
    int getBulletIndex();

private:
    BulletPlayer* bullet;
    Status<int>* health;
    Status<double>* velocity;
    Status<int>* score;
    int bulletIndex;

};


#endif // PLAYER_H
