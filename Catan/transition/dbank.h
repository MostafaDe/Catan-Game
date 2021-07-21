#ifndef DBANK_H
#define DBANK_H

#include <QMainWindow>


//#include <QObject>

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QHBoxLayout>
#include<QString>
#include<QComboBox>
#include<QJsonObject>
#include<QTcpSocket>


class DBank : public QMainWindow
{
    Q_OBJECT
    QWidget *c;
    QVBoxLayout *v1;
    QPushButton *bOk;
    QPushButton *bCansel;
    QHBoxLayout *h1;
    QHBoxLayout *h2;
    QHBoxLayout *h3;
    QComboBox *Cbg;
     QComboBox *Cbt;
   QLabel* l1;
   QLabel *l2;




public:



    explicit DBank(QTcpSocket*sock,QWidget *parent = nullptr);
public slots:
void SOk();


private:
    QTcpSocket*tcpSocket;
    void send_message(QJsonObject o);
};

#endif // DBANK_H
