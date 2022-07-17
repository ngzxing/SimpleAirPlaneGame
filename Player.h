#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include "BulletPlayer.h"
#include "Status.h"

class Player : public QGraphicsPixmapItem{

public:
    Player(string pic, double scale_, QGraphicsItem* parent = 0);
    void keyPressEvent(QKeyEvent* event);
    Status<int>* getHealth();
    Status<double>* getVelocity();
    int getBulletIndex() const;
    double getScale() const;
    void changeBulletIndex(int index);

    ~Player();

private:
    BulletPlayer* bullet;
    Status<int>* health;
    Status<double>* velocity;
    //QMediaPlayer* bulletSound;
    int bulletIndex;
    double scale;

};


#endif // PLAYER_H
