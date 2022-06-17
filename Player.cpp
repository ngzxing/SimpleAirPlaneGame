#include "Player.h"

Player::Player(string pic, double scale, QGraphicsItem* parent)
{
    setPixmap(QPixmap( (":" + pic).c_str() ));
    setScale(scale);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    health = new Status<int>("health", 10);
    score = new Status<int>("score", 10);
    velocity = new Status<double>("velocity", 10);
    bulletIndex = 1;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Right){

        setPos(x()+velocity->getFlag(), y());
    }
    else if( event->key() == Qt::Key_Left){

        setPos(x()-velocity->getFlag(), y());
    }
    else if( event->key() == Qt::Key_Space){

        bullet = BulletPlayer::selectBullet(bulletIndex);
        bullet->move();
        bullet->setPos(x()+(boundingRect().width() - bullet->boundingRect().width())/2, y());

        scene()->addItem(bullet);
    }
    else if( event->key() == Qt::Key_Up ){

        setPos(x(), y()-velocity->getFlag());
    }
    else if( event->key() == Qt::Key_Down){

        setPos(x(), y()+velocity->getFlag());
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

Status<int> *Player::getScore()
{
    return score;
}

int Player::getBulletIndex()
{
    return bulletIndex;
}




