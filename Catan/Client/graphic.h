#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsView>
#include<QLabel>
#include"position_for_graohics.h"
#include<QPushButton>
#include"Player/player.h"
#include<QJsonObject>
class graphic : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsTextItem*me,*comp1,*comp2;
    QPushButton* menu;

    void set_lands();
    void set_score();
    positions pos;

    Player*player_;
    QTcpSocket*tcpSocket;
    QJsonObject obj;

public slots:
    void clicked_menu();
    void read();

public:
    graphic(Player*player_1,QTcpSocket*Socket1,QWidget *parent = nullptr);
};
#endif // GRAPHIC_H
