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

    void mousePressEvent(QGraphicsSceneMouseEvent* event); //define how the button behave after mouse press
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event); //define how the button behave after hover enter
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event); //define how the button behave after hover leave

    ~Button();

signals:

    void clicked(); //define the signal sended after the Button is clicked

private:
    QGraphicsTextItem* text; // composition
    string pic1, pic2;

};


#endif // BUTTON_H
