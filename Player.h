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
    void keyPressEvent(QKeyEvent* event); // define how player behave after the certain key is pressed
    Status<int>* getHealth(); // get health status
    Status<double>* getVelocity(); // get velocity status
    int getBulletIndex() const; // get bullet type equipped
    double getScale() const; // get scale of picture
    void changeBulletIndex(int index); // change the type of bullet equipped

    ~Player();

private:
    BulletPlayer* bullet; // aggregation
    Status<int>* health; // composition
    Status<double>* velocity; // composition
    int bulletIndex;
    double scale;

};


#endif // PLAYER_H
