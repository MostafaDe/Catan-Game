#ifndef TPLAYER_H
#define TPLAYER_H

#include <QMainWindow>
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


class TPlayer : public QMainWindow
{
    Q_OBJECT

    QWidget *c;

    QHBoxLayout *h1;
    QHBoxLayout *h2;
    QHBoxLayout *h3;
    QHBoxLayout *h4;
    QHBoxLayout *h5;
    QHBoxLayout *h6;
    QHBoxLayout *h7;
    QHBoxLayout *h8;
    QHBoxLayout *h9;
    QHBoxLayout *h10;





    QVBoxLayout *v1;


    QLabel* l1;
    QLabel *l2;

    QLabel* l3;
    QLabel *l4;

    QLabel* l5;
    QLabel *l6;

    QLabel* l7;
    QLabel *l8;


    QLabel* l9;
    QLabel *l10;
    QLabel* l11;
    QLabel *l12;







    QComboBox *Cbgr;
    QComboBox *Cbgwh;
    QComboBox *Cbgwo;
    QComboBox *Cbgsh;
    QComboBox *Cbgb;

    QComboBox *Cbtb;
    QComboBox *Cbtwh;
    QComboBox *Cbtwo;
    QComboBox *Cbtsh;
    QComboBox *Cbtr;






    QPushButton *bOk;



public:

    explicit TPlayer(QTcpSocket*sock,QWidget *parent = nullptr);
public slots:
void SOk();
signals:
void send_jesonp(QJsonObject);
private:
    QTcpSocket*tcpSocket;
    void send_message(QJsonObject o);
};

#endif // TPLAYER_H
