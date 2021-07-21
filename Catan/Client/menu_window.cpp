#include "menu_window.h"
#include<QVBoxLayout>
#include<QJsonObject>
#include<QJsonDocument>
#include"transition/transition.h"

void menu_window:: delete_selected()
{
    for(int i=0;i<selected_land_->size();i++)
    {
            delete (*selected_land_pix_)[(*selected_land_)[i]];
            selected_land_pix_->remove((*selected_land_)[i]);
    }
    selected_land_->clear();
}

menu_window::menu_window(QMap<int,QGraphicsPixmapItem*> &selected_land_pix,QVector<int>&selected_land,int *what, bool turn,QTcpSocket*socket, QWidget *parent)
    :QDialog(parent)
    ,endOfTurn(new QPushButton(tr("end of turn")))
    ,buildHous(new QPushButton(tr("build house")))
    ,buildCity(new QPushButton(tr("build city")))
    ,buildRoad(new QPushButton(tr("build road")))
    ,transiton_(new QPushButton(tr("transiton")))
    ,what_(what)
    ,turn_(turn)
    ,selected_land_pix_(&selected_land_pix)
    ,selected_land_(&selected_land)
    ,tcpSocket(socket)
{
    this->setWindowTitle("menu");
    QVBoxLayout*all=new QVBoxLayout(this);
    all->addWidget(endOfTurn);
    all->addWidget(buildRoad);
    all->addWidget(buildHous);
    all->addWidget(buildCity);
    all->addWidget(transiton_);

    set_inable(what_,turn_);

    connect(endOfTurn,SIGNAL(clicked()),this,SLOT(clicked_endOfTurn()));
    connect(buildHous,SIGNAL(clicked()),this,SLOT(clicked_buildHous()));
    connect(buildCity,SIGNAL(clicked()),this,SLOT(clicked_buildCity()));
    connect(buildRoad,SIGNAL(clicked()),this,SLOT(clicked_buildRoad()));
    connect(transiton_,SIGNAL(clicked()),this,SLOT(clicked_transiton_()));

}

void menu_window::set_inable(int* button, bool turn_)
{
    if(turn_&&!(*button))
        return;

    if(!turn_)
    {
        endOfTurn->setEnabled(0);
        buildCity->setEnabled(0);
        buildRoad->setEnabled(0);
        buildHous->setEnabled(0);
        transiton_->setEnabled(0);
    }

    else if(*button==1)
    {
        endOfTurn->setEnabled(0);
        buildCity->setEnabled(0);
        buildRoad->setEnabled(1);
        buildHous->setEnabled(0);
        transiton_->setEnabled(0);
    }
    else if(*button==2)
    {
        endOfTurn->setEnabled(0);
        buildCity->setEnabled(0);
        buildRoad->setEnabled(0);
        buildHous->setEnabled(1);
        transiton_->setEnabled(0);
    }
    else if(*button==3)
    {
        endOfTurn->setEnabled(0);
        buildCity->setEnabled(1);
        buildRoad->setEnabled(0);
        buildHous->setEnabled(0);
        transiton_->setEnabled(0);
    }
}


void menu_window::clicked_endOfTurn()
{
    QJsonObject o;
    o["kind"]="Game";
    o["kindOfGame"]="endOfTurn";
    send_message(o);
    this->close();
}

void menu_window::clicked_buildHous()
{
    if(*what_==2)
    {
        *what_=0;
        delete_selected();
        this->close();
        return;
    }
    *what_=2;
    this->close();
}

void menu_window::clicked_buildCity()
{
    if(*what_==3)
    {
        *what_=0;
        delete_selected();
        this->close();
        return;
    }
    *what_=3;
    this->close();
}

void menu_window::clicked_buildRoad()
{
    if(*what_==1)
    {
        *what_=0;
        delete_selected();
        this->close();
        return;
    }
    *what_=1;
    this->close();
}

void menu_window::clicked_transiton_()
{
    Transition*w=new Transition(tcpSocket);
    w->show();
    this->close();
}

void menu_window::send_message(QJsonObject o)
{
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);
}
