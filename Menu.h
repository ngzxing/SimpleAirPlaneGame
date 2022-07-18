#ifndef MENU_H
#define MENU_H

#include "Scene.h"
#include "Button.h"

class Menu: public Scene{

public:

    Menu();
    void createPage(); // define how the page shown
    ~Menu();

    Button* button; // composition
};

#endif // MENU_H
