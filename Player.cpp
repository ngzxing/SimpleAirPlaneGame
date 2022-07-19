#include "Player.h"
#include <QGraphicsTextItem>
#include <QString>

extern Status<int>* score;
Player::Player(string pic, double scale_, QGraphicsItem* parent) : bulletIndex(1), scale(scale_)
{
    setPixmap(QPixmap( (":" + pic).c_str() ));
    setScale(scale);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    health = new Status<int>("health", 10);
    velocity = new Status<double>("velocity", 10);
    //bulletSound = new QMediaPlayer();
    //bulletSound->setMedia(QUrl("qrc:/sounds/sound/gun.mp3"));

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Right){

        if(x()+boundingRect().width()*scale<1440){

            setPos(x()+velocity->getFlag(), y());
        }
    }
    else if( event->key() == Qt::Key_Left){

        if(x()>0){

            setPos(x()-velocity->getFlag(), y());
        }
    }
    else if( event->key() == Qt::Key_Space){

        bullet = BulletPlayer::selectBullet(bulletIndex);
        bullet->move();
        bullet->setPos(x()+(boundingRect().width()*scale - bullet->boundingRect().width()*bullet->getScale())/2, y());

        /*
        if(bulletSound->state() == QMediaPlayer::PlayingState){

            bulletSound->setPosition(0);
        }
        else if(bulletSound->state() == QMediaPlayer::StoppedState){

            bulletSound->play();
        }*/

        scene()->addItem(bullet);
    }
    else if( event->key() == Qt::Key_Up ){

        if(y()>0){

            setPos(x(), y()-velocity->getFlag());
        }
    }
    else if( event->key() == Qt::Key_Down){

        if(y()+boundingRect().height()*scale<810){

            setPos(x(), y()+velocity->getFlag());
        }

    }
    else if( event->key() == Qt::Key_1){

        *score +=1;
    }
}

Status<int> *Player::getHealth()
{
    return health;
}

Status<double> *Player::getVelocity()
{
    return velocity;
}

int Player::getBulletIndex() const
{
    return bulletIndex;
}

double Player::getScale() const
{

    return scale;
}

void Player::changeBulletIndex(int index)
{
    bulletIndex = index;
}


Player::~Player()
{
    delete health;
    delete velocity;
}




