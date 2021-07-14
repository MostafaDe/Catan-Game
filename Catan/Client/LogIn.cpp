#include "LogIn.h"

LogIn::LogIn(QWidget *parent)
    : QDialog(parent)
, tcpSocket(new QTcpSocket)
,password(new QLineEdit)
,userName(new QLineEdit)
,error_label(new QLabel(tr(" ")))

{
    tcpSocket->connectToHost(QHostAddress::LocalHost,8080);

    QLabel* username_label=new QLabel(tr("username :"));
    QLabel* password_label=new QLabel(tr("password :"));

    ok=new QPushButton(tr("Ok"));
    cancel=new QPushButton(tr("Cancel"));
    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(ok,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancel,QDialogButtonBox::RejectRole);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(username_label,0,0);
    mainLayout->addWidget(userName,0,1);
    mainLayout->addWidget(password_label,1,0);
    mainLayout->addWidget(password,1,1);
    mainLayout->addWidget(error_label,2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);

    setWindowTitle("log in");
    userName->setFocus();
    password->setEchoMode(QLineEdit::Password);
    ok->setDefault(true);
    ok->setEnabled(false);

    connect(userName, &QLineEdit::textChanged,
            this, &LogIn::enableOkButton);
    connect(password, &QLineEdit::textChanged,
            this, &LogIn::enableOkButton);
    connect(cancel, &QAbstractButton::clicked, this, &QWidget::close);
    connect(ok,SIGNAL(clicked()),this,SLOT(sendMessage()));
    connect(tcpSocket,&QTcpSocket::readyRead,this,&LogIn::read);
}



void LogIn::sendMessage()
{

    QJsonObject o;
    o["kind"] = "LogIn";
    o["username"]=userName->text();
    o["password"]=password->text();
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    this->tcpSocket->write(jsString.toLatin1());
    tcpSocket->waitForBytesWritten(1000);
    tcpSocket->waitForReadyRead(1000);
}

void LogIn::enableOkButton()
{
    ok->setEnabled(!userName->text().isEmpty()&& !password->text().isEmpty());
}

void LogIn::read()
{
    if(startGame)
        return;
    QString readMess=tcpSocket->readAll();

    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(readMess.toUtf8());

    obj = doc.object();

    if(obj["kind"] == "LogIn"){
        if(obj["success"].toBool())
        {
            readyToStart*r=new readyToStart(tcpSocket);
            r->show();
            startGame = true;
            this->close();
        }

        else{
            error_label->setText(obj["errorMessage"].toString());
        }
    }
}

