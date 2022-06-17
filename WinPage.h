#ifndef WINPAGE_H
#define WINPAGE_H

#include "Scene.h"
#include "Button.h"

class WinPage : public Scene{

public:
    WinPage();
    void createPage();

private:
    Button* button;

};


#endif // WINPAGE_H
