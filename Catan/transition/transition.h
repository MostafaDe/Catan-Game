#ifndef TRANSITION_H
#define TRANSITION_H

#include <QMainWindow>
#include <QObject>

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QHBoxLayout>
#include<QString>
#include<QComboBox>
#include<QTcpSocket>

class Transition : public QMainWindow
{
    Q_OBJECT
QWidget *c;
QVBoxLayout *v1;
QPushButton *bbank;
QPushButton *bplayer;
QComboBox *Cb;



public:
    explicit Transition(QTcpSocket*sock,QWidget *parent = nullptr);
public slots:
void SBank();
void Splayer();

private:
QTcpSocket*tcpSocket;


};

#endif // TRANSITION_H
