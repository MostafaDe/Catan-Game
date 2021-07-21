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
#include"transection_window.h"


QString convertColorToString(Color color)
{
    switch (color) {
    case Color::Blue:
        return "blue";
    case Color::Red:
        return "red";
    case Color::Green:
        return "green";
    case Color::Yellow:
        return "yellow";

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
    if(me_box)
        delete me_box;
    me_box=new QGraphicsRectItem(14,40,125,30);
    me_box->setBrush(set_color(convertColorToString(player_->getColor())));
    scene->addItem(me_box);
    if(me)
        delete me;
    me=new QGraphicsTextItem;
    me->setPlainText("my score: "+QString::number(player_->getScore()));
    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    me->setPos(16,41);
    scene->addItem(me);

    if(comp1_box)
        delete comp1_box;
    comp1_box=new QGraphicsRectItem(14,78,125,30);
    comp1_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[0].getColor())));
    scene->addItem(comp1_box);
    if(comp1)
        delete comp1;
    comp1=new QGraphicsTextItem;
    comp1->setPlainText(player_->getCompetitors()[0].getUsername()+": "+QString::number(player_->getCompetitors()[0].getScore()));
    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    comp1->setPos(16,79);
    scene->addItem(comp1);

    if(comp2_box)
        delete comp2_box;
    comp2_box=new QGraphicsRectItem(14,116,125,30);
    comp2_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[1].getColor())));
    scene->addItem(comp2_box);
    if(comp2)
        delete comp2;
    comp2=new QGraphicsTextItem;
    comp2->setPlainText(player_->getCompetitors()[1].getUsername()+": "+QString::number(player_->getCompetitors()[1].getScore()));
    setFont(QFont(":/fonts/Images/OCR A Std Regular.ttf",20));
    comp2->setPos(16,117);
    scene->addItem(comp2);


    if(player_->getCompetitors().size()>2)
    {
        if(comp3_box)
            delete comp3_box;
        comp3_box=new QGraphicsRectItem(14,154,125,30);
        comp3_box->setBrush(set_color(convertColorToString(player_->getCompetitors()[2].getColor())));
        scene->addItem(comp3_box);
        if(comp3)
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
    if(resource_box)
        delete resource_box;
    if(player_->getCompetitors().size()>2)
            resource_box=new QGraphicsRectItem(14,192,125,215);
    else
            resource_box=new QGraphicsRectItem(14,154,125,215);

    resource_box->setBrush(QColor(52,48,48));
    scene->addItem(resource_box);

    //tree
    if(tree)
        delete tree;
    tree=new QGraphicsPixmapItem;
    tree->setPixmap(QPixmap(":/cards/Images/cards/tree_card.png"));
    tree->setScale(0.5);
    tree->setPos(resource_box->sceneBoundingRect().x()+5,resource_box->sceneBoundingRect().y()+5);
    scene->addItem(tree);
    if(tree_)
        delete tree_;
    tree_=new QGraphicsTextItem;
    tree_->setPlainText(" : "+QString::number(player_->getCountOfWoodCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    tree_->setDefaultTextColor(QColor(225,225,225));
    tree_->setPos(tree->sceneBoundingRect().x()+tree->sceneBoundingRect().width()+5,tree->sceneBoundingRect().y()+tree->sceneBoundingRect().height()/2-5);
    scene->addItem(tree_);

    //sheep
    if(sheep)
        delete sheep;
    sheep=new QGraphicsPixmapItem;
    sheep->setPixmap(QPixmap(":/cards/Images/cards/sheep_card.png"));
    sheep->setScale(0.5);
    sheep->setPos(tree->sceneBoundingRect().x(),tree->sceneBoundingRect().y()+5+tree->sceneBoundingRect().height());
    scene->addItem(sheep);
    if(sheep_)
        delete sheep_;
    sheep_=new QGraphicsTextItem;
    sheep_->setPlainText(" : "+QString::number(player_->getCountOfSheepCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    sheep_->setDefaultTextColor(QColor(225,225,225));
    sheep_->setPos(sheep->sceneBoundingRect().x()+sheep->sceneBoundingRect().width()+5,sheep->sceneBoundingRect().y()+sheep->sceneBoundingRect().height()/2-5);
    scene->addItem(sheep_);

    //iron
    if(iron)
        delete iron;
    iron=new QGraphicsPixmapItem;
    iron->setPixmap(QPixmap(":/cards/Images/cards/iron_card.png"));
    iron->setScale(0.5);
    iron->setPos(sheep->sceneBoundingRect().x(),sheep->sceneBoundingRect().y()+5+sheep->sceneBoundingRect().height());
    scene->addItem(iron);
    if(iron_)
        delete iron_;
    iron_=new QGraphicsTextItem;
    iron_->setPlainText(" : "+QString::number(player_->getCountOfRockCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    iron_->setDefaultTextColor(QColor(225,225,225));
    iron_->setPos(iron->sceneBoundingRect().x()+iron->sceneBoundingRect().width()+5,iron->sceneBoundingRect().y()+iron->sceneBoundingRect().height()/2-5);
    scene->addItem(iron_);

    //rock
    if(rock)
        delete rock;
    rock=new QGraphicsPixmapItem;
    rock->setPixmap(QPixmap(":/cards/Images/cards/rock_card.png"));
    rock->setScale(0.5);
    rock->setPos(iron->sceneBoundingRect().x(),iron->sceneBoundingRect().y()+5+iron->sceneBoundingRect().height());
    scene->addItem(rock);
    if(rock_)
        delete rock_;
    rock_=new QGraphicsTextItem;
    rock_->setPlainText(" : "+QString::number(player_->getCountOfBrickCards()));
    setFont(QFont(":/fonts/OCR A Std Regular.ttf",20));
    rock_->setDefaultTextColor(QColor(225,225,225));
    rock_->setPos(rock->sceneBoundingRect().x()+rock->sceneBoundingRect().width()+5,rock->sceneBoundingRect().y()+rock->sceneBoundingRect().height()/2-5);
    scene->addItem(rock_);

    //wheat
    if(wheat)
        delete wheat;
    wheat=new QGraphicsPixmapItem;
    wheat->setPixmap(QPixmap(":/cards/Images/cards/wheat_card.png"));
    wheat->setScale(0.5);
    wheat->setPos(rock->sceneBoundingRect().x(),rock->sceneBoundingRect().y()+5+rock->sceneBoundingRect().height());
    scene->addItem(wheat);
    if(wheat_)
        delete wheat_;
    wheat_=new QGraphicsTextItem;
    wheat_->setPlainText(" : "+QString::number(player_->getCountOfWheatCards()));
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
    tcpSocket->waitForBytesWritten(1000);
}

void graphic::show_message(QString mess_)
{
    mess->setPlainText(mess_);

    if(timer!=NULL)
        delete timer;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(arase_message()));
    timer->start(10000);
}

int graphic::find_nearest_land(int x, int y)
{
    int land=-18;
    double l=distance_of_points(pos.map_l["-18"],x,y);
    for(int i=-36;i<29;i++)
    {
        if((i<-12 && i>-31)||i==0)
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
    win_ptr=new menu_window(selected_land_pix,selected_land,&what_want_buld,player_->getIsTurn(),tcpSocket,this);
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
        show_message( obj["errorMessage"].toString());
    }
    else if(obj["kindOfGame"].toString() == "getBoardInformation")
    {
        this->obj = obj;
        set_lands();
        set_score();
        set_resource();
        player_->setIsTurn(obj["myTurn"].toBool());
    }
    else if(obj["kindOfGame"] == "responseTobuildHouse")
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

            if(obj["color"]==convertColorToString(player_->getColor()))
                player_->setScore(player_->getScore()+1);
            else
            {
                QVector<Competitor>comps=player_->getCompetitors();
                for(int i=0;i<player_->getCompetitors().size();i++)
                {
                    if(convertColorToString(player_->getCompetitors()[i].getColor())==obj["color"].toString())
                    {
                        comps[i].setScore(comps[i].getScore()+1);
                        player_->setCompetitors(comps);
                        break;
                    }
                }
            }
            set_score();

        }
        else
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
        else
        {
            show_message(obj["errorMessage"].toString());
        }
    }
    else if(obj["kindOfGame"].toString() == "responseToTransactionToPlayers")
    {
        if(obj["dealSuccess"].toBool())
        {
            player_->setCountOfBrickCards(player_->getCountOfBrickCards()+obj["brikT"].toInt()-obj["brikG"].toInt());
            player_->setCountOfSheepCards(player_->getCountOfSheepCards()+obj["sheepT"].toInt()-obj["sheepG"].toInt());
            player_->setCountOfRockCards(player_->getCountOfRockCards()+obj["rockT"].toInt()-obj["rockG"].toInt());
            player_->setCountOfWheatCards(player_->getCountOfWheatCards()+obj["wheatT"].toInt()-obj["wheatG"].toInt());
            player_->setCountOfWoodCards(player_->getCountOfWoodCards()+obj["treeT"].toInt()-obj["treeG"].toInt());
            set_resource();
            show_message(obj["message"].toString());
        }
        else
        {
            show_message(obj["errorMessage"].toString());
        }
    }
    else if(obj["kindOfGame"].toString() == "responseToTransactionToBank")
    {
        if(obj["dealSuccess"].toBool())
        {
            player_->setCountOfBrickCards(player_->getCountOfBrickCards()+obj["brikT"].toInt()-obj["brikG"].toInt());
            player_->setCountOfSheepCards(player_->getCountOfSheepCards()+obj["sheepT"].toInt()-obj["sheepG"].toInt());
            player_->setCountOfRockCards(player_->getCountOfRockCards()+obj["rockT"].toInt()-obj["rockG"].toInt());
            player_->setCountOfWheatCards(player_->getCountOfWheatCards()+obj["wheatT"].toInt()-obj["wheatG"].toInt());
            player_->setCountOfWoodCards(player_->getCountOfWoodCards()+obj["treeT"].toInt()-obj["treeG"].toInt());
            set_resource();
            show_message(obj["message"].toString());
        }

        else
        {
            show_message(obj["errorMessage"].toString());
        }
    }
    else if(obj["kindOfGame"].toString() == "responseToTransactionToPlayersAsk")
    {
        QJsonObject deal=obj["deal"].toObject();
        transection_window* w=new transection_window(tcpSocket,obj["username"].toString(),obj["sheepG"].toInt(),obj["sheepT"].toInt(),obj["wheatT"].toInt(),obj["wheatG"].toInt(),obj["treeT"].toInt(),obj["treeG"].toInt(),obj["rockG"].toInt(),obj["rockT"].toInt(),obj["brickT"].toInt(),obj["brickG"].toInt(),this);
        w->show();
    }
    else if(obj["kindOfGame"].toString() == "endOfTurn")
    {
        if(obj["whoseTurn"]==convertColorToString(player_->getColor()))
            player_->setIsTurn(true);
        else
            player_->setIsTurn(false);

        show_message("it is "+obj["whoseTurn"].toString()+" turn");

        //set cards
        if(obj["dices"].toArray().size())
        {
            QJsonObject cards=obj[convertColorToString(player_->getColor())].toObject();
            player_->setCountOfSheepCards((player_->getCountOfSheepCards())+(cards["sheep"].toInt()));
            player_->setCountOfBrickCards((player_->getCountOfBrickCards())+(cards["brick"].toInt()));
            player_->setCountOfWheatCards((player_->getCountOfWheatCards())+(cards["wheat"].toInt()));
            player_->setCountOfWoodCards((player_->getCountOfWoodCards())+(cards["tree"].toInt()));
            player_->setCountOfRockCards((player_->getCountOfRockCards())+(cards["rock"].toInt()));

            qDebug()<<player_->getCountOfSheepCards();
            qDebug()<<player_->getCountOfBrickCards();
            qDebug()<<player_->getCountOfWheatCards();
            qDebug()<<player_->getCountOfWoodCards();
            qDebug()<<player_->getCountOfRockCards();

            set_resource();

            QJsonArray arr=obj["dices"].toArray();
            set_dices(arr[0].toInt(),arr[1].toInt());
        }
    }
    else if(obj["kindOfGame"].toString()=="winer")
    {
        show_message(obj["message"].toString());
    }
    if(!(player_->getIsTurn()))
    {
        tcpSocket->waitForBytesWritten(1000);
    }
}

void graphic::arase_message()
{
    if(timer)
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
        QJsonObject o;
        o["kind"] = "Game";
        o["kindOfGame"] = "buildRoad";
        QJsonArray arr={selected_land[0],selected_land[1]};
        o["position"] = arr;
        o["color"] = convertColorToString(player_->getColor());
        send_message(o);
        what_want_buld=0;
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
    }
    else if(what_want_buld==2 && selected_land.size()==3)
    {
        //home
        QJsonObject o;
        o["kind"] = "Game";
        o["kindOfGame"] = "buildHouse";
        QJsonArray arr={selected_land[0],selected_land[1],selected_land[2]};
        o["position"] = arr;
        o["color"] = convertColorToString(player_->getColor());
        send_message(o);
        what_want_buld=0;
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
        create_selected_land(selected_land[0]);
    }
    else if(what_want_buld==3 && selected_land.size()==3)
    {
        //city
        QJsonObject o;
        o["kind"] = "Game";
        o["kindOfGame"] = "buildBigCity";
        QJsonArray arr={selected_land[0],selected_land[1],selected_land[2]};
        o["position"] = arr;
        o["color"] = convertColorToString(player_->getColor());
        send_message(o);
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
    for(int r=0;r<selected_land.size();r++)
    {
        if(distance_of_points(pos.map_l[QString::number(selected_land[r])],pos.map_l[QString::number(i)].x,pos.map_l[QString::number(i)].y)>60)
        {
            show_message("you must choos the neigber lands!");
            return;
        }
    }
    selected_land.push_back(i);
    QGraphicsPixmapItem*pix=new QGraphicsPixmapItem;
    pix->setPixmap(QPixmap(":/lands/Images/lands/selected.png"));
    pix->setPos(pos.map_l[QString::number(i)].x-28.5,pos.map_l[QString::number(i)].y-33);
    scene->addItem(pix);
    selected_land_pix.insert(i,pix);
}

void graphic::set_dices(int d1, int d2)
{
    if(dice1)
        delete dice1;
    dice1=new QGraphicsPixmapItem;
    dice1->setPixmap(QPixmap(":/dice/Images/dice/"+QString::number(d1)+".png"));
    dice1->setPos(resource_box->sceneBoundingRect().x(),resource_box->sceneBoundingRect().y()+resource_box->sceneBoundingRect().height()+8);
    dice1->setScale(0.3);
    scene->addItem(dice1);

    if(dice2)
        delete dice2;
    dice2=new QGraphicsPixmapItem;
    dice2->setPixmap(QPixmap(":/dice/Images/dice/"+QString::number(d2)+".png"));
    dice2->setPos(dice1->sceneBoundingRect().x()+dice1->sceneBoundingRect().width()+8,dice1->sceneBoundingRect().y());
    dice2->setScale(0.3);
    scene->addItem(dice2);

    if(dice_timer)
        delete dice_timer;
    dice_timer = new QTimer();
    connect(dice_timer,SIGNAL(timeout()),this,SLOT(delete_dices()));
    dice_timer->start(10000);
}

void graphic::delete_dices()
{
    if(dice_timer)
        delete dice_timer;
    dice_timer=NULL;
    if(dice1)
        delete dice1;
    if(dice2)
        delete dice2;
    dice1=NULL;
    dice2=NULL;
}

QColor graphic::set_color(QString str)
{
    if(str=="blue")
        return QColor(51,77,210);
    else if(str=="red")
        return QColor(210,51,51);
    else if(str=="green")
        return QColor(103,210,51);
    else
        return QColor(210,186,51);
}
