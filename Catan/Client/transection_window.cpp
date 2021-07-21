#include "transection_window.h"
#include<QLabel>
#include<QDialogButtonBox>
#include<QGridLayout>
#include<QString>
#include<QJsonDocument>
#include<QJsonObject>

void transection_window::send_message(QJsonObject o)
{
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);
}


transection_window::transection_window(QTcpSocket *sock,QString userName, int sheepG, int sheepT, int wheatT, int wheatG, int treeT, int treeG, int rockG, int rockT, int brickT, int brickG, QWidget *parent)
    :QDialog(parent)
    ,tcpSocket(sock)
{
    QLabel* sheep=new QLabel(tr("sheep :"));
    QLabel* tree=new QLabel(tr("wood :"));
    QLabel* rock=new QLabel(tr("rock :"));
    QLabel* brick=new QLabel(tr("brick :"));
    QLabel* wheat=new QLabel(tr("wheat :"));

    QLabel* sheepGG=new QLabel(tr(QString::number(sheepG).toLatin1()));
    QLabel* treeGG=new QLabel(tr(QString::number(treeG).toLatin1()));
    QLabel* rockGG=new QLabel(tr(QString::number(rockG).toLatin1()));
    QLabel* brickGG=new QLabel(tr(QString::number(brickG).toLatin1()));
    QLabel* wheatGG=new QLabel(tr(QString::number(wheatG).toLatin1()));

    QLabel* sheepTT=new QLabel(tr(QString::number(sheepT).toLatin1()));
    QLabel* treeTT=new QLabel(tr(QString::number(treeT).toLatin1()));
    QLabel* rockTT=new QLabel(tr(QString::number(rockT).toLatin1()));
    QLabel* brickTT=new QLabel(tr(QString::number(brickT).toLatin1()));
    QLabel* wheatTT=new QLabel(tr(QString::number(wheatT).toLatin1()));

    ok=new QPushButton(tr("Ok"));
    cancel=new QPushButton(tr("Cancel"));
    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(ok,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancel,QDialogButtonBox::RejectRole);

    QLabel*user=new QLabel(tr(userName.toLatin1()+"want to"));
    QLabel*get=new QLabel(tr("get"));
    QLabel*take=new QLabel(tr("take"));




    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(user,0,0);
    mainLayout->addWidget(get,1,0);
    mainLayout->addWidget(take,2,0);

    mainLayout->addWidget(sheep,0,1);
    mainLayout->addWidget(sheepGG,1,1);
    mainLayout->addWidget(sheepTT,2,1);

    mainLayout->addWidget(tree,0,2);
    mainLayout->addWidget(treeGG,1,2);
    mainLayout->addWidget(treeTT,2,2);

    mainLayout->addWidget(rock,0,3);
    mainLayout->addWidget(rockGG,1,3);
    mainLayout->addWidget(rockTT,2,3);

    mainLayout->addWidget(brick,0,4);
    mainLayout->addWidget(brickGG,1,4);
    mainLayout->addWidget(brickTT,2,4);

    mainLayout->addWidget(wheat,0,5);
    mainLayout->addWidget(wheatGG,1,5);
    mainLayout->addWidget(wheatTT,2,5);

    mainLayout->addWidget(buttonBox,1,6,2,1);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);



    connect(ok,SIGNAL(clicked()),this,SLOT(clicked_ok()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(clicked_cancel()));
}

void transection_window::clicked_ok()
{
    QJsonObject o;
    o["kind"]="Game";
    o["kindOfGame"]="responseToTransactionToPlayers";
    o["answer"]=true;
    send_message(o);
    this->close();
}

void transection_window::clicked_cancel()
{
    QJsonObject o;
    o["kind"]="Game";
    o["kindOfGame"]="responseToTransactionToPlayers";
    o["answer"]=false;
    send_message(o);
    this->close();
}
