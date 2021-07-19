#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<QJsonObject>
#include"Server/game.h"

using testing::Eq;

namespace  {
class ClassDec:public testing::Test {


public:
   Game game;

    ClassDec(){
        QMap<Color,Player> colorToPlayer;
        if(true){
        Competitor comp1;
        Competitor comp2;
        comp1.setColor(Color::Green);
        comp2.setColor(Color::Blue);
        Player player;
        player.setColor(Color::Red);
        player.setSocketDescriptor(1);
        player.setIsTurn(true);
        colorToPlayer[Color::Red] = player;

    }
        if(true){
            Competitor comp1;
            Competitor comp2;
            comp1.setColor(Color::Red);
            comp2.setColor(Color::Blue);
            Player player;
            player.setColor(Color::Green);
            player.setSocketDescriptor(2);
            colorToPlayer[Color::Green] = player;


    }
        if(true){
            Competitor comp1;
            Competitor comp2;
            comp1.setColor(Color::Red);
            comp2.setColor(Color::Green);
            Player player;
            player.setColor(Color::Blue);
            player.setSocketDescriptor(3);
            colorToPlayer[Color::Blue] = player;

    }
        GameData::colorToPlayer = colorToPlayer;
        Board* b= new Board1();
        GameData::setBoard(b);
        game = Game();

    }

};
void reset(){
    QMap<Color,Player> colorToPlayer;
    if(true){
    Competitor comp1;
    Competitor comp2;
    comp1.setColor(Color::Green);
    comp2.setColor(Color::Blue);
    Player player;
    player.setUsername("1");
    player.setColor(Color::Red);
    player.setSocketDescriptor(1);
    player.setIsTurn(true);
    colorToPlayer[Color::Red] = player;

}
    if(true){
        Competitor comp1;
        Competitor comp2;
        comp1.setColor(Color::Red);
        comp2.setColor(Color::Blue);
        Player player;
        player.setUsername("2");
        player.setColor(Color::Green);
        player.setSocketDescriptor(2);
        colorToPlayer[Color::Green] = player;


}
    if(true){
        Competitor comp1;
        Competitor comp2;
        comp1.setColor(Color::Red);
        comp2.setColor(Color::Green);
        Player player;
        player.setUsername("3");
        player.setColor(Color::Blue);
        player.setSocketDescriptor(3);
        colorToPlayer[Color::Blue] = player;

}
    GameData::colorToPlayer = colorToPlayer;
    Board* b= new Board1();
    GameData::setBoard(b);



}


QJsonObject getATransactionReq(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j)
{
    QJsonObject jsO;
    QJsonObject js;
    js["brickT"] = a;
    js["wheatT"] = b;
    js["rockT"] = c;
    js["treeT"] = d;
    js["sheepT"] = e;
    js["brickG"] = f;
    js["wheatG"] = g;
    js["rockG"] = h;
    js["treeG"] = i;
    js["sheepG"] = j;
    jsO["deal"] = js;
    return js;
}
}
TEST_F(ClassDec,getInformationMethod){


    for(int i = 1; i <= 3;i++){
    QJsonObject js;
    QVector<int> socks;
    socks.push_back(i);
    js = game.getBoardInformation(socks);
    if(i ==1)
       EXPECT_TRUE(js["myTurn"].toBool());
    else
       EXPECT_FALSE(js["myTurn"].toBool());
    }



}
TEST_F(ClassDec,transactionToBankMethod){

       reset();
       game.setGameFlow(12);
       GameData::colorToPlayer[Color::Red].setCountOfBrickCards(100);
       GameData::colorToPlayer[Color::Red].setCountOfWoodCards(100);
       GameData::colorToPlayer[Color::Red].setCountOfRockCards(100);
       GameData::colorToPlayer[Color::Red].setCountOfWheatCards(100);
       GameData::colorToPlayer[Color::Red].setCountOfSheepCards(100);

       // brick wheat rock tree sheep
       if(true){
       QJsonObject js = getATransactionReq(4,0,0,0,0 ,0,0,1,1,0);
       QJsonObject jsO2;
       jsO2["deal"] = js;
       QJsonObject jsO;
       QVector<int> v;
       v.push_back(1);
       jsO = game.transactionToBank(jsO2,v);
       EXPECT_FALSE(jsO["kind"].toString() == "Game");
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}// brick wheat rock tree sheep
       if(true){
       QJsonObject js = getATransactionReq(4,0,0,0,0,1,0,0,0,0);
       QJsonObject jsO2;
       jsO2["deal"] = js;
       QJsonObject jsO;
       QVector<int> v;
       v.push_back(1);
       jsO = game.transactionToBank(jsO2,v);
       EXPECT_FALSE(jsO["kind"].toString() == "Game");
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}// brick wheat rock tree sheep
       if(true){
       QJsonObject js = getATransactionReq(3,0,0,0,0,0,0,0,1,0);
       QJsonObject jsO2;
       jsO2["deal"] = js;
       QJsonObject jsO;
       QVector<int> v;
       v.push_back(1);
       jsO = game.transactionToBank(jsO2,v);
       EXPECT_FALSE(jsO["kind"].toString() == "Game");
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}// brick wheat rock tree sheep
       if(true){
       QJsonObject js = getATransactionReq(4,4,0,0,0,0,0,1,1,1);
       QJsonObject jsO2;
       jsO2["deal"] = js;
       QJsonObject jsO;
       QVector<int> v;
       v.push_back(1);
       jsO = game.transactionToBank(jsO2,v);
       EXPECT_FALSE(jsO["kind"].toString() == "Game");
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}// brick wheat rock tree sheep
       if(true){

       QJsonObject js = getATransactionReq(4,4,0,0,0,0,0,0,1,1);
       QJsonObject jsO2;
       jsO2["deal"] = js;
       QJsonObject jsO;
       QVector<int> v;
       v.push_back(1);
       jsO = game.transactionToBank(jsO2,v);
       bool a =jsO["kind"].toString() == "Game";
       EXPECT_TRUE(a);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),101);
       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),96);

}


}

TEST_F(ClassDec,transactionToPlayerMethod){


  reset();
  game.setGameFlow(12);

  GameData::colorToPlayer[Color::Red].setCountOfBrickCards(100);
  GameData::colorToPlayer[Color::Red].setCountOfWoodCards(100);
  GameData::colorToPlayer[Color::Red].setCountOfRockCards(100);
  GameData::colorToPlayer[Color::Red].setCountOfWheatCards(100);
  GameData::colorToPlayer[Color::Red].setCountOfSheepCards(100);
  // brick wheat rock tree sheep
  if(true){
  QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
  QJsonObject jsO2;
  jsO2["deal"] = js;
  QJsonObject jsO;
  QVector<int> v;
  v.push_back(1);
  jsO = game.transactionToPlayers(jsO2,v);
  EXPECT_TRUE(jsO["kind"].toString() == "Game");
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
  if(true){
  QJsonObject js = getATransactionReq(0,0,0,0,0,1,0,0,0,0);
  QJsonObject jsO2;
  jsO2["deal"] = js;
  QJsonObject jsO;
  QVector<int> v;
  v.push_back(1);
  jsO = game.transactionToPlayers(jsO2,v);
  EXPECT_FALSE(jsO["kind"].toString() == "Game");
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
  if(true){
  QJsonObject js = getATransactionReq(3,0,0,0,0,1,0,0,1,0);
  QJsonObject jsO2;
  jsO2["deal"] = js;
  QJsonObject jsO;
  QVector<int> v;
  v.push_back(1);
  jsO = game.transactionToPlayers(jsO2,v);
  EXPECT_FALSE(jsO["kind"].toString() == "Game");
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
  if(true){
  QJsonObject js = getATransactionReq(0,1,0,0,0,0,0,0,0,0);
  QJsonObject jsO2;
  jsO2["deal"] = js;
  QJsonObject jsO;
  QVector<int> v;
  v.push_back(1);
  jsO = game.transactionToPlayers(jsO2,v);
  EXPECT_FALSE(jsO["kind"].toString() == "Game");
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
  if(true){
  QJsonObject js = getATransactionReq(4,4,4,0,0,1,0,0,1,1);
  QJsonObject jsO2;
  jsO2["deal"] = js;
  QJsonObject jsO;
  QVector<int> v;
  v.push_back(1);
  jsO = game.transactionToPlayers(jsO2,v);
  EXPECT_FALSE(jsO["kind"].toString() == "Game");
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
  // brick wheat rock tree sheep
  if(true){
  QJsonObject js = getATransactionReq(4,4,0,0,0,0,0,0,2,2);
  QJsonObject jsO2;
  jsO2["deal"] = js;
  QJsonObject jsO;
  QVector<int> v;
  v.push_back(1);
  jsO = game.transactionToPlayers(jsO2,v);
  EXPECT_TRUE(jsO["kind"].toString() == "Game");
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),92);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),103);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),102);
  EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),96);

}



}
TEST_F(ClassDec,endOfTurn){
    reset();
    if(true)
    {
        game.setGameFlow(0);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);
    }
    if(true)
    {
        game.setGameFlow(1);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);
    }
    if(true)
    {
        game.setGameFlow(2);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"green");
        EXPECT_TRUE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);

    }
    if(true)
    {
        game.setGameFlow(3);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);
    }
    if(true)
    {
        game.setGameFlow(4);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"blue");
        EXPECT_TRUE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(5);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);

    }
    if(true)
    {
        game.setGameFlow(6);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"blue");
        EXPECT_TRUE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(7);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);
    }
    if(true)
    {
        game.setGameFlow(8);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"green");
        EXPECT_TRUE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(9);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);
    }
    if(true)
    {
        game.setGameFlow(10);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"red");
        EXPECT_TRUE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(11);
        QVector<int> sockets;
        sockets.push_back(1);

        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"invalid request");
        EXPECT_EQ(sockets.size(),1);
    }
    if(true)
    {
        game.setGameFlow(12);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"green");
        EXPECT_FALSE(jsO["dices"].isNull());

        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(13);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"blue");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(14);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"red");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);;
    }
    if(true)
    {
        game.setGameFlow(15);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"green");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(16);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"blue");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);
    }
    if(true)
    {
        game.setGameFlow(17);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"red");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);;
    }
    if(true)
    {
        game.setGameFlow(18);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"green");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);;
    }
    if(true)
    {
        game.setGameFlow(18);
        QVector<int> sockets;
        sockets.push_back(1);
        QJsonObject js;
        QJsonObject jsO = game.endOfTurn(sockets);
        EXPECT_EQ(jsO["kind"].toString(),"Game");
        EXPECT_EQ(jsO["kindOfGame"].toString(),"endOfTurn");
        EXPECT_EQ(jsO["whoseTurn"].toString(),"blue");
        EXPECT_FALSE(jsO["dices"].isNull());
        EXPECT_EQ(sockets.size(),3);;
    }


}
QJsonArray createPosForHouse(int x,int y ,int z){



    QJsonArray a;
    a.append(x);
    a.append(y);
    a.append(z);
    return a;

}
QJsonArray createPosForRoad(int x,int y ){



    QJsonArray a;
    a.append(x);
    a.append(y);

    return a;

}
TEST_F(ClassDec,buildHouseARoadABigCityMethod){

//       reset();

//       GameData::colorToPlayer[Color::Red].setCountOfBrickCards(100);
//       GameData::colorToPlayer[Color::Red].setCountOfWoodCards(100);
//       GameData::colorToPlayer[Color::Red].setCountOfRockCards(100);
//       GameData::colorToPlayer[Color::Red].setCountOfWheatCards(100);
//       GameData::colorToPlayer[Color::Red].setCountOfSheepCards(100);
//       GameData::colorToPlayer[Color::Green].setCountOfBrickCards(100);
//       GameData::colorToPlayer[Color::Green].setCountOfWoodCards(100);
//       GameData::colorToPlayer[Color::Green].setCountOfRockCards(100);
//       GameData::colorToPlayer[Color::Green].setCountOfWheatCards(100);
//       GameData::colorToPlayer[Color::Green].setCountOfSheepCards(100);
//       GameData::colorToPlayer[Color::Blue].setCountOfBrickCards(100);
//       GameData::colorToPlayer[Color::Blue].setCountOfWoodCards(100);
//       GameData::colorToPlayer[Color::Blue].setCountOfRockCards(100);
//       GameData::colorToPlayer[Color::Blue].setCountOfWheatCards(100);
//       GameData::colorToPlayer[Color::Blue].setCountOfSheepCards(100);

//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForHouse(11,12,16);
//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildHouse(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "house built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "house");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildHouse");

//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForHouse(11,12,16);
//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildHouse(js,v);

//       EXPECT_EQ(js1["kind"].toString(), "invalid request");


//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForRoad(11,12);
//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildRoad(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "road built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "road");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildRoad");

//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForRoad(11,12);

//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildRoad(js,v);

//       EXPECT_EQ(js1["kind"].toString(), "invalid request");


//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForHouse(7,12,8);
//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildHouse(js,v);

//       EXPECT_EQ(js1["kind"].toString(), "invalid request");


//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForRoad(11,12);

//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildRoad(js,v);

//       EXPECT_EQ(js1["kind"].toString(), "invalid request");


//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

//}
//       if(true){

//       QVector<int> v;
//       v.push_back(1);
//       QJsonObject js;
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"green");
//       EXPECT_EQ(v.size(),3);
//       v.clear();
//       v.append(2);
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       EXPECT_EQ(v.size(),1);
//}


//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(3);
//       QJsonArray a = createPosForHouse(7,4,8);
//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildHouse(js,v);

//       EXPECT_EQ(js1["kind"].toString(), "invalid request");


//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);

//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(2);
//       QJsonArray a = createPosForRoad(7,8);

//       js["position"] = a;
//       js["color"] = "green";
//       js1 = game.buildRoad(js,v);

//       EXPECT_EQ(js1["kind"].toString(), "invalid request");


//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);


//}

//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(2);
//       QJsonArray a = createPosForHouse(7,4,8);
//       js["position"] = a;
//       js["color"] = "green";
//       js1 = game.buildHouse(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "house built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "house");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildHouse");
//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(2);
//       QJsonArray a = createPosForRoad(7,8);

//       js["position"] = a;
//       js["color"] = "green";
//       js1 = game.buildRoad(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "road built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "road");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildRoad");



//}
//       if(true){

//       QVector<int> v;
//       v.push_back(2);
//       QJsonObject js;
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"blue");
//       EXPECT_EQ(v.size(),3);
//       v.clear();
//       v.append(3);
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       EXPECT_EQ(v.size(),1);
//}
//       if(true){
//           QJsonObject js;
//           QJsonObject js1;
//           QVector<int> v;
//           v.append(3);
//           QJsonArray a = createPosForHouse(16,19,20);
//           js["position"] = a;
//           js["color"] = "blue";
//           js1 = game.buildHouse(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "house built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "house");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildHouse");



//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(3);
//       QJsonArray a = createPosForRoad(16,20);

//       js["position"] = a;
//       js["color"] = "blue";
//       js1 = game.buildRoad(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "road built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "road");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildRoad");



//}

//       if(true){

//       QVector<int> v;
//       v.push_back(3);
//       QJsonObject js;
//       js = game.endOfTurn(v);

//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       EXPECT_EQ(v.size(),1);
//       v.clear();
//       v.append(3);
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       EXPECT_EQ(v.size(),1);
//}
//       if(true){
//           QJsonObject js;
//           QJsonObject js1;
//           QVector<int> v;
//           v.append(3);
//           QJsonArray a = createPosForHouse(25,26,27);
//        js["position"] = a;
//       js["color"] = "blue";
//       js1 = game.buildHouse(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "house built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "house");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildHouse");



//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(3);
//       QJsonArray a = createPosForRoad(25,26);

//       js["position"] = a;
//       js["color"] = "blue";
//       js1 = game.buildRoad(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "road built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "road");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildRoad");



//}
//       if(true){
//           QJsonObject js;
//           QJsonObject js1;
//           QVector<int> v;
//           v.append(3);
//           QJsonArray a = createPosForHouse(10,6,-1);
//        js["position"] = a;
//       js["color"] = "blue";

//       js1 = game.buildHouse(js,v);
//       EXPECT_EQ(js1["kind"].toString(), "invalid request");

//       EXPECT_EQ(v.size(),1);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);




//}
//       if(true){

//       QVector<int> v;
//       v.push_back(3);
//       QJsonObject js;
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"green");
//       EXPECT_EQ(v.size(),3);
//       v.clear();
//       v.append(2);
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       EXPECT_EQ(v.size(),1);
//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(2);
//       QJsonArray a = createPosForHouse(1,-28,2);
//       js["position"] = a;
//       js["color"] = "green";
//       js1 = game.buildHouse(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "house built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "house");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildHouse");



//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(2);
//       QJsonArray a = createPosForRoad(1,2);

//       js["position"] = a;
//       js["color"] = "green";
//       js1 = game.buildRoad(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "road built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "road");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildRoad");



//}
//       if(true){

//       QVector<int> v;
//       v.push_back(2);
//       QJsonObject js;
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"red");
//       EXPECT_EQ(v.size(),3);
//       v.clear();
//       v.append(1);
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       js = game.endOfTurn(v);
//       EXPECT_EQ(js["kind"].toString(),"invalid request");
//       EXPECT_EQ(v.size(),1);
//}

//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForHouse(10,11,6);
//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildHouse(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "house built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "house");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildHouse");



//}
//       if(true){
//       QJsonObject js;
//       QJsonObject js1;
//       QVector<int> v;
//       v.append(1);
//       QJsonArray a = createPosForRoad(10,11);

//       js["position"] = a;
//       js["color"] = "red";
//       js1 = game.buildRoad(js,v);
//       EXPECT_TRUE(js1["success"].toBool());
//       EXPECT_EQ(js1["message"].toString(), "road built successfuly :)");
//       EXPECT_EQ(js1["kindOfBuilding"].toString(), "road");
//       EXPECT_EQ(js1["position"].toArray(),a);
//       EXPECT_EQ(v.size(),3);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
//       EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);
//       EXPECT_EQ(js1["kindOfGame"].toString(),"responseTobuildRoad");



//}
//       if(true){

//       QVector<int> v;
//       v.push_back(1);
//       QJsonObject js;
//       qDebug() <<"size :" <<GameData::colorToPlayer.size();
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       qDebug() <<"size :" <<GameData::colorToPlayer.size();
//       EXPECT_EQ(js["whoseTurn"].toString(),"green");
//       EXPECT_EQ(v.size(),3);
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"blue");
//       EXPECT_EQ(v.size(),3);
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"red");
//       EXPECT_EQ(v.size(),3);

//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"green");
//       EXPECT_EQ(v.size(),3);

//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"blue");
//       EXPECT_EQ(v.size(),3);
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"red");
//       EXPECT_EQ(v.size(),3);
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"green");
//       EXPECT_EQ(v.size(),3);
//       js = game.endOfTurn(v);
//       qDebug() << js["whoseTurn"].toString();
//       EXPECT_EQ(js["whoseTurn"].toString(),"blue");
//       EXPECT_EQ(v.size(),3);

//}




}
TEST_F(ClassDec,ResponseToTransaction)
{
reset();
GameData::colorToPlayer[Color::Red].setCountOfBrickCards(100);
GameData::colorToPlayer[Color::Red].setCountOfWoodCards(100);
GameData::colorToPlayer[Color::Red].setCountOfRockCards(100);
GameData::colorToPlayer[Color::Red].setCountOfWheatCards(100);
GameData::colorToPlayer[Color::Red].setCountOfSheepCards(100);
GameData::colorToPlayer[Color::Green].setCountOfBrickCards(0);
GameData::colorToPlayer[Color::Green].setCountOfWoodCards(0);
GameData::colorToPlayer[Color::Green].setCountOfRockCards(0);
GameData::colorToPlayer[Color::Green].setCountOfWheatCards(0);
GameData::colorToPlayer[Color::Green].setCountOfSheepCards(0);
GameData::colorToPlayer[Color::Blue].setCountOfBrickCards(0);
GameData::colorToPlayer[Color::Blue].setCountOfWoodCards(0);
GameData::colorToPlayer[Color::Blue].setCountOfRockCards(0);
GameData::colorToPlayer[Color::Blue].setCountOfWheatCards(0);
GameData::colorToPlayer[Color::Blue].setCountOfSheepCards(0);
game.setGameFlow(13);
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsO;
QVector<int> v;
v.push_back(1);
jsO = game.transactionToPlayers(jsO2,v);
EXPECT_TRUE(jsO["kind"].toString() == "Game");
EXPECT_TRUE(jsO["kindOfGame"].toString() == "responseToTransaction");
EXPECT_FALSE(jsO["dealSuccess"].toBool());
EXPECT_EQ(jsO["username"].toString(),"All");
EXPECT_EQ(v.size(),1);
EXPECT_EQ(v.at(0),1);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
GameData::colorToPlayer[Color::Green].setCountOfBrickCards(100);
GameData::colorToPlayer[Color::Green].setCountOfWoodCards(100);
GameData::colorToPlayer[Color::Green].setCountOfRockCards(100);
GameData::colorToPlayer[Color::Green].setCountOfWheatCards(100);
GameData::colorToPlayer[Color::Green].setCountOfSheepCards(100);
GameData::colorToPlayer[Color::Blue].setCountOfBrickCards(100);
GameData::colorToPlayer[Color::Blue].setCountOfWoodCards(100);
GameData::colorToPlayer[Color::Blue].setCountOfRockCards(100);
GameData::colorToPlayer[Color::Blue].setCountOfWheatCards(100);
GameData::colorToPlayer[Color::Blue].setCountOfSheepCards(100);
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsO;
QVector<int> v;
v.push_back(1);
jsO = game.transactionToPlayers(jsO2,v);
EXPECT_EQ(v.size(),2);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsO;
QVector<int> v;
v.push_back(1);
jsO = game.transactionToPlayers(jsO2,v);
EXPECT_EQ(jsO["kind"],"invalid request");
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}

if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsObj;
jsObj["kind"] = "Game";
jsObj["kindOfGame"] = "responseToTransaction";
jsObj["dealSuccess"] = false;
QVector<int> v;
v.push_back(2);
jsObj = game.responseToTransactionToPlayers(jsO2,v);

EXPECT_EQ(jsObj["kind"].toString(),"Game");
EXPECT_EQ(jsObj["kindOfGame"].toString(),"responseToTransaction");
EXPECT_EQ(jsObj["dealSuccess"].toBool(),false);
EXPECT_EQ(jsObj["username"].toString() ,"2");

EXPECT_EQ(v.size(),1);

EXPECT_EQ(v.at(0),1);


EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);

}
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsObj;
jsObj["kind"] = "Game";
jsObj["kindOfGame"] = "responseToTransaction";
jsObj["dealSuccess"] = false;
QVector<int> v;
v.push_back(2);
jsObj = game.responseToTransactionToPlayers(jsO2,v);

EXPECT_EQ(jsObj["kind"].toString(),"invalid request");


EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);

}
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsObj;
jsObj["kind"] = "Game";
jsObj["kindOfGame"] = "responseToTransaction";
jsObj["dealSuccess"] = false;
QVector<int> v;
v.push_back(3);
jsObj = game.responseToTransactionToPlayers(jsO2,v);
EXPECT_EQ(jsObj["last"].toBool(),true);
EXPECT_EQ(jsObj["kind"].toString(),"Game");
EXPECT_EQ(jsObj["kindOfGame"].toString(),"responseToTransaction");
EXPECT_EQ(jsObj["dealSuccess"].toBool(),false);
EXPECT_EQ(jsObj["username"].toString() ,"3");
EXPECT_EQ(v.size(),1);

EXPECT_EQ(v.at(0),1);


EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);

}

if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsO;
QVector<int> v;
v.push_back(1);
jsO = game.transactionToPlayers(jsO2,v);
EXPECT_EQ(v.size(),2);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsObj;
jsObj["kind"] = "Game";
jsObj["kindOfGame"] = "responseToTransaction";
jsObj["answer"] = true;
QVector<int> v;
v.push_back(3);
jsObj = game.responseToTransactionToPlayers(jsObj,v);

EXPECT_EQ(jsObj["kind"].toString(),"Game");
EXPECT_EQ(jsObj["kindOfGame"].toString(),"responseToTransaction");
EXPECT_EQ(jsObj["dealSuccess"].toBool(),true);
EXPECT_EQ(jsObj["username"].toString() ,"3");
//EXPECT_EQ(v.size(),1);

//EXPECT_EQ(v.at(0),1);


EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfBrickCards(),104);

EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWoodCards(),99);
EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfWheatCards(),100);

EXPECT_EQ(GameData::colorToPlayer[Color::Blue].getCountOfRockCards(),99);


}
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsO;
QVector<int> v;
v.push_back(1);
jsO = game.transactionToPlayers(jsO2,v);
EXPECT_EQ(v.size(),2);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),96);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),101);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),101);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);

}
if(true){

QJsonObject js = getATransactionReq(4,0,0,0,0,0,0,1,1,0);
QJsonObject jsO2;
jsO2["deal"] = js;
QJsonObject jsObj;
jsObj["kind"] = "Game";
jsObj["kindOfGame"] = "responseToTransaction";
jsObj["answer"] = true;
QVector<int> v;
v.push_back(2);
jsObj = game.responseToTransactionToPlayers(jsObj,v);

EXPECT_EQ(jsObj["kind"].toString(),"Game");
EXPECT_EQ(jsObj["kindOfGame"].toString(),"responseToTransaction");
EXPECT_EQ(jsObj["dealSuccess"].toBool(),true);
EXPECT_EQ(jsObj["username"].toString() ,"2");
EXPECT_EQ(v.size(),1);
EXPECT_EQ(v.at(0),1);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfBrickCards(),104);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWoodCards(),99);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfWheatCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Green].getCountOfRockCards(),99);


EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfBrickCards(),92);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfRockCards(),102);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWoodCards(),102);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfSheepCards(),100);
EXPECT_EQ(GameData::colorToPlayer[Color::Red].getCountOfWheatCards(),100);



}









}


