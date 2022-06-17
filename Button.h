#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QBrush>
#include <QFont>
using namespace std;

class Button : public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Button(string name, int width, int height, int x, int y, const QColor& color, const QColor& fontColor, string font, int fontSize, QGraphicsItem* parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:

    void clicked();

private:
    QGraphicsTextItem* text;

};


#endif // BUTTON_H
