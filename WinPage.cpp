#include "WinPage.h"
#include "Menu.h"
#include "LossPage.h"

extern Menu* menu;
extern LossPage* lossPage;

WinPage::WinPage()
{

}

void WinPage::createPage()
{
    button = new Button("Start","/images/image/bottonBack1.png", "/images/image/bottonBack2.png", 0.33, 1000, 810-108-125);
    addAnm("/images/image/VICTORY.gif");
    scene->addItem(button);
    jumpPage(button, menu);
}

WinPage::~WinPage()
{
    scene->clear();
}
