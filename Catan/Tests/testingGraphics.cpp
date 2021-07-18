#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include"Client/graphic.h"
#include"Player/player.h"
#include<QJsonArray>
#include<QJsonObject>
using testing::Eq;

namespace  {
class ClassDec:public testing::Test {


public:
graphic* gra;

    ClassDec(){
        QTcpSocket* socket = new QTcpSocket;
        Player* player  = new Player;
        player->setUsername("mostafa");
        player->setColor(Color::Red);
        Competitor comp;
        QVector<Competitor> comps;

        comp.setColor(Color::Blue);
        Competitor comp1;
        comp1.setColor(Color::Green);
        comp.setUsername("ali");
        comp1.setUsername("jafar");
        comps.push_back(comp);
        comps.push_back(comp1);
        player->setCompetitors(comps);

        graphic*gr=new graphic(player,socket);
        gra = gr;
        gr->show();

    }

};
}
TEST_F(ClassDec,numOfTest1)
{
if(true){
        QJsonArray jsA;
        QJsonObject jsObj;
        jsA.append(11);
        jsA.append(12);
        jsA.append(16);
        jsObj["position"] = jsA;
        jsObj["kind"] = "Game";
        jsObj["kindOfGame"] = "responseTobuildHouse";

        jsObj["color"] = "blue";

        jsObj["kindOfBuilding"] = "house";
        jsObj["success"] = true;
        jsObj["message"] = "BigCity built successfuly :)";
        gra->message = jsObj;
        gra->read();
    }

if(true){
    QJsonArray jsA;
    QJsonObject jsObj;
    jsA.append(11);
    jsA.append(12);

    jsObj["position"] = jsA;
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildRoad";

    jsObj["color"] = "blue";

    jsObj["kindOfBuilding"] = "Road";
    jsObj["success"] = true;
    jsObj["message"] = "BigCity built successfuly :)";
    gra->message = jsObj;
    gra->read();
}
if(true){
        QJsonArray jsA;
        QJsonObject jsObj;
        jsA.append(13);
        jsA.append(12);
        jsA.append(17);
        jsObj["position"] = jsA;
        jsObj["kind"] = "Game";
        jsObj["kindOfGame"] = "responseTobuildHouse";

        jsObj["color"] = "green";

        jsObj["kindOfBuilding"] = "house";
        jsObj["success"] = true;
        jsObj["message"] = "BigCity built successfuly :)";
        gra->message = jsObj;
        gra->read();
    }

if(true){
    QJsonArray jsA;
    QJsonObject jsObj;
    jsA.append(17);
    jsA.append(12);

    jsObj["position"] = jsA;
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildRoad";

    jsObj["color"] = "green";

    jsObj["kindOfBuilding"] = "Road";
    jsObj["success"] = true;
    jsObj["message"] = "BigCity built successfuly :)";
    gra->message = jsObj;
    gra->read();
}
if(true){
        QJsonArray jsA;
        QJsonObject jsObj;
        jsA.append(-7);
        jsA.append(26);
        jsA.append(25);
        jsObj["position"] = jsA;
        jsObj["kind"] = "Game";
        jsObj["kindOfGame"] = "responseTobuildHouse";

        jsObj["color"] = "red";

        jsObj["kindOfBuilding"] = "house";
        jsObj["success"] = true;
        jsObj["message"] = "BigCity built successfuly :)";
        gra->message = jsObj;
        gra->read();
    }

if(true){
    QJsonArray jsA;
    QJsonObject jsObj;
    jsA.append(-7);
    jsA.append(26);

    jsObj["position"] = jsA;
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildRoad";

    jsObj["color"] = "red";

    jsObj["kindOfBuilding"] = "BigCity";
    jsObj["success"] = true;
    jsObj["message"] = "BigCity built successfuly :)";
    gra->message = jsObj;
    gra->read();
}
//if(true){
//        QJsonArray jsA;
//        QJsonObject jsObj;
//        jsA.append(11);
//        jsA.append(12);
//        jsA.append(16);
//        jsObj["position"] = jsA;
//        jsObj["kind"] = "Game";
//        jsObj["kindOfGame"] = "responseTobuildHouse";

//        jsObj["color"] = "blue";

//        jsObj["kindOfBuilding"] = "house";
//        jsObj["success"] = true;
//        jsObj["message"] = "BigCity built successfuly :)";
//        gra->message = jsObj;
//        gra->read();
//    }

//if(true){
//    QJsonArray jsA;
//    QJsonObject jsObj;
//    jsA.append(11);
//    jsA.append(12);

//    jsObj["position"] = jsA;
//    jsObj["kind"] = "Game";
//    jsObj["kindOfGame"] = "responseTobuildRoad";

//    jsObj["color"] = "blue";

//    jsObj["kindOfBuilding"] = "BigCity";
//    jsObj["success"] = true;
//    jsObj["message"] = "BigCity built successfuly :)";
//    gra->message = jsObj;
//    gra->read();
//}
//if(true){
//        QJsonArray jsA;
//        QJsonObject jsObj;
//        jsA.append(11);
//        jsA.append(12);
//        jsA.append(16);
//        jsObj["position"] = jsA;
//        jsObj["kind"] = "Game";
//        jsObj["kindOfGame"] = "responseTobuildHouse";

//        jsObj["color"] = "blue";

//        jsObj["kindOfBuilding"] = "house";
//        jsObj["success"] = true;
//        jsObj["message"] = "BigCity built successfuly :)";
//        gra->message = jsObj;
//        gra->read();
//    }

//if(true){
//    QJsonArray jsA;
//    QJsonObject jsObj;
//    jsA.append(11);
//    jsA.append(12);

//    jsObj["position"] = jsA;
//    jsObj["kind"] = "Game";
//    jsObj["kindOfGame"] = "responseTobuildRoad";

//    jsObj["color"] = "blue";

//    jsObj["kindOfBuilding"] = "BigCity";
//    jsObj["success"] = true;
//    jsObj["message"] = "BigCity built successfuly :)";
//    gra->message = jsObj;
//    gra->read();
//}

}
