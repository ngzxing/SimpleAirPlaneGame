#include <QApplication>
#include "Menu.h"
#include "Game.h"
#include "Scene.h"
#include "LossPage.h"
#include "WinPage.h"
#include "TryPage.h"
#include <QMediaPlayer>

QGraphicsScene* Scene::scene;
QGraphicsView* Scene::view;
Status<int>* score;
Menu* menu;
Game* game;
LossPage* lossPage;
WinPage* winPage;
TryPage* tryPage;
QMediaPlayer* music;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scene::scene = new QGraphicsScene();
    Scene::view = new QGraphicsView();
    menu = new Menu();
    game = new Game();
    lossPage = new LossPage();
    winPage = new WinPage();
    tryPage = new TryPage();

    winPage->createPage();
    Scene::view->show();

    return a.exec();
}
