#ifndef STATUS_H
#define STATUS_H

#include <QGraphicsTextItem>
#include <string>
#include <QFont>
using namespace std;

template <typename dataType>
class Status : public QGraphicsTextItem{

public:

    Status(string name_, dataType initial, QGraphicsItem* parent = NULL);
    void operator +=(dataType degree); // define how the status change after added
    void operator -=(dataType degree); // define how the status change after substracted
    void changeFlag(dataType flag_); // define how to change the status
    dataType getFlag(); // get the data encapsulated

    void setTextFont(int x, int y, const QColor& color = "black", int fontSize = 16, string font = "times"); // set how the status shown on screen
    void showOnScreen(); // prepare the text will be shown on the screen

    virtual ~Status();

private:
    dataType flag;
    string name; //composition

};

#endif // STATUS_H
