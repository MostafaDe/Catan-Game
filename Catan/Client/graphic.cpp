#include "graphic.h"
#include <QPixmap>
#include<QGraphicsPixmapItem>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<math.h>
#include<QDebug>
#include<QtAlgorithms>
#include<QMouseEvent>
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
    if(!me_box)
        delete me_box;
    me_box=new QGraphicsRectItem(14,40,125,30);
    me_box->setBrush(set_color(convertColorToString(player_->getColor())));
    scene->addItem(me_box);
    if(!me)
        delete me;
    me=new QGraphicsTextItem;
    me->setPlainText("my score: "+QString::number(player_->getScore()));
    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    me->setPos(16,41);
    scene->addItem(me);

    if(!comp1_box)
        delete comp1_box;
    comp1_box=new QGraphicsRectItem(14,78,125,30);
    comp1_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[0].getColor())));
    scene->addItem(comp1_box);
    if(!comp1)
        delete comp1;
    comp1=new QGraphicsTextItem;
    comp1->setPlainText(player_->getCompetitors()[0].getUsername()+": "+QString::number(player_->getCompetitors()[0].getScore()));
    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    comp1->setPos(16,79);
    scene->addItem(comp1);

    if(!comp2_box)
        delete comp2_box;
    comp2_box=new QGraphicsRectItem(14,116,125,30);
    comp2_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[1].getColor())));
    scene->addItem(comp2_box);
    if(!comp2)
        delete comp2;
    comp2=new QGraphicsTextItem;
    comp2->setPlainText(player_->getCompetitors()[1].getUsername()+": "+QString::number(player_->getCompetitors()[1].getScore()));
    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    comp2->setPos(16,117);
    scene->addItem(comp2);


    if(player_->getCompetitors().size()>2)
    {
        if(!comp3_box)
            delete comp3_box;
        comp3_box=new QGraphicsRectItem(14,154,125,30);
        comp3_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[2].getColor())));
        scene->addItem(comp3_box);
        if(!comp3)
            delete comp3;
        comp3=new QGraphicsTextItem;
        comp3->setPlainText(player_->getCompetitors()[2].getUsername()+": "+QString::number(player_->getCompetitors()[2].getScore()));
        setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
        comp3->setPos(16,165);
        scene->addItem(comp3);
    }

}

void graphic::set_resource()
{
    if(!resource_box)
        delete resource_box;
    if(player_->getCompetitors().size()>2)
            resource_box=new QGraphicsRectItem(14,192,125,215);
    else
            resource_box=new QGraphicsRectItem(14,154,125,215);

    resource_box->setBrush(QColor(52,48,48));
    scene->addItem(resource_box);

    //tree
    if(!tree)
        delete tree;
    tree=new QGraphicsPixmapItem;
    tree->setPixmap(QPixmap(":/cards/Images/cards/tree_card.png"));
    tree->setScale(0.5);
    tree->setPos(resource_box->sceneBoundingRect().x()+5,resource_box->sceneBoundingRect().y()+5);
    scene->addItem(tree);
    if(!tree_)
        delete tree_;
    tree_=new QGraphicsTextItem;
    tree_->setPlainText(" : "+QString::number(player_->getCountOfWoodCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    tree_->setDefaultTextColor(QColor(225,225,225));
    tree_->setPos(tree->sceneBoundingRect().x()+tree->sceneBoundingRect().width()+5,tree->sceneBoundingRect().y()+tree->sceneBoundingRect().height()/2-5);
    scene->addItem(tree_);

    //sheep
    if(!sheep)
        delete sheep;
    sheep=new QGraphicsPixmapItem;
    sheep->setPixmap(QPixmap(":/cards/Images/cards/sheep_card.png"));
    sheep->setScale(0.5);
    sheep->setPos(tree->sceneBoundingRect().x(),tree->sceneBoundingRect().y()+5+tree->sceneBoundingRect().height());
    scene->addItem(sheep);
    if(!sheep_)
        delete sheep_;
    sheep_=new QGraphicsTextItem;
    sheep_->setPlainText(" : "+QString::number(player_->getCountOfWoodCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    sheep_->setDefaultTextColor(QColor(225,225,225));
    sheep_->setPos(sheep->sceneBoundingRect().x()+sheep->sceneBoundingRect().width()+5,sheep->sceneBoundingRect().y()+sheep->sceneBoundingRect().height()/2-5);
    scene->addItem(sheep_);

    //iron
    if(!iron)
        delete iron;
    iron=new QGraphicsPixmapItem;
    iron->setPixmap(QPixmap(":/cards/Images/cards/iron_card.png"));
    iron->setScale(0.5);
    iron->setPos(sheep->sceneBoundingRect().x(),sheep->sceneBoundingRect().y()+5+sheep->sceneBoundingRect().height());
    scene->addItem(iron);
    if(!iron_)
        delete iron_;
    iron_=new QGraphicsTextItem;
    iron_->setPlainText(" : "+QString::number(player_->getCountOfWoodCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    iron_->setDefaultTextColor(QColor(225,225,225));
    iron_->setPos(iron->sceneBoundingRect().x()+iron->sceneBoundingRect().width()+5,iron->sceneBoundingRect().y()+iron->sceneBoundingRect().height()/2-5);
    scene->addItem(iron_);

    //rock
    if(!rock)
        delete rock;
    rock=new QGraphicsPixmapItem;
    rock->setPixmap(QPixmap(":/cards/Images/cards/rock_card.png"));
    rock->setScale(0.5);
    rock->setPos(iron->sceneBoundingRect().x(),iron->sceneBoundingRect().y()+5+iron->sceneBoundingRect().height());
    scene->addItem(rock);
    if(!rock_)
        delete rock_;
    rock_=new QGraphicsTextItem;
    rock_->setPlainText(" : "+QString::number(player_->getCountOfWoodCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    rock_->setDefaultTextColor(QColor(225,225,225));
    rock_->setPos(rock->sceneBoundingRect().x()+rock->sceneBoundingRect().width()+5,rock->sceneBoundingRect().y()+rock->sceneBoundingRect().height()/2-5);
    scene->addItem(rock_);

    //wheat
    if(!wheat)
        delete wheat;
    wheat=new QGraphicsPixmapItem;
    wheat->setPixmap(QPixmap(":/cards/Images/cards/wheat_card.png"));
    wheat->setScale(0.5);
    wheat->setPos(rock->sceneBoundingRect().x(),rock->sceneBoundingRect().y()+5+rock->sceneBoundingRect().height());
    scene->addItem(wheat);
    if(!wheat_)
        delete wheat_;
    wheat_=new QGraphicsTextItem;
    wheat_->setPlainText(" : "+QString::number(player_->getCountOfWoodCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    wheat_->setDefaultTextColor(QColor(225,225,225));
    wheat_->setPos(wheat->sceneBoundingRect().x()+wheat->sceneBoundingRect().width()+5,wheat->sceneBoundingRect().y()+wheat->sceneBoundingRect().height()/2-5);
    scene->addItem(wheat_);

}

void graphic::send_message(QJsonObject o)
{
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
}

void graphic::show_message(QString mess_)
{
    mess->setPlainText(mess_);

    if(timer!=NULL)
        delete timer;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(arase_message()));
    timer->start(5000);
}

int graphic::find_nearest_land(int x, int y)
{
    int land=-18;
    double l=distance_of_points(pos.map_l["-18"],x,y);
    for(int i=-18;i<29;i++)
    {
        if(!i)
            continue;
        int l2=distance_of_points(pos.map_l[QString::number(i)],x,y);
        if(l2<l)
        {
            land=i;
            l=l2;
        }
    }
    return land;

}

double graphic::distance_of_points(position_for_graphics a, int x,int y)
{
    return sqrt(powf(x- a.x ,2) +powf(y- a.y ,2));
}

void graphic::clicked_menu()
{
    win_ptr=new menu_window(selected_land_pix,selected_land,&what_want_buld,player_->getIsTurn(),this);
    win_ptr->show();
}

void graphic::read()
{
    QString readMess=tcpSocket->readAll();
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(readMess.toUtf8());

    obj = doc.object();
    qDebug() << obj;
    if(obj["kind"].toString() == "invalid request"){
         // show obj["errorMessage"]
    }
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
    else if(obj["kindOfGame"].toString() == "responseToTransactionToPlayers")
    {
        if(obj["dealSuccess"].toBool())
        {
            //update the player and tell him who accepts the request

        }else{
            // tell the player that his request was not allowed
        }


    }
    else if(obj["kindOfGame"].toString() == "responseToTransactionToBank"){
        if(obj["dealSuccess"].toBool())
        {
            //update the player

        }else{
            // tell the player that his request was not allowed
        }



    }
    else if(obj["kindOfGame"].toString() == "responseToTransactionToPlayersAsk"){
       // show obj["deal"]
       // show obj["username"] (username of asker)
       // get player response and send it back to the server
        //  format of message you should send after recieving this
        /*"kindOfGame":"responseToTransactionToPlayers"
         * "answer":boolean(true/false)*/




}
    else if(obj["kindOfGame"].toString() == "endOfTurn"){
        //format of  message you get is like this
        /*obj["kindOfGame"] = "endOfTurn";

         * obj["whoseTurn"] = "red/blue/green/yellow
         * obj["dices"] = [int dice1,int dice2] jsonArray
         * obj["red"] :{"brick": int how much recived
         *              "tree" :int how much recived
         *              "sheep":int how much recived
         *              "wheat":int how much recived
         *              "rock":int how much recived}
         * obj["green"] :{"brick": int how much recived
         *              "tree" :int how much recived
         *              "sheep":int how much recived
         *              "wheat":int how much recived
         *              "rock":int how much recived}
         * obj["blue"] :{"brick": int how much recived   ->* if game was 3 players we also have red green blue *
         *              "tree" :int how much recived
         *              "sheep":int how much recived
         *              "wheat":int how much recived
         *              "rock":int how much recived}
         * obj["yellow"] :{"brick": int how much recived   ->* if game was 4 players we also have yellow *
         *              "tree" :int how much recived
         *              "sheep":int how much recived
         *              "wheat":int how much recived
         *              "rock":int how much recived}  */







    }


}

void graphic::arase_message()
{
    delete timer;
    timer=NULL;
    mess->setPlainText(" ");
}

void graphic::mousePressEvent(QMouseEvent *e)
{
    if(!player_->getIsTurn()||what_want_buld==0)
        return;
    int land= find_nearest_land(e->pos().x(),e->pos().y());
    create_selected_land(land);
    if(what_want_buld==1 && selected_land.size()==2)
    {
        //road
        //send some thing to server
        what_want_buld=0;
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
    }
    else if(what_want_buld==2 && selected_land.size()==3)
    {
        //home
        //send some thing to server
        what_want_buld=0;
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
    }
    else if(what_want_buld==3 && selected_land.size()==3)
    {
        //city
        //send some thing to server
        what_want_buld=0;
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
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
    tcpSocket->waitForBytesWritten(1000);

    this->setWindowTitle("catan");

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,720,512);
    setBackgroundBrush(QBrush(QImage(":/lands/Images/lands/back.png")));

    send_message(o);

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

    mess=new QGraphicsTextItem;
    mess->setPlainText(" ");
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    mess->setDefaultTextColor(QColor(0,0,0));
    mess->setPos(300,470);
    scene->addItem(mess);

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

void graphic::create_selected_land(int i)
{
    if(std::find(selected_land.begin(),selected_land.end(),i)!=selected_land.end())
    {
        selected_land.erase(std::find(selected_land.begin(),selected_land.end(),i));
        delete selected_land_pix[i];
        selected_land_pix.remove(i);
        return;
    }
    selected_land.push_back(i);
    QGraphicsPixmapItem*pix=new QGraphicsPixmapItem;
    pix->setPixmap(QPixmap(":/lands/Images/lands/selected.png"));
    pix->setPos(pos.map_l[QString::number(i)].x-28.5,pos.map_l[QString::number(i)].y-33);
    scene->addItem(pix);
    selected_land_pix.insert(i,pix);
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
