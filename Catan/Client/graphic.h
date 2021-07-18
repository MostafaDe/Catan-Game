#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsView>
#include<QLabel>
#include"position_for_graohics.h"
#include<QPushButton>
#include"Player/player.h"
#include<QJsonObject>
#include<QTimer>

class graphic : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsTextItem*me,*comp1,*comp2,*comp3,*mess;
    QGraphicsRectItem*me_box,*comp1_box,*comp2_box,*comp3_box;
    QGraphicsRectItem*resource_box;
    QPushButton* menu;
    QTimer*timer=NULL;

    QGraphicsPixmapItem*sheep,*iron,*tree,*rock,*wheat;
    QGraphicsTextItem*sheep_,*iron_,*tree_,*rock_,*wheat_;


    void set_lands();
    void set_score();
    void set_resource();
    void send_message(QJsonObject o);
    void show_message(QString mess);
    positions pos;

    Player*player_;
    QTcpSocket*tcpSocket;
    QJsonObject obj;

    QColor set_color (QString str);
    position_for_graphics set_center(int num,QJsonArray arr);

public slots:
    void clicked_menu();
    void read();
    void arase_message();

public:
    graphic(Player*player_1,QTcpSocket*Socket1,QWidget *parent = nullptr);
};
#endif // GRAPHIC_H
