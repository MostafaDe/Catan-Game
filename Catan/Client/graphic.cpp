#include "graphic.h"
#include <QPixmap>
#include<QGraphicsPixmapItem>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>

#include"menu_window.h"


QString convertColorToString(Color color)
{
    switch (color) {
    case Color::Blue:
        return "Blue";
    case Color::Red:
        return "Red";
    case Color::Green:
        return "Green";
    case Color::Yellow:
        return "Yellow";

    }
}

void graphic::set_lands()
{
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
    me_box=new QGraphicsRectItem(14,40,125,30);
    me_box->setBrush(set_color(convertColorToString(player_->getColor())));
    scene->addItem(me_box);
    me=new QGraphicsTextItem;
    me->setPlainText("my score:"+QString::number(player_->getScore()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    me->setPos(16,41);
    scene->addItem(me);

    comp1_box=new QGraphicsRectItem(14,78,125,30);
    comp1_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[0].getColor())));
    scene->addItem(comp1_box);
    comp1=new QGraphicsTextItem;
    comp1->setPlainText(player_->getCompetitors()[0].getUsername()+": "+QString::number(player_->getCompetitors()[0].getScore()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    comp1->setPos(16,79);
    scene->addItem(comp1);

    comp2_box=new QGraphicsRectItem(14,116,125,30);
    comp2_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[1].getColor())));
    scene->addItem(comp2_box);
    comp2=new QGraphicsTextItem;
    comp2->setPlainText(player_->getCompetitors()[1].getUsername()+": "+QString::number(player_->getCompetitors()[1].getScore()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    comp2->setPos(16,117);
    scene->addItem(comp2);


    if(player_->getCompetitors().size()>2)
    {
        comp3_box=new QGraphicsRectItem(14,164,125,30);
        comp3_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[2].getColor())));
        scene->addItem(comp3_box);
        comp3=new QGraphicsTextItem;
        comp3->setPlainText(player_->getCompetitors()[2].getUsername()+": "+QString::number(player_->getCompetitors()[2].getScore()));
        setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
        comp3->setPos(16,165);
        scene->addItem(comp3);
    }

}

void graphic::set_resource()
{
    if(player_->getCompetitors().size()>2)
            resource_box=new QGraphicsRectItem(14,205,125,225);
    else
            resource_box=new QGraphicsRectItem(14,175,125,225);

    resource_box->setBrush(QColor(52,48,48));
    scene->addItem(resource_box);
}

void graphic::show_message(QString mess_)
{
    mess=new QGraphicsTextItem;
    mess->setPlainText(mess_);
    mess->setDefaultTextColor(QColor(256,256,256));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    mess->setPos(145,505);
    scene->addItem(mess);
}

void graphic::clicked_menu()
{
    menu_window *M=new menu_window(this);
    M->show();
}

void graphic::read()
{
    QString readMess=tcpSocket->readAll();
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(readMess.toUtf8());

    obj = doc.object();
    qDebug() << obj;

    if(obj["kindOfGame"].toString() == "getBoardInformation")
    {
        this->obj = obj;
        set_lands();
        set_score();
        set_resource();
        player_->setIsTurn(obj["myTurn"].toBool());
    }

    if(obj["kindOfGame"] == "responseTobuildHouse")
    {
        if(obj["success"].toBool())
        {

            QJsonArray arr=obj["position"].toArray();
            position_for_graphics centerOfShape=set_center(3,arr);


            if(obj["kindOfBuilding"]=="house")
            {
                auto circle = new QGraphicsEllipseItem(centerOfShape.x-5, centerOfShape.y-5, 10, 10);
                circle->setBrush(set_color(obj["color"].toString()));
                scene->addItem(circle);
            }
            else
            {
                //city

                QGraphicsRectItem *rec=new QGraphicsRectItem(centerOfShape.x-5, centerOfShape.y-5, 10, 10);
                rec->setBrush(set_color(obj["color"].toString()));
                scene->addItem(rec);
            }

            if(convertColorToString(player_->getColor())==obj["color"].toString())
            {
                show_message(obj["message"].toString());
            }

        }
        else if(convertColorToString(player_->getColor())==obj["color"].toString())
        {
            show_message(obj["errorMessage"].toString());
        }
    }

    else if(obj["kindOfGame"].toString() == "responseTobuildRoad")
    {

        if(obj["success"].toBool())
        {
            QJsonArray arr=obj["position"].toArray();
            position_for_graphics centerOfShape=set_center(2,arr);

            QGraphicsRectItem *rec=new QGraphicsRectItem(centerOfShape.x-4, centerOfShape.y-10, 8, 20);
            rec->setBrush(set_color(obj["color"].toString()));
            rec->setTransformOriginPoint(centerOfShape.x, centerOfShape.y);

            position_for_graphics p1={pos.map_l[QString::number(arr[0].toInt())].x,pos.map_l[QString::number(arr[0].toInt())].y};
            position_for_graphics p2={pos.map_l[QString::number(arr[1].toInt())].x,pos.map_l[QString::number(arr[1].toInt())].y};

            if(p1.y==p2.y)
            {

            }
            else if((p1.x<p2.x && p1.y>p2.y)  ||  (p2.x<p1.x && p2.y>p1.y))
            {
                rec->setRotation(-60);
            }
            else
            {
                rec->setRotation(60);
            }

            scene->addItem(rec);


            if(convertColorToString(player_->getColor())==obj["color"].toString())
            {
                show_message(obj["message"].toString());
            }

        }
        else if(convertColorToString(player_->getColor())==obj["color"].toString())
        {
            show_message(obj["errorMessage"].toString());
        }
    }

    else if(obj["kindOfGame"].toString() == "transactionToPlayers")
    {


    }

}

graphic::graphic(Player*player_1,QTcpSocket*Socket1,QWidget *parent)
    :QGraphicsView(parent)
    ,player_(player_1)
    ,tcpSocket(Socket1)
{
    QJsonObject o;
    o["kind"] = "Game";
    o["kindOfGame"]="getBoardInformation";
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


    menu=new QPushButton(this);
    menu->setIcon(QIcon(":/buttons/Images/menu_button.png"));
    menu->setIconSize(QSize(22,19));
    menu->setGeometry(QRect(14,13,22,19));
    scene->addWidget(menu);
    menu->setFocus();

    connect(menu,SIGNAL(clicked()),this,SLOT(clicked_menu()));
    connect(tcpSocket,&QTcpSocket::readyRead,this,&graphic::read);

}

position_for_graphics graphic::set_center(int num, QJsonArray arr)
{
        position_for_graphics centerOfShape={0,0};
        for(int i=0;i<num;i++)
        {
            centerOfShape.x += pos.map_l[QString::number(arr[i].toInt())].x;
            centerOfShape.y += pos.map_l[QString::number(arr[i].toInt())].y;
        }
        centerOfShape.x/=num;
        centerOfShape.y/=num;

        return centerOfShape;
}

QColor graphic::set_color(QString str)
{
    if(str=="Blue")
        return QColor(51,77,210);
    else if(str=="Red")
        return QColor(210,51,51);
    else if(str=="Green")
        return QColor(103,210,51);
    else
        return QColor(210,186,51);
}
