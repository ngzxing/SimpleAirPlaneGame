#include "LossPage.h"
#include "Menu.h"
#include <QMediaPlayer>

extern Menu* menu;
extern QMediaPlayer* music;

LossPage::LossPage()
{

}

void LossPage::createPage()
{
    button = new Button("Start","/images/image/bottonBack1.png", "/images/image/bottonBack2.png", 0.33, (1440-256)/2, (810-108)/2+100);
    //addAnm("/images/image/YOU_LOSS.gif");

    /*music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sound/outro.m4a"));
    music->play();*/
    scene->addItem(button);
    jumpPage(button, menu);
}

LossPage::~LossPage()
{
    scene->clear();
}
