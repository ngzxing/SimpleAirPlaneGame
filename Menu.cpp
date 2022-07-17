#include "Menu.h"
#include "Game.h"
#include "WinPage.h"
#include <QMovie>
#include <QLabel>
#include <QLineEdit>
#include <QMediaPlayer>

extern Game* game;
extern QMediaPlayer* music;
extern WinPage* winPage;

Menu::Menu() : Scene(){}

void Menu::createPage()
{

    button = new Button("Start","/images/image/bottonStart1.png", "/images/image/bottonStart2.png", 0.42, (1440-267)/2, (810-108)/2+50);
    //addAnm("/images/image/STAR_WARS.gif", 0,0,1440,810);
    scene->addItem(button);
    /*music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sound/intro.m4a"));
    music->play();*/

    Scene::jumpPage(button, winPage);
}

Menu::~Menu()
{
    scene->clear();
};


