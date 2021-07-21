#include "tplayer.h"
#include<QJsonDocument>

TPlayer::TPlayer(QTcpSocket*sock,QWidget *parent) : QMainWindow(parent)
  ,tcpSocket(sock)
{
    c=new QWidget;
    v1=new QVBoxLayout;
    bOk=new QPushButton;

    h1=new QHBoxLayout;
    h2=new QHBoxLayout;
    h3=new QHBoxLayout;
    h4=new QHBoxLayout;
    h5=new QHBoxLayout;
    h6=new QHBoxLayout;
    h7=new QHBoxLayout;
    h8=new QHBoxLayout;
    h9=new QHBoxLayout;
    h10=new QHBoxLayout;

    Cbgr=new QComboBox;
    Cbgwh=new QComboBox;
    Cbgwo=new QComboBox;
    Cbgsh=new QComboBox;
    Cbgb=new QComboBox;

    Cbtr=new QComboBox;
    Cbtwh=new QComboBox;
    Cbtwo=new QComboBox;
    Cbtsh=new QComboBox;
    Cbtb=new QComboBox;

    l1=new QLabel;
    l2=new QLabel;
    l3=new QLabel;
    l4=new QLabel;
    l5=new QLabel;
    l6=new QLabel;
    l7=new QLabel;
    l8=new QLabel;
    l9=new QLabel;
    l10=new QLabel;
    l11=new QLabel;
    l12=new QLabel;

    Cbgb->addItem("0");
    Cbgb->addItem("1");
    Cbgb->addItem("2");
    Cbgb->addItem("3");
    Cbgb->addItem("4");
    Cbgb->addItem("5");
    Cbgb->addItem("6");
    Cbgb->addItem("7");
    Cbgb->addItem("8");
    Cbgb->addItem("9");
    Cbgb->addItem("10");
    Cbgb->addItem("11");
    Cbgb->addItem("12");
    Cbgb->addItem("13");
    Cbgb->addItem("14");

    Cbgr->addItem("0");
    Cbgr->addItem("1");
    Cbgr->addItem("2");
    Cbgr->addItem("3");
    Cbgr->addItem("4");
    Cbgr->addItem("5");
    Cbgr->addItem("6");
    Cbgr->addItem("7");
    Cbgr->addItem("8");
    Cbgr->addItem("9");
    Cbgr->addItem("10");
    Cbgr->addItem("11");
    Cbgr->addItem("12");
    Cbgr->addItem("13");
    Cbgr->addItem("14");

    Cbgsh->addItem("0");
    Cbgsh->addItem("1");
    Cbgsh->addItem("2");
    Cbgsh->addItem("3");
    Cbgsh->addItem("4");
    Cbgsh->addItem("5");
    Cbgsh->addItem("6");
    Cbgsh->addItem("7");
    Cbgsh->addItem("8");
    Cbgsh->addItem("9");
    Cbgsh->addItem("10");
    Cbgsh->addItem("11");
    Cbgsh->addItem("12");
    Cbgsh->addItem("13");
    Cbgsh->addItem("14");

    Cbgwo->addItem("0");
    Cbgwo->addItem("1");
    Cbgwo->addItem("2");
    Cbgwo->addItem("3");
    Cbgwo->addItem("4");
    Cbgwo->addItem("5");
    Cbgwo->addItem("6");
    Cbgwo->addItem("7");
    Cbgwo->addItem("8");
    Cbgwo->addItem("9");
    Cbgwo->addItem("10");
    Cbgwo->addItem("11");
    Cbgwo->addItem("12");
    Cbgwo->addItem("13");
    Cbgwo->addItem("14");

    Cbgwh->addItem("0");
    Cbgwh->addItem("1");
    Cbgwh->addItem("2");
    Cbgwh->addItem("3");
    Cbgwh->addItem("4");
    Cbgwh->addItem("5");
    Cbgwh->addItem("6");
    Cbgwh->addItem("7");
    Cbgwh->addItem("8");
    Cbgwh->addItem("9");
    Cbgwh->addItem("10");
    Cbgwh->addItem("11");
    Cbgwh->addItem("12");
    Cbgwh->addItem("13");
    Cbgwh->addItem("14");

    Cbtb->addItem("0");
    Cbtb->addItem("1");
    Cbtb->addItem("2");
    Cbtb->addItem("3");
    Cbtb->addItem("4");
    Cbtb->addItem("5");
    Cbtb->addItem("6");
               Cbtb->addItem("7");
                Cbtb->addItem("8");
                Cbtb->addItem("9");
                Cbtb->addItem("10");
               Cbtb->addItem("11");
                Cbtb->addItem("12");
                Cbtb->addItem("13");
                Cbtb->addItem("14");

  Cbtr->addItem("0");
                Cbtr->addItem("1");
                 Cbtr->addItem("2");
                 Cbtr->addItem("3");
                 Cbtr->addItem("4");
                 Cbtr->addItem("5");
                 Cbtr->addItem("6");
                 Cbtr->addItem("7");
                  Cbtr->addItem("8");
                  Cbtr->addItem("9");
                  Cbtr->addItem("10");
                 Cbtr->addItem("11");
                  Cbtr->addItem("12");
                  Cbtr->addItem("13");
                  Cbtr->addItem("14");

 Cbtsh->addItem("0");
                  Cbtsh->addItem("1");
                   Cbtsh->addItem("2");
                   Cbtsh->addItem("3");
                   Cbtsh->addItem("4");
                   Cbtsh->addItem("5");
                   Cbtsh->addItem("6");
                   Cbtsh->addItem("7");
                    Cbtsh->addItem("8");
                    Cbtsh->addItem("9");
                    Cbtsh->addItem("10");
                   Cbtsh->addItem("11");
                    Cbtsh->addItem("12");
                    Cbtsh->addItem("13");
                    Cbtsh->addItem("14");



 Cbtwo->addItem("0");
                    Cbtwo->addItem("1");
                     Cbtwo->addItem("2");
                     Cbtwo->addItem("3");
                     Cbtwo->addItem("4");
                     Cbtwo->addItem("5");
                     Cbtwo->addItem("6");
                     Cbtwo->addItem("7");
                      Cbtwo->addItem("8");
                      Cbtwo->addItem("9");
                      Cbtwo->addItem("10");
                     Cbtwo->addItem("11");
                      Cbtwo->addItem("12");
                      Cbtwo->addItem("13");
                      Cbtwo->addItem("14");


  Cbtwh->addItem("0");
                      Cbtwh->addItem("1");
                       Cbtwh->addItem("2");
                       Cbtwh->addItem("3");
                       Cbtwh->addItem("4");
                       Cbtwh->addItem("5");
                       Cbtwh->addItem("6");
                       Cbtwh->addItem("7");
                        Cbtwh->addItem("8");
                        Cbtwh->addItem("9");
                        Cbtwh->addItem("10");
                       Cbtwh->addItem("11");
                        Cbtwh->addItem("12");
                        Cbtwh->addItem("13");
                        Cbtwh->addItem("14");
l1->setText("get somting:");

l2->setText("take somting:");
l3->setText("brick");

l4->setText("wood:");

l5->setText("wheat");

l6->setText("sheep");
l7->setText("rock");


l8->setText("brick");

l9->setText("wood:");

l10->setText("wheat");

l11->setText("sheep");
l12->setText("rock");










bOk->setText("Ok");
                         v1->addWidget(l1);

                         h1->addWidget(l3);
                         h1->addWidget(Cbgb);
                         h2->addWidget(l4);
                         h2->addWidget(Cbgwo);



                         h3->addWidget(l5);
                         h3->addWidget(Cbgwh);




                         h4->addWidget(l6);
                         h4->addWidget(Cbgsh);



                         h5->addWidget(l7);
                         h5->addWidget(Cbgr);


                         h6->addWidget(l8);
                         h6->addWidget(Cbtb);


                         h7->addWidget(l9);
                         h7->addWidget(Cbtwo);


                         h8->addWidget(l10);
                         h8->addWidget(Cbtwh);


                         h9->addWidget(l11);
                         h9->addWidget(Cbtsh);


                         h10->addWidget(l12);
                         h10->addWidget(Cbtr);




                         v1->addLayout(h1);
                         v1->addLayout(h2);
                         v1->addLayout(h3);
                         v1->addLayout(h4);

                         v1->addLayout(h5);






                        v1->addWidget(l2);


                        v1->addLayout(h6);
                        v1->addLayout(h7);
                        v1->addLayout(h8);
                        v1->addLayout(h9);
                        v1->addLayout(h10);



                        v1->addWidget(bOk);
 connect(bOk,SIGNAL(clicked()),this,SLOT(SOk()));
                        c->setLayout(v1);
                         l2->setStyleSheet("background-color: rgb(100,225,0);");
                        l1->setStyleSheet("background-color: rgb(200,25,0);");
                        setCentralWidget(c);





}

void TPlayer::SOk()
{

    if(Cbgb->currentText().toInt()!=0&&Cbtb->currentText().toInt()!=0||Cbgsh->currentText().toInt()!=0&&Cbtsh->currentText().toInt()!=0||Cbgwo->currentText().toInt()!=0&&Cbtwo->currentText().toInt()!=0||Cbgwh->currentText().toInt()!=0&&Cbtwh->currentText().toInt()!=0||Cbgr->currentText().toInt()!=0&&Cbtr->currentText().toInt()!=0){

     c->setStyleSheet("background-color: rgb(100,0,0);");



    }

    else
    {

    QJsonObject boos,deal;

    boos["kind"]="Game";
    boos["kindOfGame"]="transactionToPlayer";

    deal["brickT"]=Cbgb->currentText().toInt();
    deal["woodT"]=Cbgwo->currentText().toInt();
    deal["sheepT"]=Cbgsh->currentText().toInt();
    deal["wheatT"]=Cbgwh->currentText().toInt();
    deal["rockT"]=Cbgr->currentText().toInt();

    deal["brickG"]=Cbgb->currentText().toInt();
    deal["woodG"]=Cbgwo->currentText().toInt();
    deal["sheepG"]=Cbgsh->currentText().toInt();
    deal["wheatG"]=Cbgwh->currentText().toInt();
    deal["rockG"]=Cbgr->currentText().toInt();
    boos["deal"]=deal;

    send_message(boos);
    connect(bOk,SIGNAL(clicked()),this,SLOT(close()));

    }

}

void TPlayer::send_message(QJsonObject o)
{
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);
}
