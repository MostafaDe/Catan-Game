#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include<QDialog>
#include<QPushButton>
#include<QGraphicsPixmapItem>
#include<QJsonObject>
#include<QTcpSocket>

class menu_window:public QDialog
{
    Q_OBJECT
public:
    menu_window(QMap<int,QGraphicsPixmapItem*> &selected_land_pix,QVector<int>&selected_land,int *what,bool turn,QTcpSocket*socket,QWidget *parent = nullptr);

private:
    QPushButton*endOfTurn,*buildHous,*buildCity,*buildRoad,*transiton_;
    void set_inable(int* button,bool turn_);
    int *what_;
    bool turn_;
    QMap<int,QGraphicsPixmapItem*>*selected_land_pix_;
    QVector<int>*selected_land_;
    void delete_selected();
    void send_message(QJsonObject o);
    QTcpSocket*tcpSocket=NULL;

public slots:
    void clicked_endOfTurn();
    void clicked_buildHous();
    void clicked_buildCity();
    void clicked_buildRoad();
    void clicked_transiton_();

};

#endif // MENU_WINDOW_H
