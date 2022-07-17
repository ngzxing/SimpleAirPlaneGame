#ifndef LOSSPAGE_H
#define LOSSPAGE_H

#include "Scene.h"
#include "Button.h"

class LossPage : public Scene{

public:
    LossPage();
    void createPage();
    ~LossPage();

private:
    Button* button;

};

#endif // LOSSPAGE_H
