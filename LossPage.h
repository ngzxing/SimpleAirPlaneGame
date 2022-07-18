#ifndef LOSSPAGE_H
#define LOSSPAGE_H

#include "Scene.h"
#include "Button.h"

class LossPage : public Scene{

public:
    LossPage();
    void createPage(); // define how the page shown
    ~LossPage();

private:
    Button* button; // composition

};

#endif // LOSSPAGE_H
