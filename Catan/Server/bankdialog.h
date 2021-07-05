#ifndef BANKDIALOG_H
#define BANKDIALOG_H
#include <QWidget>
#include "Bank.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class BankDialog
         :public  QWidget
{
    Q_OBJECT

public:
   BankDialog(QWidget *parent = nullptr);

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    Bank server;
};

#endif // BANKDIALOG_H
