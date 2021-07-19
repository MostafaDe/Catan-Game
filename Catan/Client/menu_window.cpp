#include "menu_window.h"
#include<QVBoxLayout>

menu_window::menu_window(int *what, bool button_inable, QWidget *parent)
    :QDialog(parent)
    ,endOfTurn(new QPushButton(tr("end of turn")))
    ,buildHous(new QPushButton(tr("build house")))
    ,buildCity(new QPushButton(tr("build city")))
    ,buildRoad(new QPushButton(tr("build road")))
    ,what_(what)
{
    this->setWindowTitle("menu");
    QVBoxLayout*all=new QVBoxLayout(this);
    all->addWidget(endOfTurn);
    all->addWidget(buildRoad);
    all->addWidget(buildHous);
    all->addWidget(buildCity);

    set_inable(button_inable);

    connect(endOfTurn,SIGNAL(clicked()),this,SLOT(clicked_endOfTurn()));
    connect(buildHous,SIGNAL(clicked()),this,SLOT(clicked_buildHous()));
    connect(buildCity,SIGNAL(clicked()),this,SLOT(clicked_buildCity()));
    connect(buildRoad,SIGNAL(clicked()),this,SLOT(clicked_buildRoad()));

}

void menu_window::set_inable(bool is)
{
    endOfTurn->setEnabled(is);
    buildCity->setEnabled(is);
    buildRoad->setEnabled(is);
    buildHous->setEnabled(is);
}

void menu_window::clicked_endOfTurn()
{
    //some thing send to server
    this->close();
}

void menu_window::clicked_buildHous()
{
    *what_=2;
    emit value_changed();
    this->close();
}

void menu_window::clicked_buildCity()
{
    *what_=3;
    emit value_changed();
    this->close();
}

void menu_window::clicked_buildRoad()
{
    *what_=1;
    emit value_changed();
    this->close();
}
