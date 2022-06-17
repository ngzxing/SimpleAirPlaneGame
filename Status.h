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
    void operator +=(dataType degree);
    void operator -=(dataType degree);
    void changeFlag(dataType flag_);
    dataType getFlag();

    void setTextFont(int x, int y, const QColor& color = "black", int fontSize = 16, string font = "times");
    void showOnScreen();

private:
    dataType flag;
    string name;

};

#endif // STATUS_H