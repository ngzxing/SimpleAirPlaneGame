#include "Button.h"

Button::Button(string name, int width, int height, int x, int y, const QColor& color, const QColor& fontColor, string font, int fontSize, QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent)
{
    setRect(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    setBrush(brush);

    text = new QGraphicsTextItem(name.c_str(), this);
    text->setFont(QFont(font.c_str(), fontSize));
    text->setDefaultTextColor(fontColor);
    text->setPos( (rect().width() - text->boundingRect().width())/2+rect().x(), (rect().height() - text->boundingRect().height())/2+rect().y());

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}



