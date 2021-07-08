#include "SignUp.h"


signUp::signUp(QWidget *parent)
: QDialog(parent)
, tcpSocket(new QTcpSocket(this))
,name(new QLineEdit)
,lastName(new QLineEdit)
,password(new QLineEdit)
,userName(new QLineEdit)

{

    QLabel* name_label=new QLabel(tr("name :"));
    QLabel* lastName_label=new QLabel(tr("lastname :"));
    QLabel* username_label=new QLabel(tr("username :"));
    QLabel* password_label=new QLabel(tr("password :"));

    ok=new QPushButton(tr("Ok"));
    cancel=new QPushButton(tr("Cancel"));
    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(ok,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancel,QDialogButtonBox::RejectRole);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(name_label,0,0);
    mainLayout->addWidget(name,0,1);
    mainLayout->addWidget(lastName_label,1,0);
    mainLayout->addWidget(lastName,1,1);
    mainLayout->addWidget(username_label,2,0);
    mainLayout->addWidget(userName,2,1);
    mainLayout->addWidget(password_label,3,0);
    mainLayout->addWidget(password,3,1);
    mainLayout->addWidget(buttonBox, 4, 0, 1, 2);

    setWindowTitle(QGuiApplication::applicationDisplayName());
    name->setFocus();
    password->setEchoMode(QLineEdit::Password);
    ok->setDefault(true);
    ok->setEnabled(false);

    connect(name, &QLineEdit::textChanged,
            this, &signUp::enableOkButton);
    connect(lastName, &QLineEdit::textChanged,
            this, &signUp::enableOkButton);
    connect(userName, &QLineEdit::textChanged,
            this, &signUp::enableOkButton);
    connect(password, &QLineEdit::textChanged,
            this, &signUp::enableOkButton);
    connect(cancel, &QAbstractButton::clicked, this, &QWidget::close);
    connect(ok,SIGNAL(clicked()),this,SLOT(connectToServer()));

}

void signUp::connectToServer()
{
    tcpSocket->connectToHost(QHostAddress::LocalHost,8080);
    QJsonObject o;
    o["name"]=name->text();
    o["lastname"]=lastName->text();
    o["username"]=userName->text();
    o["password"]=password->text();
    QJsonDocument d(o);
    QString jsString = QString::fromLatin1(d.toJson());
    if(tcpSocket->waitForConnected(3000))
    {
        this->tcpSocket->write(jsString.toLatin1());
        tcpSocket->waitForBytesWritten(3000);
        read();
    }
    else
    {
         QMessageBox::information(this,tr("connecting error"),tr("I can not find the server!\nPlease try again."));
    }

}

void signUp::enableOkButton()
{
    ok->setEnabled(!name->text().isEmpty()&& !lastName->text().isEmpty()&&
                   !userName->text().isEmpty()&& !password->text().isEmpty());
}

void signUp::read()
{
    tcpSocket->waitForReadyRead(3000);
    QString readMess=tcpSocket->readAll();

    ////////
}

