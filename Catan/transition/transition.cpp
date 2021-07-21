#include "transition.h"
#include"dilag_bank.h"
#include"dbank.h"
#include"tplayer.h"

Transition::Transition(QTcpSocket*sock,QWidget *parent) : QMainWindow(parent)
  ,tcpSocket(sock)
{
    c=new QWidget;
    v1=new QVBoxLayout;
    bbank=new QPushButton;
    bplayer=new QPushButton;
    Cb=new QComboBox;

    bbank->setText("Bank");
    bplayer->setText("player");
    v1->addWidget(bbank);
    v1->addWidget(bplayer);

    connect(bbank,SIGNAL(clicked()),this,SLOT(SBank()));
    connect(bplayer,SIGNAL(clicked()),this,SLOT(Splayer()));

    c->setLayout(v1);
    setCentralWidget(c);

}

void Transition::SBank()
{
    DBank *d=new DBank(tcpSocket);
    d->show();
}

void Transition::Splayer()
{
    TPlayer *p=new TPlayer(tcpSocket);
    p->show();
}
