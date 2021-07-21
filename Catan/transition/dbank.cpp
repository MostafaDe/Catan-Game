#include "dbank.h"
#include<QDebug>
#include<QJsonDocument>

DBank::DBank(QTcpSocket*sock,QWidget *parent) : QMainWindow(parent)
  ,tcpSocket(sock)
{


    c=new QWidget;
    v1=new QVBoxLayout;
    bOk=new QPushButton;
    bCansel=new QPushButton;
    Cbg=new QComboBox;
    Cbt=new QComboBox;
    l1=new QLabel;
    l2=new QLabel;
    h1=new QHBoxLayout;
     h2=new QHBoxLayout;
     h3=new QHBoxLayout;

l1->setText("somthinng  you take:");
l2->setText("somthinng  you give:");

bOk->setText("Ok");
bCansel->setText("cancel");
Cbg->addItem("brick");
Cbg->addItem("wheat");
Cbg->addItem("Wood");
Cbg->addItem("rock");
Cbg->addItem("sheep");

Cbt->addItem("brick");
Cbt->addItem("wheat");
Cbt->addItem("Wood");
Cbt->addItem("rock");
Cbt->addItem("sheep");


h1->addWidget(l1);
h1->addWidget(Cbt);
h2->addWidget(l2);
h2->addWidget(Cbg);
h3->addWidget(bOk);
//h3->addWidget(bCansel);

v1->addLayout(h1);
v1->addLayout(h2);
v1->addLayout(h3);
c->setLayout(v1);
 l2->setStyleSheet("background-color: rgb(100,225,0);");
l1->setStyleSheet("background-color: rgb(200,25,0);");
qDebug() << Cbt->currentText();
   connect(bOk,SIGNAL(clicked()),this,SLOT(SOk()));

setCentralWidget(c);

}

void DBank::SOk()
{

    qDebug() << Cbt->currentText();

    QJsonObject boos,deal;

    boos["kind"]="Game";
    boos["kindOfGame"]="transactionToBank";

    if("brick"== Cbt->currentText()){


     deal["brickT"]=4;
     deal["woodT"]=0;
     deal["sheepT"]=0;
     deal["wheatT"]=0;
     deal["rockT"]=0;





    }
    else if("sheep"== Cbt->currentText()){
        deal["brickT"]=0;
        deal["woodT"]=0;
        deal["sheepT"]=4;
        deal["wheatT"]=0;
        deal["rockT"]=0;

    }
    else if("Wood"==Cbt->currentText()){
        deal["brickT"]=0;
        deal["woodT"]=4;
        deal["sheepT"]=0;
        deal["wheatT"]=0;
        deal["rockT"]=0;

    }

    else if("wheat"==Cbt->currentText()){

        deal["brickT"]=0;
        deal["woodT"]=0;
        deal["sheepT"]=0;
        deal["wheatT"]=4;
        deal["rockT"]=0;
    }
    else if("rock"==Cbt->currentText()){
        deal["brickT"]=0;
        deal["woodT"]=0;
        deal["sheepT"]=0;
        deal["wheatT"]=0;
        deal["rockT"]=4;

    }





    if("brick"== Cbg->currentText()){


     deal["brickG"]=1;
     deal["woodG"]=0;
     deal["sheepG"]=0;
     deal["wheatG"]=0;
     deal["rockG"]=0;





    }
    else if("sheep"== Cbg->currentText()){
        deal["brickG"]=0;
        deal["woodG"]=0;
        deal["sheepG"]=1;
        deal["wheatG"]=0;
        deal["rockG"]=0;

    }
    else if("Wood"==Cbg->currentText()){
        deal["brickG"]=0;
        deal["woodG"]=1;
        deal["sheepG"]=0;
        deal["wheatG"]=0;
        deal["rockG"]=0;

    }

    else if("wheat"==Cbg->currentText()){

        deal["brickG"]=0;
        deal["woodG"]=0;
        deal["sheepG"]=0;
        deal["wheatG"]=1;
        deal["rockG"]=0;
    }
    else if("rock"==Cbg->currentText()){
        deal["brickG"]=0;
        deal["woodG"]=0;
        deal["sheepG"]=0;
        deal["wheatG"]=0;
        deal["rockG"]=1;

    }

boos["deal"]=deal;

send_message(boos);















}

void DBank::send_message(QJsonObject o)
{
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);
}
