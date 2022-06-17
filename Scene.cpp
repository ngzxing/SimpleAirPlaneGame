#include "Scene.h"
#include "Player.h"
#include <QFont>

Scene::Scene(QWidget *parent)
{
    scene -> setSceneRect(0, 0, 1000, 650);
    view->setScene(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1000, 650);

}

void Scene::createPage(){}

void Scene::setBackground(const QColor& color)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    view->setBackgroundBrush(brush);
    scene -> update();
}

void Scene::setBackgroundPic(string bgPic){

    view->setBackgroundBrush( QBrush(QImage( (":" + bgPic).c_str() )));
}

void Scene::addPic(string pic, int x, int y, double scale)
{
    QGraphicsPixmapItem* images = new QGraphicsPixmapItem();
    images -> setPixmap(QPixmap( (":" + pic).c_str() ));
    images->setPos(x, y);
    images->setScale(scale);
    scene->addItem(images);
}

void Scene::addText(string text, int x, int y, const QColor &color, string font, int fontSize)
{
    QGraphicsTextItem* textItem = new QGraphicsTextItem();
    textItem->setPlainText(QString(text.c_str()));
    textItem->setPos(x, y);
    textItem->setDefaultTextColor(color);
    textItem->setFont(QFont(font.c_str(), fontSize));
    scene->addItem(textItem);
}

void Scene::jumpPage(Button *button, Scene *scene)
{

    QObject::connect(button, SIGNAL(clicked()), scene, SLOT(newPage()));
}



void Scene::newPage()
{
    scene->clear();
    createPage();
}


