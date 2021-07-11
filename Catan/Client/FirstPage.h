#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QDialog>
#include<Client/LogIn.h>
#include<Client/SignUp.h>

class FirstPage : public QDialog
{
    Q_OBJECT

public:
    FirstPage(QWidget *parent = nullptr);

private:
    QPushButton *SignUp_,*LogIn_;

private slots:
    void clicked_signUp();
    void clicked_logIn();
};
#endif // FIRSTPAGE_H
