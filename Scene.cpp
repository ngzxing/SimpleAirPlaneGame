#include "Scene.h"
#include "Player.h"
#include <QFont>
#include <QLabel>
#include <QMovie>
#include <QMediaPlayer>

extern QMediaPlayer* music;

Scene::Scene(QWidget *parent)
{
    scene -> setSceneRect(0, 0, 1440, 810);
    view->setScene(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1440, 810);

}

Scene::~Scene()
{

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

void Scene::addAnm(string pic, int x, int y, double width, double height)
{
    QLabel *gif_anim = new QLabel();
    QMovie *movie = new QMovie((":"+pic).c_str());
    movie->setScaledSize(QSize(width,height));
    gif_anim->setMovie(movie);
    movie->start();
    gif_anim->setGeometry(x, y, width, height);
    scene->addWidget(gif_anim);
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
    /*music->stop();
    delete music;*/
    scene->clear();
    createPage();
}


