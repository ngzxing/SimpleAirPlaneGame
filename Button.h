#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QBrush>
#include <QFont>
using namespace std;

class Button : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Button(string name, string pic1_, string pic2_, double scale, int x, int y, QGraphicsItem* parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

    ~Button();

signals:

    void clicked();

private:
    QGraphicsTextItem* text;
    string pic1, pic2;

};


#endif // BUTTON_H
