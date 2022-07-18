#include "LossPage.h"
#include "Menu.h"

extern Menu* menu;

LossPage::LossPage()
{

}

void LossPage::createPage()
{
    button = new Button("Start","/images/image/bottonBack1.png", "/images/image/bottonBack2.png", 0.33, (1440-256)/2, (810-108)/2+100);
    addAnm("/images/image/YOU_LOSS.gif");
    scene->addItem(button);
    jumpPage(button, menu);
}

LossPage::~LossPage()
{
    scene->clear();
}
