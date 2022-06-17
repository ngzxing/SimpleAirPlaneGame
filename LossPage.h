#ifndef LOSSPAGE_H
#define LOSSPAGE_H

#include "Scene.h"
#include "Button.h"

class LossPage : public Scene{

public:
    LossPage();
    void createPage();

private:
    Button* button;

};

#endif // LOSSPAGE_H
