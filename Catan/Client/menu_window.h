#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include<QDialog>
#include<QPushButton>

class menu_window:public QDialog
{
    Q_OBJECT
public:
    menu_window(int *what,bool button_inable,QWidget *parent = nullptr);

private:
    QPushButton*endOfTurn,*buildHous,*buildCity,*buildRoad;
    void set_inable(bool is);
    int *what_;

public slots:
    void clicked_endOfTurn();
    void clicked_buildHous();
    void clicked_buildCity();
    void clicked_buildRoad();

signals:
    void value_changed();

};

#endif // MENU_WINDOW_H
