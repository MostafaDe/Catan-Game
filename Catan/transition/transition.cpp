#include "transition.h"
#include"dilag_bank.h"
#include"dbank.h"
#include"tplayer.h"
Transition::Transition(QWidget *parent) : QMainWindow(parent)
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

//    Dilag_bank *d=new Dilag_bank();
//      d->show();

    DBank *d=new DBank();
    d->show();



}

void Transition::Splayer()
{
    TPlayer *p=new TPlayer();
    p->show();




}
