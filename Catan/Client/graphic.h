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
    QGraphicsTextItem*me,*comp1,*comp2,*comp3,*mess;
    QGraphicsRectItem*me_box,*comp1_box,*comp2_box,*comp3_box;
    QGraphicsRectItem*resource_box;
    QPushButton* menu;


    void set_lands();
    void set_score();
    void set_resource();
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

public:
    graphic(Player*player_1,QTcpSocket*Socket1,QWidget *parent = nullptr);
};
#endif // GRAPHIC_H
