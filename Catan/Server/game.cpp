#include "game.h"



Game::Game()
{


}



QJsonObject Game::stopGame(QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}

QJsonObject Game::getBoardInformation(QVector<int> &socketDescriptors)
{


    return GameData::getBoard()->get_board_information();

}

QJsonObject Game::buildHouse(QJsonObject message, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}

QJsonObject Game::buildRoad(QJsonObject message, QVector<int> &socketDescriptors)
{

    QJsonObject jsObj;
    return jsObj;
}

QJsonObject Game::buildBridge(QJsonObject message, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
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
                 ){
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
     *}
    */
   if(socketOfDealer == -1 && !socketExistInListOfSockets(socketDescriptors.at(0),waitingForSocketsResponse)
       &&  waitingForSocketsResponse.size() == 0     )
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




QJsonObject Game::endOfTurn(QJsonObject message, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
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





QJsonObject Game::winner(bool &iswinner, QVector<int> &socketDescriptors)
{
    QJsonObject jsObj;
    return jsObj;
}




