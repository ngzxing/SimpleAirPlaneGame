#ifndef WINPAGE_H
#define WINPAGE_H

#include "Scene.h"
#include "Button.h"

class WinPage : public Scene{

public:
    WinPage();
    void createPage(); // define how the page shown
    ~WinPage();

private:
    Button* button; //composition

};


#endif // WINPAGE_H
