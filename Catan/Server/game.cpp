#include "game.h"



Game::Game()
{
multiPlayerMode = GameData::colorToPlayer.size();
intToColor[0] = Color::Red;
intToColor[1] = Color::Green;
intToColor[2] = Color::Blue;
intToColor[3] = Color::Yellow;

}



QJsonObject Game::stopGame(QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}

QJsonObject Game::getBoardInformation(QVector<int> &socketDescriptors)
{



    QJsonObject jsObj = GameData::getBoard()->get_board_information();
    if(socketDescriptors.at(0) == getSocketOfPlayingPlayer())
        jsObj["myTurn"] = true;
    else
        jsObj["myTurn"] = false;

    return jsObj;


}

QJsonObject Game::buildHouse(QJsonObject message, QVector<int> &socketDescriptors)
{
    gameFlow++;
    QJsonObject jsObj;

    if(socketDescriptors.at(0) != getSocketOfPlayingPlayer() || (gameFlow < multiPlayerMode*4 && gameFlow%2 ==0 ) || checkSomeConditionForBuildingHouse(makeColorToPlayerToSocketToPlayer()[socketDescriptors.at(0)].getColor()))
    {

        jsObj["kind"] = "invalid request";
        gameFlow--;
        return jsObj;

    }

    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildHouse";
    QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();

    if(playerCanEfordIt("House",socketToPlayer[socketDescriptors.at(0)].getColor()))
    {

    Tranlate trans(GameData::getBoard()->mede_neiberhod_and_get());
    QJsonArray jsArray = message["position"].toArray();
    RoulsOfBuildHome rule(GameData::getBoard()->mede_neiberhod_and_get());
    int a[3];
    a[0] = jsArray.at(0).toInt();
    a[1] = jsArray.at(1).toInt();
    a[2] = jsArray.at(2).toInt();

    if(rule.check_make(trans.getPositionOfLand(a),message["color"].toString().toStdString()))
    {
        jsObj["color"] = convertColorToString( socketToPlayer[socketDescriptors.at(0)].getColor());
        jsObj["position"] = message["position"].toArray();
        jsObj["kindOfBuilding"] = "house";
        jsObj["success"] = true;
        jsObj["message"] = "house built successfuly :)";
        appendAllSocketsToVector(socketDescriptors);
        return jsObj;
        }
    jsObj["success"] = false;
    jsObj["errorMessage"] = "you can not build any house here :(";
    return jsObj;
    }
    jsObj["success"] = false;
    jsObj["errorMessage"] = "you can not eford building a house  :(";
    gameFlow--;
    return jsObj;




}

QJsonObject Game::buildRoad(QJsonObject message, QVector<int> &socketDescriptors)
{
     gameFlow++;
     QJsonObject jsObj;

    if(socketDescriptors.at(0) != getSocketOfPlayingPlayer() || (gameFlow < multiPlayerMode*4 && gameFlow%2 ==1 ))
    {

        jsObj["kind"] = "invalid request";
        gameFlow--;
        return jsObj;

    }
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildRoad";
    QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
    Tranlate trans(GameData::getBoard()->mede_neiberhod_and_get());
    if(playerCanEfordIt("Road",socketToPlayer[socketDescriptors.at(0)].getColor())){
    RoulsOfBiuldRoad rule(GameData::getBoard()->mede_neiberhod_and_get());
    QJsonArray jsArray = message["position"].toArray();

    int a[2];
    a[0] = jsArray.at(0).toInt();
    a[1] = jsArray.at(1).toInt();

    if(rule.check_make(trans.getPositionOfRoad(a),message["color"].toString().toStdString()))
    {
        jsObj["color"] = convertColorToString( socketToPlayer[socketDescriptors.at(0)].getColor());
        jsObj["position"] =jsArray;
        jsObj["kindOfBuilding"] = "road";
        jsObj["success"] = true;
        jsObj["message"] = "road built successfuly :)";


        appendAllSocketsToVector(socketDescriptors);
        return jsObj;


        }
    jsObj["success"] = false;
    jsObj["errorMessage"] = "you can not build any road here :(";
    gameFlow--;
    return jsObj;

    }
    jsObj["success"] = false;
    jsObj["errorMessage"] = "you can not eford building a road  :(";
    return jsObj;

}



QJsonObject Game::buildBigCity(QJsonObject message, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;

   if(socketDescriptors.at(0) != getSocketOfPlayingPlayer() || gameFlow < multiPlayerMode*4)
   {

       jsObj["kind"] = "invalid request";
       return jsObj;

   }
   jsObj["kind"] = "Game";
   jsObj["kindOfGame"] = "responseTobuildHouse";
   QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
   Tranlate trans(GameData::getBoard()->mede_neiberhod_and_get());
   if(playerCanEfordIt("BigCity",socketToPlayer[socketDescriptors.at(0)].getColor())){
   RoulsOfBiuldRoad rule(GameData::getBoard()->mede_neiberhod_and_get());
   QJsonArray jsArray = message["position"].toArray();

   int a[3];
   a[0] = jsArray.at(0).toInt();
   a[1] = jsArray.at(1).toInt();
   a[2] = jsArray.at(2).toInt();

   if(rule.check_make(trans.getPositionOfRoad(a),message["color"].toString().toStdString()))
   {
       jsObj["color"] = convertColorToString( socketToPlayer[socketDescriptors.at(0)].getColor());
       jsObj["position"] =jsArray;
       jsObj["kindOfBuilding"] = "bigCity";
       jsObj["success"] = true;
       jsObj["message"] = "BigCity built successfuly :)";
       appendAllSocketsToVector(socketDescriptors);
       return jsObj;
     }
   jsObj["success"] = false;
   jsObj["errorMessage"] = "you can not build any BigCity here :(";
   return jsObj;

   }
   jsObj["success"] = false;
   jsObj["errorMessage"] = "you can not eford building a road  :(";
   return jsObj;

}

QJsonObject Game::transactionToPlayers(QJsonObject message, QVector<int> &socketDescriptors)
{
    /*format of message input json
     * {"kind":"Game"
     *  "kindOfGame":"transactionToPlayers"
     *  "deal":{"brickT":some number
     *          "wheatT":some number
     *           ...
     *           "rockG":some number
     *           "treeG":some number}}*/

    //postfix "G" : what player wants to get.
    //postfix "T" : what player wants to take.

    QJsonObject jsObj;
    QJsonObject jsDeal(message["deal"].toObject());


        if(jsDeal["brickT"].toInt() < 0 || jsDeal["wheatT"].toInt() < 0 || jsDeal["rockT"].toInt() < 0 || jsDeal["treeT"].toInt() < 0 || jsDeal["sheepT"].toInt() < 0 ||
           jsDeal["brickG"].toInt() < 0 || jsDeal["wheatG"].toInt() < 0 || jsDeal["rockG"].toInt() < 0 || jsDeal["treeG"].toInt() < 0 || jsDeal["sheepG"].toInt() < 0 ||
            (jsDeal["brickT"].toInt() + jsDeal["wheatT"].toInt() + jsDeal["rockT"].toInt() + jsDeal["treeT"].toInt() + jsDeal["sheepT"].toInt() ) <= 0 ||
                (jsDeal["brickG"].toInt() + jsDeal["wheatG"].toInt() + jsDeal["rockG"].toInt() + jsDeal["treeG"].toInt() + jsDeal["sheepG"].toInt() ) <= 0
                  || socketDescriptors.at(0) != getSocketOfPlayingPlayer()
               || gameFlow < multiPlayerMode*4/*|| (gameFlow != multiPlayerMode*4 || makeColorToPlayerToSocketToPlayer()[socketDescriptors.at(0)].getColor() == Color::)*/ // there can be a bug here fix that latter
                || checkExtraConditionForTransaction(jsDeal)
                  ){

            jsObj["kind"] = "invalid request";
            return jsObj;


    }
        if( !playerCanEfordTransaction(jsDeal,socketDescriptors.at(0))){
                jsObj["kind"] = "invalid request";
                return jsObj;

    }
    QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "transactionToPlayers";

    jsObj["username"] = socketToPlayer[socketDescriptors.at(0)].getUsername();
    jsObj["deal"] = jsDeal;
    for(auto &it:socketToPlayer){
        if(it.getSocketDescriptor() != socketDescriptors.at(0) &&
           it.getCountOfBrickCards() >= jsDeal["brickT"].toInt() &&
              it.getCountOfBrickCards() >= jsDeal["wheatT"].toInt() &&
              it.getCountOfBrickCards() >= jsDeal["sheepT"].toInt() &&
              it.getCountOfBrickCards() >= jsDeal["treeT"].toInt() &&
              it.getCountOfBrickCards() >= jsDeal["rockT"].toInt() ){
            socketDescriptors.append(it.getSocketDescriptor());
            waitingForSocketsResponse.append(it.getSocketDescriptor());
        }
    }
    socketOfDealer = socketDescriptors.at(0);
    socketDescriptors.removeAt(0);
    transactionMessage = message;

    return jsObj;


















}

QJsonObject Game::responseToTransactionToPlayers(QJsonObject message, QVector<int> &socketDescriptors)
{
    /*message format
     *{"kind":"Game",
     *"kindOfGame":"responseToTransactionToPlayers",
     *"answer":Some boolean(true/fasle)
     *}*/

   if(socketOfDealer == -1 && !socketExistInListOfSockets(socketDescriptors.at(0),waitingForSocketsResponse)
       &&  waitingForSocketsResponse.size() == 0 && gameFlow < multiPlayerMode*4    )
   {
       QJsonObject jsObj;
       jsObj["kind"] = "invalid request";
       return jsObj;
   }
   if(message["answer"].isBool())
   {
       QJsonObject jsObj;
       jsObj["kind"] = "Game";
       jsObj["kindOfGame"] = "responseToTransaction";
       jsObj["dealSuccess"] = true;
       makeDealWithTwoSockets(transactionMessage,socketDescriptors.at(0),socketOfDealer);
       socketDescriptors = waitingForSocketsResponse;
       socketDescriptors.append(socketOfDealer);
       socketOfDealer = -1;
       waitingForSocketsResponse.clear();
       return jsObj;

   }else{

   QJsonObject jsObj;
   QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
   jsObj["kind"] = "Game";
   jsObj["kindOfGame"] = "responseToTransaction";
   jsObj["dealSuccess"] = false;
   jsObj["username"] = socketToPlayer[socketDescriptors.at(0)].getUsername();
   if(waitingForSocketsResponse.size() == 0){

       socketDescriptors.append(socketOfDealer);
       socketOfDealer = -1;
       return jsObj;
   }else{
       return jsObj;
   }
   }

}

QJsonObject Game::transactionToBank(QJsonObject message, QVector<int> &socketDescriptors)
{

    QJsonObject jsObj;
    QJsonObject jsDeal(message["deal"].toObject());

    if((jsDeal["brickT"].toInt()%4 != 0) || (jsDeal["wheatT"].toInt()%4 != 0 )
            || (jsDeal["rockT"].toInt()%4 != 0 ) || (jsDeal["treeT"].toInt()%4 != 0)
            || (jsDeal["sheepT"].toInt()%4 != 0) ||
       jsDeal["brickG"].toInt() < 0 || jsDeal["wheatG"].toInt() < 0 || jsDeal["rockG"].toInt() < 0 || jsDeal["treeG"].toInt() < 0 || jsDeal["sheepG"].toInt() < 0 ||
        (jsDeal["brickT"].toInt() + jsDeal["wheatT"].toInt() + jsDeal["rockT"].toInt() + jsDeal["treeT"].toInt() + jsDeal["sheepT"].toInt() ) <= 0 ||
            (jsDeal["brickG"].toInt() + jsDeal["wheatG"].toInt() + jsDeal["rockG"].toInt() + jsDeal["treeG"].toInt() + jsDeal["sheepG"].toInt() ) <= 0
              || socketDescriptors.at(0) != getSocketOfPlayingPlayer()
            || gameFlow < multiPlayerMode*4 /*|| (gameFlow != multiPlayerMode*4 || makeColorToPlayerToSocketToPlayer()[socketDescriptors.at(0)].getColor() == Color::)*/ // there can be a bug here fix that latter
            ||(jsDeal["brickT"].toInt() + jsDeal["wheatT"].toInt() + jsDeal["rockT"].toInt() + jsDeal["treeT"].toInt() + jsDeal["sheepT"].toInt() ) /(jsDeal["brickG"].toInt() + jsDeal["wheatG"].toInt() + jsDeal["rockG"].toInt() + jsDeal["treeG"].toInt() + jsDeal["sheepG"].toInt() ) != 4
            || checkExtraConditionForTransaction(jsDeal)
            ){
        jsObj["kind"] = "invalid request";
        return jsObj;


    }
    if( !playerCanEfordTransaction(jsDeal,socketDescriptors.at(0))){
            jsObj["kind"] = "invalid request";
            return jsObj;

}
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseToTransaction";
    jsObj["dealSuccess"] = true;
    return jsObj;


}




QJsonObject Game::endOfTurn(QVector<int> &sockets)
{

    QJsonObject jsObj;
    static int counter = 0;
    if(gameFlow == 0 || (gameFlow%2 == 1 && gameFlow < 12  ) || checkExtraConditionForEndOfTurn(makeColorToPlayerToSocketToPlayer()[sockets.at(0)].getColor()) )
    {
        QJsonObject jsObj;
        jsObj["kind"] = "invalid request";
        return jsObj;
    }



    if(gameFlow < multiPlayerMode*4 && gameFlow >= multiPlayerMode*2){
       GameData::colorToPlayer[ intToColor[(counter)%multiPlayerMode]].setIsTurn(false);
       GameData::colorToPlayer[ intToColor[(counter - 1)%multiPlayerMode]].setIsTurn(true);

       jsObj["kind"] = "Game";
       jsObj["kindOfGame"] = "endOfTurn";
       jsObj["whoseTurn"] =convertColorToString(GameData::colorToPlayer[ intToColor[(counter - 1) %multiPlayerMode]].getColor());
       counter--;

    }
    else{


        GameData::colorToPlayer[ intToColor[counter%multiPlayerMode]].setIsTurn(false);
        counter++;
        GameData::colorToPlayer[ intToColor[counter%multiPlayerMode]].setIsTurn(true);
        QJsonArray jsArry;

        // Allocate resources
        jsObj["kind"] = "Game";
        jsObj["kindOfGame"] = "endOfTurn";
        jsObj["whoseTurn"] =convertColorToString(GameData::colorToPlayer[ intToColor[counter%multiPlayerMode]].getColor());
        if(gameFlow >= 12){
            dice.generateRandomDices();
            jsArry.append(dice.getDice1());
            jsArry.append(dice.getDice2());
            jsObj["dices"] = jsArry;
        }
    }


    appendAllSocketsToVector(sockets);
    return jsObj;
}

bool Game::socketExistInListOfSockets(int socket,const QVector<int>& waitingForSocketsResponse)
{
    for(auto& it:waitingForSocketsResponse){
        if(it == socket)
        return true;
    }
    return false;
}

void Game::removeThisSocketFromSocketList(int socket, QVector<int> &waitingForSocketsResponse)
{

}

void Game::makeDealWithTwoSockets(QJsonObject transactionMessage, int socketDealer, int socketBuyer)
{
}

QMap<int, Player> Game::makeColorToPlayerToSocketToPlayer()
{
    QMap<int,Player> socketToPlayer;
    for(auto &it :GameData::colorToPlayer){
        socketToPlayer [it.getSocketDescriptor()] = it;
    }

    return socketToPlayer;
}

int Game::getSocketOfPlayingPlayer()
{
    for(auto & it : GameData::colorToPlayer){
        if(it.getIsTurn())
            return it.getSocketDescriptor();
    }
}

QString Game::convertColorToString(Color color)
{
    switch (color) {
    case Color::Blue:
        return "blue";
    case Color::Red:
        return "red";
    case Color::Green:
        return "green";
    case Color::Yellow:
        return "yellow";

    }
}

bool Game::playerCanEfordIt(QString building, Color colorOfPlayer)
{

    if(building == "House"){

        if(gameFlow < 12 && gameFlow%2 == 1)
            return true;
        if(GameData::colorToPlayer[colorOfPlayer].getCountOfBrickCards() >= 1 &&
           GameData::colorToPlayer[colorOfPlayer].getCountOfWoodCards() >= 1 &&
           GameData::colorToPlayer[colorOfPlayer].getCountOfSheepCards() >= 1 &&
           GameData::colorToPlayer[colorOfPlayer].getCountOfWheatCards() >= 1
  )
        {
            GameData::colorToPlayer[colorOfPlayer].setCountOfBrickCards(GameData::colorToPlayer[colorOfPlayer].getCountOfBrickCards() - 1);

            GameData::colorToPlayer[colorOfPlayer].setCountOfWheatCards(GameData::colorToPlayer[colorOfPlayer].getCountOfWheatCards() - 1);
            GameData::colorToPlayer[colorOfPlayer].setCountOfSheepCards(GameData::colorToPlayer[colorOfPlayer].getCountOfSheepCards() - 1);
            GameData::colorToPlayer[colorOfPlayer].setCountOfWoodCards(GameData::colorToPlayer[colorOfPlayer].getCountOfWoodCards() - 1);


            return true;
        }
        else
            return false;

    }
    if(building == "Road"){
        if(colorOfPlayer == Color::Red && gameFlow == 12)
            return true;
        if(gameFlow < 12 && gameFlow%2 == 0)
            return true;
        if(GameData::colorToPlayer[colorOfPlayer].getCountOfBrickCards() >= 1 &&
           GameData::colorToPlayer[colorOfPlayer].getCountOfWoodCards() >= 1


               )
        {
            GameData::colorToPlayer[colorOfPlayer].setCountOfBrickCards(GameData::colorToPlayer[colorOfPlayer].getCountOfBrickCards() - 1);
            GameData::colorToPlayer[colorOfPlayer].setCountOfWoodCards(GameData::colorToPlayer[colorOfPlayer].getCountOfWoodCards() - 1);


            return true;
        }
        else
            return false;

    }
    if(building == "BigCity"){
        if(
           GameData::colorToPlayer[colorOfPlayer].getCountOfWheatCards() >= 2 &&
           GameData::colorToPlayer[colorOfPlayer].getCountOfRockCards() >= 3     )
        {

            GameData::colorToPlayer[colorOfPlayer].setCountOfRockCards(GameData::colorToPlayer[colorOfPlayer].getCountOfRockCards() - 3);
            GameData::colorToPlayer[colorOfPlayer].setCountOfWheatCards(GameData::colorToPlayer[colorOfPlayer].getCountOfWheatCards() - 2);



            return true;
        }
        else
            return false;
    }

    return true;
}

bool Game::playerCanEfordTransaction(QJsonObject jsDeal,int socket)
{

    Color color = makeColorToPlayerToSocketToPlayer()[socket].getColor();
    if(GameData::colorToPlayer[color].getCountOfBrickCards() < jsDeal["brickT"].toInt()
       ||GameData::colorToPlayer[color].getCountOfWheatCards() < jsDeal["wheatT"].toInt()
       ||GameData::colorToPlayer[color].getCountOfRockCards() < jsDeal["rockT"].toInt()
       ||GameData::colorToPlayer[color].getCountOfWoodCards() < jsDeal["treeT"].toInt()
       ||GameData::colorToPlayer[color].getCountOfSheepCards() < jsDeal["sheepT"].toInt()     )
       return false;
    else{

           GameData::colorToPlayer[color].setCountOfBrickCards((GameData::colorToPlayer[color].getCountOfBrickCards()  - jsDeal["brickT"].toInt()) + jsDeal["brickG"].toInt() );
           GameData::colorToPlayer[color].setCountOfWheatCards((GameData::colorToPlayer[color].getCountOfWheatCards()  - jsDeal["wheatT"].toInt()) + jsDeal["wheatG"].toInt() );
           GameData::colorToPlayer[color].setCountOfWoodCards((GameData::colorToPlayer[color].getCountOfWoodCards()  - jsDeal["treeT"].toInt()) +  jsDeal["treeG"].toInt());
           GameData::colorToPlayer[color].setCountOfSheepCards((GameData::colorToPlayer[color].getCountOfSheepCards()  - jsDeal["sheepT"].toInt()) + jsDeal["sheepG"].toInt());
           GameData::colorToPlayer[color].setCountOfRockCards((GameData::colorToPlayer[color].getCountOfRockCards()  - jsDeal["rockT"].toInt()) + jsDeal["rockG"].toInt());
           return true;
       }
}



void Game::appendAllSocketsToVector(QVector<int>& sockets)
{
     sockets.clear();
     QMap<Color,Player> colorToPlayer = GameData::colorToPlayer;
     for(auto &it:colorToPlayer)
     {
         sockets.append(it.getSocketDescriptor());
     }
}

void Game::setGameFlow(int newGameFlow)
{
    gameFlow = newGameFlow;
}

bool Game::checkExtraConditionForTransaction(QJsonObject jsDeal)
{
    if((jsDeal["brickT"].toInt() != 0 && jsDeal["brickG"].toInt() != 0 ) ||
        (jsDeal["wheatT"].toInt() != 0 && jsDeal["wheatG"].toInt() != 0 )||
         (jsDeal["rockT"].toInt() != 0 && jsDeal["rockG"].toInt() != 0 )||
            (jsDeal["treeT"].toInt() != 0 && jsDeal["treeG"].toInt() != 0 )||
            (jsDeal["sheepT"].toInt() != 0 && jsDeal["sheepG"].toInt() != 0 ))
        return true;
    else
        return false;
}

bool Game::checkSomeConditionForBuildingHouse(Color color)
{
    if(color == Color::Red){
     if((gameFlow == 3 || gameFlow == 3 + multiPlayerMode*2) && gameFlow <= multiPlayerMode*4){

         return true;
     }else{
         return false;
     }
}
    if(color == Color::Green){
     if((gameFlow == 5 || gameFlow == 5+ multiPlayerMode*2) && gameFlow <= multiPlayerMode*4){

         return true;
     }else{
         return false;
     }
    }
     if(color == Color::Blue){
         if(multiPlayerMode == 3 && gameFlow == 7)
             return false;
      if( (gameFlow == 9 || gameFlow ==9 +   multiPlayerMode*2) && gameFlow <= multiPlayerMode*4){

          return true;
      }else{
          return false;
      }
     }
      if(color == Color::Yellow){
          if(multiPlayerMode == 3 && gameFlow == 9)
              return false;
       if((gameFlow == 9 || gameFlow == 9 + multiPlayerMode*2 )&& gameFlow <= multiPlayerMode*4){

           return true;
       }else{
           return false;
       }
}


}

bool Game::checkExtraConditionForEndOfTurn(Color color)
{
    if(color == Color::Red){
     if((gameFlow == 0 || gameFlow == (multiPlayerMode*4) - 2) && gameFlow <= multiPlayerMode*4){

         return true;
     }else{
         return false;
     }
}
    if(color == Color::Green){
     if((gameFlow == 2 || gameFlow ==  (multiPlayerMode*4) - 4) && gameFlow <= multiPlayerMode*4){

         return true;
     }else{
         return false;
     }
    }
     if(color == Color::Blue){
         if(multiPlayerMode == 3 && gameFlow == 6 )
             return true;
      if((gameFlow == 4 || gameFlow ==  (multiPlayerMode*4) - 6) && gameFlow <= multiPlayerMode*4){

          return true;
      }else{
          return false;
      }
     }
      if(color == Color::Yellow){
       if(multiPlayerMode == 4 && gameFlow == 8 )
              return true;
       if((gameFlow == 6 || gameFlow == 6 + (multiPlayerMode*4 )- 8 )&& gameFlow <= multiPlayerMode*4){

           return true;
       }else{
           return false;
       }
}

}





QJsonObject Game::winner(bool &iswinner, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}




