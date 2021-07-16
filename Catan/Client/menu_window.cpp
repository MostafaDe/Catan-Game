#include "menu_window.h"

menu_window::menu_window(QWidget *parent)
    :QDialog(parent)
{
    test=new QPushButton(this);
    test->setText("test");
}
