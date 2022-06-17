#include "Menu.h"
#include "Game.h"

extern Game* game;

Menu::Menu() : Scene(){}

void Menu::createPage()
{

    button = new Button("Start", 100, 100, 100, 100, "darkCyan", "black", "times", 16);
    scene->addItem(button); // add buttom onto scene
    Scene::jumpPage(button, game);
};


