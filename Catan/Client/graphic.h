#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsView>
#include<QLabel>
#include"position_for_graohics.h"
#include<QPushButton>
#include"Player/player.h"
#include<QJsonObject>
#include<QTimer>
#include"Client/menu_window.h"

class graphic : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsTextItem*me=NULL,*comp1=NULL,*comp2=NULL,*comp3=NULL,*mess=NULL;
    QGraphicsRectItem*me_box=NULL,*comp1_box=NULL,*comp2_box=NULL,*comp3_box=NULL;
    menu_window*win_ptr=NULL;
    QGraphicsPixmapItem*sheep=NULL,*iron=NULL,*tree=NULL,*rock=NULL,*wheat=NULL;
    QGraphicsTextItem*sheep_=NULL,*iron_=NULL,*tree_=NULL,*rock_=NULL,*wheat_=NULL;
    QGraphicsRectItem*resource_box=NULL;
    QPushButton* menu;
    QTimer*timer=NULL,*dice_timer=NULL;
    QGraphicsPixmapItem*dice1=NULL,*dice2=NULL;

    int what_want_buld=0;//0=nothing  1=road   2=house   3=city
    void set_lands();
    void set_score();
    void set_resource();
    void send_message(QJsonObject o);
    void show_message(QString mess);
    int find_nearest_land(int x,int y);
    double distance_of_points(position_for_graphics a, int x,int y);
    positions pos;
    Player*player_;
    QTcpSocket*tcpSocket;
    QJsonObject obj;
    QColor set_color (QString str);
    position_for_graphics set_center(int num,QJsonArray arr);
    QVector<int>selected_land;
    QMap<int,QGraphicsPixmapItem*>selected_land_pix;
    void create_selected_land(int i);
    void set_dices(int d1,int d2);

public slots:
    void clicked_menu();
    void read();
    void arase_message();
    void delete_dices();


public:
    graphic(Player*player_1,QTcpSocket*Socket1,QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent * e);

};
#endif // GRAPHIC_H
