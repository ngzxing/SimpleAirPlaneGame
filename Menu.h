#ifndef MENU_H
#define MENU_H

#include "Scene.h"
#include "Button.h"

class Menu: public Scene{

public:

    Menu();
    void createPage();

    Button* button;
};

#endif // MENU_H
