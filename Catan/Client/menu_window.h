#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include<QDialog>
#include<QPushButton>

class menu_window:public QDialog
{
public:
    menu_window(QWidget *parent = nullptr);

private:
    QPushButton*test;

};

#endif // MENU_WINDOW_H
