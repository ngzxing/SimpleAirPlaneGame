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
    void jumpPage(Button* button, Scene* scene);

    //create page related method
    Scene(QWidget* parent = 0);
    virtual void createPage();



public slots:
    void newPage();

protected:
    //design purpose methods
    void setBackground(const QColor& color);
    void setBackgroundPic(string bgPic);
    void addPic(string pic, int x, int y, double scale);
    void addText(string text, int x, int y, const QColor& color, string font, int fontSize);

};

#endif // SCENE_H