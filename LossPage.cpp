#include "LossPage.h"
#include "Menu.h"

extern Menu* menu;

LossPage::LossPage()
{

}

void LossPage::createPage()
{
    addText("You Loss", 0, 0, "red", "times", 20);
    button = new Button("Back", 100, 100, 100, 100, "darkCyan", "black", "times", 16);
    scene->addItem(button);
    jumpPage(button, menu);

}
