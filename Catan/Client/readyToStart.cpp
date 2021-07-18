#include "readyToStart.h"
#include "Client/graphic.h"

readyToStart::readyToStart(QTcpSocket*sock,QWidget *parent)
    : QDialog(parent)
    ,tcpSocket(sock)
{
    QLabel *text_=new QLabel(tr("Are you ready to start a new game?"));

    ok=new QPushButton(tr("Ok"));
    cancel=new QPushButton(tr("Cancel"));
    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(ok,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancel,QDialogButtonBox::RejectRole);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(text_,0,0);
    mainLayout->addWidget(buttonBox, 1, 0, 1, 2);

    setWindowTitle("catan");
    ok->setFocus();

    connect(cancel, &QAbstractButton::clicked, this, &QWidget::close);
    connect(ok,SIGNAL(clicked()),this,SLOT(sendMessage()));
    connect(tcpSocket,&QTcpSocket::readyRead,this,&readyToStart::read);
}



Player *readyToStart::getPlayer() const
{
    return player;
}

void readyToStart::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void readyToStart::sendMessage()
{
    ok->setEnabled(false);
    cancel->setEnabled(false);
    QJsonObject o;
    o["kind"] = "ReadyToPlay";
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);
    tcpSocket->waitForReadyRead(1000);
}

void readyToStart::read()
{
    if(inGraphics)
        return;
    QString readMess=tcpSocket->readAll();
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(readMess.toUtf8());

    obj = doc.object();
    qDebug() << obj;
    if(obj["kind"] == "startGame")
    {
               player=new Player();

               if(obj["color"]=="red")
                   player->setColor(Color::Red);
               else if(obj["color"]=="yellow")
                   player->setColor(Color::Yellow);
               else if(obj["color"]=="blue")
                   player->setColor(Color::Blue);
               else
                   player->setColor(Color::Green);

               player->setUsername(obj["username"].toString());

               QJsonObject comp_obj=obj["comps"].toObject();
               QVector<Competitor>comp;
               for(int i=0;i<comp_obj["size"].toInt();i++)
               {
                   Competitor c;
                   QJsonArray arr = comp_obj["comp"+QString::number(i+1)].toArray();
                   if(arr[0].toString()=="red")
                       c.setColor(Color::Red);
                   else if(arr[0].toString()=="yellow")
                       c.setColor(Color::Yellow);
                   else if(arr[0].toString()=="blue")
                       c.setColor(Color::Blue);
                   else
                       c.setColor(Color::Green);
                   c.setUsername(arr[1].toString());
                   comp.push_back(c);
               }

               player->setCompetitors(comp);

    }

    graphic*gr=new graphic(player,tcpSocket);
    gr->show();
    inGraphics = true;
    this->close();
}
