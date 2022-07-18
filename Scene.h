#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "Button.h"

class Scene : public QObject{

    Q_OBJECT

public:

    //page showing related method
    static QGraphicsScene* scene;
    static QGraphicsView* view;
    void jumpPage(Button* button, Scene* scene); // define how to use a button to jump between two page

    //create page related method
    Scene(QWidget* parent = 0);
    virtual void createPage() = 0; // define how the page shown
    virtual ~Scene();


public slots:
    void newPage(); // define how to jump to the next page

protected:
    //design purpose methods
    void setBackground(const QColor& color); // set background color
    void setBackgroundPic(string bgPic); // set background picture
    void addPic(string pic, int x, int y, double scale); // adding picture to screen
    void addAnm(string pic, int x =0 , int y=0, double width = 1440, double height = 810); // adding gif or movie to screen
    void addText(string text, int x, int y, const QColor& color, string font, int fontSize); // adding text to screen

};

#endif // SCENE_H
