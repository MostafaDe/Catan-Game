#include "graphic.h"
#include <QPixmap>
#include<QGraphicsPixmapItem>
#include<QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include"menu_window.h"


void graphic::set_lands()
{
    tcpSocket->waitForReadyRead(1000);
    QString readMess=tcpSocket->readAll();
    QJsonObject obj;
    QJsonDocument duc = QJsonDocument::fromJson(readMess.toUtf8());
    obj = duc.object();


    for(int i=1;i<29;i++)
    {
        QGraphicsPixmapItem*pix=new QGraphicsPixmapItem;
        pix->setPixmap(QPixmap(":/lands/Images/lands/"+obj["json1"].toObject()[QString::number(i)].toString()));
        pix->setScale(0.5);
        pix->setPos(pos.map_l[QString::number(i)].x-27,pos.map_l[QString::number(i)].y-30.5);
        scene->addItem(pix);

        QGraphicsPixmapItem*pixN=new QGraphicsPixmapItem;
        pixN->setPixmap(QPixmap(":/numbers/Images/numbers/"+QString::number(obj["json2"].toObject()[QString::number(i)].toInt())));
        pixN->setScale(0.6);
        pixN->setPos(pos.map_l[QString::number(i)].x-10,pos.map_l[QString::number(i)].y-10);
        scene->addItem(pixN);
    }
}

void graphic::set_score()
{
    me=new QGraphicsTextItem;
    me->setPlainText("my score: "+QString::number(player_->getScore()));

    if(player_->getColor()==Color::Blue)
        me->setDefaultTextColor(Qt::blue);
    else if(player_->getColor()==Color::Red)
        me->setDefaultTextColor(Qt::red);
    else if(player_->getColor()==Color::Yellow)
        me->setDefaultTextColor(Qt::yellow);
    else
        me->setDefaultTextColor(Qt::green);

    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    me->setPos(10,512-50);
    scene->addItem(me);





    comp1=new QGraphicsTextItem;
    comp1->setPlainText(player_->getCompetitors()[0].getUsername()+" score: "+QString::number(player_->getCompetitors()[0].getScore()));

    if(player_->getCompetitors()[0].getColor()==Color::Blue)
        comp1->setDefaultTextColor(Qt::blue);
    else if(player_->getCompetitors()[0].getColor()==Color::Red)
        comp1->setDefaultTextColor(Qt::red);
    else if(player_->getCompetitors()[0].getColor()==Color::Yellow)
        comp1->setDefaultTextColor(Qt::yellow);
    else
        comp1->setDefaultTextColor(Qt::green);

    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    comp1->setPos(10,512-75);
    scene->addItem(comp1);



    comp2=new QGraphicsTextItem;
    comp2->setPlainText(player_->getCompetitors()[1].getUsername()+" score: "+QString::number(player_->getCompetitors()[0].getScore()));

    if(player_->getCompetitors()[1].getColor()==Color::Blue)
        comp2->setDefaultTextColor(Qt::blue);
    else if(player_->getCompetitors()[1].getColor()==Color::Red)
        comp2->setDefaultTextColor(Qt::red);
    else if(player_->getCompetitors()[1].getColor()==Color::Yellow)
        comp2->setDefaultTextColor(Qt::yellow);
    else
        comp2->setDefaultTextColor(Qt::green);

    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    comp2->setPos(10,512-100);
    scene->addItem(comp2);

}

void graphic::clicked_menu()
{
    menu_window *M=new menu_window(this);
    M->show();
}

graphic::graphic(Player*player_1,QTcpSocket*Socket1,QWidget *parent)
    :QGraphicsView(parent)
    ,player_(player_1)
    ,tcpSocket(Socket1)
{
    QJsonObject o;
    o["kind"] = "Game";
    o["kindOfGame"]="getBordInformation";
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);


    this->setWindowTitle("catan");

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,720,512);
    setBackgroundBrush(QBrush(QImage(":/lands/Images/lands/back")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(720,512);

    set_lands();
    set_score();

    menu=new QPushButton(this);
    menu->setIcon(QIcon(":/buttons/Images/menu_button"));
    menu->setIconSize(QSize(90,30));
    menu->setGeometry(QRect(0,0,90,30));
    scene->addWidget(menu);
    menu->setFocus();

    connect(menu,SIGNAL(clicked()),this,SLOT(clicked_menu()));

}



