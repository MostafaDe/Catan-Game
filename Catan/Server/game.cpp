#include "game.h"



Game::Game()
{
multiPlayerMode = GameData::getColorToPlayer().size();
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

    if(socketDescriptors.at(0) != getSocketOfPlayingPlayer())
    {

        jsObj["kind"] = "invalid request";
        return jsObj;

    }

    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildHouse";
    QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();

    if(playerCanEfordIt("House",socketToPlayer[socketDescriptors.at(0)].getColor(),message["fromCards"].toBool()))
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
    return jsObj;




}

QJsonObject Game::buildRoad(QJsonObject message, QVector<int> &socketDescriptors)
{
     gameFlow++;
     QJsonObject jsObj;

    if(socketDescriptors.at(0) != getSocketOfPlayingPlayer() )
    {

        jsObj["kind"] = "invalid request";
        return jsObj;

    }
    jsObj["kind"] = "Game";
    jsObj["kindOfGame"] = "responseTobuildRoad";
    QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
    Tranlate trans(GameData::getBoard()->mede_neiberhod_and_get());
    if(playerCanEfordIt("Road",socketToPlayer[socketDescriptors.at(0)].getColor(),message["fromCards"].toBool())){
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
    return jsObj;

    }
    jsObj["success"] = false;
    jsObj["errorMessage"] = "you can not eford building a road  :(";
    return jsObj;

}



QJsonObject Game::buildBigCity(QJsonObject message, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;

   if(socketDescriptors.at(0) != getSocketOfPlayingPlayer() && gameFlow < multiPlayerMode*4)
   {

       jsObj["kind"] = "invalid request";
       return jsObj;

   }
   jsObj["kind"] = "Game";
   jsObj["kindOfGame"] = "responseTobuildBigCity";
   QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
   Tranlate trans(GameData::getBoard()->mede_neiberhod_and_get());
   if(playerCanEfordIt("BigCity",socketToPlayer[socketDescriptors.at(0)].getColor(),message["fromCards"].toBool())){
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
    try{
        if(jsDeal["brickT"].toInt() <= 0 && jsDeal["wheatT"].toInt() <= 0 && jsDeal["rockT"].toInt() <= 0 && jsDeal["treeT"].toInt() <= 0 && jsDeal["sheepT"].toInt() <= 0 &&
           jsDeal["brickG"].toInt() <= 0 && jsDeal["wheatG"].toInt() <= 0 && jsDeal["rockG"].toInt() <= 0 && jsDeal["treeG"].toInt() <= 0 && jsDeal["sheepG"].toInt() <= 0 &&
            (jsDeal["brickT"].toInt() + jsDeal["wheatT"].toInt() + jsDeal["rockT"].toInt() + jsDeal["treeT"].toInt() + jsDeal["sheepT"].toInt() ) < 0 &&
                (jsDeal["brickG"].toInt() + jsDeal["wheatG"].toInt() + jsDeal["rockG"].toInt() + jsDeal["treeG"].toInt() + jsDeal["sheepG"].toInt() ) < 0
                  && socketDescriptors.at(0) != getSocketOfPlayingPlayer()
                && gameFlow < multiPlayerMode*4){
            // there can be a bug when wheatG = 2 and wheatT = 3 support that latter
            jsObj["kind"] = "invalid request";
            return jsObj;


    }
    QMap<int,Player> socketToPlayer = makeColorToPlayerToSocketToPlayer();
    jsObj["kind"] = "game";
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



 // if any error acured send an invalid request
    catch(...){

          // threre can be a bug  it depends which part of the code the error will happen
          // there is a posibilty that invalid request gets sent to non realted users fix that bug latter


          QJsonObject jsObj;
          jsObj["kind"] = "invalid request";
          return jsObj;
        }







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
    if((jsDeal["brickT"].toInt()%4 != 0) && (jsDeal["wheatT"].toInt()%4 != 0 )
            && (jsDeal["rockT"].toInt()%4 != 0 ) && (jsDeal["treeT"].toInt()%4 != 0)
            && (jsDeal["sheepT"].toInt()%4 != 0) &&
       jsDeal["brickG"].toInt() <= 0 && jsDeal["wheatG"].toInt() <= 0 && jsDeal["rockG"].toInt() <= 0 && jsDeal["treeG"].toInt() <= 0 && jsDeal["sheepG"].toInt() <= 0 &&
        (jsDeal["brickT"].toInt() + jsDeal["wheatT"].toInt() + jsDeal["rockT"].toInt() + jsDeal["treeT"].toInt() + jsDeal["sheepT"].toInt() ) < 0 &&
            (jsDeal["brickG"].toInt() + jsDeal["wheatG"].toInt() + jsDeal["rockG"].toInt() + jsDeal["treeG"].toInt() + jsDeal["sheepG"].toInt() ) < 0
              && socketDescriptors.at(0) != getSocketOfPlayingPlayer()
            && gameFlow < multiPlayerMode*4){
        QJsonObject jsObj;
        jsObj["kind"] = "Game";
        jsObj["kindOfGame"] = "responseToTransaction";
        jsObj["dealSuccess"] = true;

    }

}




QJsonObject Game::endOfTurn(QJsonObject message, QVector<int> &socketDescriptors)
{

    QJsonObject jsObj;
    static int counter = 0;
    if(gameFlow == 0 || (gameFlow%2 == 1 && gameFlow < 12  ))
    {
        QJsonObject jsObj;
        jsObj["kind"] = "invalid request";
        return jsObj;
    }

    QMap<Color,Player> colToPlayer  = GameData::getColorToPlayer();

    if(gameFlow < multiPlayerMode*4 && gameFlow >= multiPlayerMode*2){
       colToPlayer[ intToColor[(counter + 1)%multiPlayerMode]].setIsTurn(false);
       colToPlayer[ intToColor[counter%multiPlayerMode]].setIsTurn(true);

       jsObj["kind"] = "Game";
       jsObj["kindOfGame"] = "endOfTurn";
       jsObj["whoseTurn"] =convertColorToString(colToPlayer[ intToColor[counter%multiPlayerMode]].getColor());
       counter--;

    }
    else{
        colToPlayer[ intToColor[counter%multiPlayerMode]].setIsTurn(false);
        counter++;
        colToPlayer[ intToColor[counter%multiPlayerMode]].setIsTurn(true);
        QJsonArray jsArry;
        dice.generateRandomDices();
        jsArry.append(dice.getDice1());
        jsArry.append(dice.getDice2());
        // Allocate resources
        jsObj["kind"] = "Game";
        jsObj["kindOfGame"] = "endOfTurn";
        jsObj["whoseTurn"] =convertColorToString(colToPlayer[ intToColor[counter%multiPlayerMode]].getColor());
        jsObj["dices"] = jsArry;
    }


    appendAllSocketsToVector(socketDescriptors);
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
    for(auto &it :GameData::getColorToPlayer()){
        socketToPlayer [it.getSocketDescriptor()] = it;
    }

    return socketToPlayer;
}

int Game::getSocketOfPlayingPlayer()
{
    for(auto & it : GameData::getColorToPlayer()){
        if(it.getIsTurn())
            return it.getSocketDescriptor();
    }
}

QString Game::convertColorToString(Color color)
{
    switch (color) {
    case Color::Blue:
        return "Blue";
    case Color::Red:
        return "Red";
    case Color::Green:
        return "Green";
    case Color::Yellow:
        return "Yellow";

    }
}

bool Game::playerCanEfordIt(QString building, Color colorOfPlayer,bool fromCards)
{

}



void Game::appendAllSocketsToVector(QVector<int>& sockets)
{
     sockets.clear();
     QMap<Color,Player> colorToPlayer = GameData::getColorToPlayer();
     for(auto &it:colorToPlayer)
     {
         sockets.append(it.getSocketDescriptor());
     }
}





QJsonObject Game::winner(bool &iswinner, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}




