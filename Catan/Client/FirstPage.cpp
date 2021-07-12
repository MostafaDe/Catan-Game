#include "FirstPage.h"

FirstPage::FirstPage(QWidget *parent)
    : QDialog(parent)
    ,SignUp_(new QPushButton(tr("sign up")))
    ,LogIn_(new QPushButton(tr("log in")))
{
    QLabel* w=new QLabel(tr("If you have an accont click on log in button.\nelse click on sign up."));
    setWindowTitle("catan");

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(w,0,0);
    mainLayout->addWidget(LogIn_,1,0);
    mainLayout->addWidget(SignUp_,2,0);

    connect(SignUp_,SIGNAL(clicked()),this,SLOT(clicked_signUp()));
    connect(LogIn_,SIGNAL(clicked()),this,SLOT(clicked_logIn()));
}

void FirstPage::clicked_signUp()
{
    signUp* page1=new signUp();
    page1->show();
    this->close();

}

void FirstPage::clicked_logIn()
{
    LogIn* page2=new LogIn();
    page2->show();
    this->close();
}


