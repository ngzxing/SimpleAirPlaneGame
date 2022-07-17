#include "Button.h"

Button::Button(string name, string pic1_, string pic2_, double scale, int x, int y, QGraphicsItem* parent) : pic1(pic1_), pic2(pic2_)
{
    setPixmap(QPixmap( (":" + pic1).c_str() ));
    setScale(scale);
    setPos(x, y);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap( (":" + pic2).c_str() ));
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap( (":" + pic1).c_str() ));
}

Button::~Button()
{
    delete text;
}



