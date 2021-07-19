//
// Created by apadana on ۰۵/۰۷/۲۰۲۱.
//

#include "Bank.h"






Bank::Bank(QObject *parent)

{

//    QJsonObject jo;
//    jo["ali"] = "12346";
//    jo["hassan"] = "45645";
//    QJsonDocument jsDoc(jo);
//    QString jsString = QString::fromLatin1(jsDoc.toJson());
//    fortunes << jsString;


}

void Bank::startServer()
{
    if(!this->listen(QHostAddress::Any,8080))
        qDebug()<< "couldnt start server";
    else{
         qDebug()<< "start server";
    }
}

void Bank::startTheGame()
{
QVector<Player> players;
QJsonObject jsO1;
if(multiPlayerMode == 3){

    /* 0->Red
     * 1->Green
     * 2->Blue*/
    if(true){
    Competitor comp1;
    Competitor comp2;
    comp1.setColor(Color::Green);
    comp2.setColor(Color::Blue);
    comp1.setSocketDescriptor(socketToPlayerList[1].first);
    comp2.setSocketDescriptor(socketToPlayerList[2].first);
    comp1.setUsername(socketToPlayerList[1].second.getUsername());
    comp2.setUsername(socketToPlayerList[2].second.getUsername());
    QVector<Competitor> comps;
    comps.push_back(comp1);
    comps.push_back(comp2);
    socketToPlayerList[0].second.setColor(Color::Red);
    socketToPlayerList[0].second.setCompetitors(comps);
    socketToPlayerList[0].second.setIsTurn(true);
    QJsonObject jsObject1;
    QJsonObject jsObject2;
    jsObject2["size"] = 2;
    QJsonArray js;
    js.append("green");
    js.append(socketToPlayerList[1].second.getUsername());

    jsObject2["comp1"]  = js;
    QJsonArray js1;
    js1.append("blue");
    js1.append(socketToPlayerList[2].second.getUsername());
    jsObject2["comp2"]  = js1;
    jsObject1["kind"] = "startGame";
    jsObject1["color"] ="red";
    jsObject1["comps"] = jsObject2;
    jsObject1["username"] =socketToPlayerList[0].second.getUsername();
    jsO1 = jsObject1;
//    emit sendMessage(jsObject1,socketToPlayerList[0].first);
    players.append(socketToPlayerList[0].second);

}
    QJsonObject jsO2;
    if(true){
        Competitor comp1;
        Competitor comp2;
        comp1.setColor(Color::Red);
        comp2.setColor(Color::Blue);
        comp1.setSocketDescriptor(socketToPlayerList[0].first);
        comp2.setSocketDescriptor(socketToPlayerList[2].first);
        comp1.setUsername(socketToPlayerList[0].second.getUsername());
        comp2.setUsername(socketToPlayerList[2].second.getUsername());
        QVector<Competitor> comps;
        comps.push_back(comp1);
        comps.push_back(comp2);
        socketToPlayerList[1].second.setColor(Color::Green);
        socketToPlayerList[1].second.setCompetitors(comps);
        QJsonObject jsObject1;
        QJsonObject jsObject2;
        jsObject2["size"] = 2;
        QJsonArray js;
        js.append("red");
        js.append(socketToPlayerList[0].second.getUsername());

        jsObject2["comp1"]  = js;
        QJsonArray js1;
        js1.append("blue");
        js1.append(socketToPlayerList[2].second.getUsername());
        jsObject2["comp2"]  = js1;
        jsObject1["kind"] = "startGame";
        jsObject1["color"] ="green";

        jsObject1["comps"] = jsObject2;
        jsObject1["username"] =socketToPlayerList[1].second.getUsername();
         jsO2 = jsObject1;
//        emit sendMessage(jsObject1,socketToPlayerList[1].first);
        players.append(socketToPlayerList[1].second);
}
    QJsonObject jsO3;
    if(true){
        Competitor comp1;
        Competitor comp2;
        comp1.setColor(Color::Red);
        comp2.setColor(Color::Green);
        comp1.setSocketDescriptor(socketToPlayerList[0].first);
        comp2.setSocketDescriptor(socketToPlayerList[1].first);
        comp1.setUsername(socketToPlayerList[0].second.getUsername());
        comp2.setUsername(socketToPlayerList[1].second.getUsername());
        QVector<Competitor> comps;
        comps.push_back(comp1);
        comps.push_back(comp2);
        socketToPlayerList[2].second.setColor(Color::Blue);
        socketToPlayerList[2].second.setCompetitors(comps);
        QJsonObject jsObject1;
        QJsonObject jsObject2;
        jsObject2["size"] = 2;
        QJsonArray js;
        js.append("red");
        js.append( socketToPlayerList[0].second.getUsername());
        jsObject2["comp1"]  = js;
        QJsonArray js1;
        js1.append("green");
        js1.append(socketToPlayerList[1].second.getUsername());
        jsObject2["comp2"]  = js1;
        jsObject1["kind"] = "startGame";
        jsObject1["color"] ="blue";
        jsObject1["comps"] = jsObject2;
        jsObject1["username"] =socketToPlayerList[2].second.getUsername();
        jsO3 = jsObject1;
//        emit sendMessage(jsObject1,socketToPlayerList[2].first);
        players.append(socketToPlayerList[2].second);
}
    game = new Game();
    gameData = new GameData(socketToPlayerList);
    emit sendMessage(jsO1,socketToPlayerList[0].first);
    emit sendMessage(jsO2,socketToPlayerList[1].first);
    emit sendMessage(jsO3,socketToPlayerList[2].first);
}
if(multiPlayerMode == 4){
    // 0 -> red
    // 1 -> green
    // 2 -> blue
    // 3 -> yellow
        if(true){
        Competitor comp1;
        Competitor comp2;
        Competitor comp3;
        comp1.setColor(Color::Green);
        comp2.setColor(Color::Blue);
        comp3.setColor(Color::Yellow);
        comp1.setSocketDescriptor(socketToPlayerList[1].first);
        comp2.setSocketDescriptor(socketToPlayerList[2].first);
        comp3.setSocketDescriptor(socketToPlayerList[3].first);
        comp1.setUsername(socketToPlayerList[1].second.getUsername());
        comp2.setUsername(socketToPlayerList[2].second.getUsername());
        comp3.setUsername(socketToPlayerList[3].second.getUsername());
        QVector<Competitor> comps;
        comps.push_back(comp1);
        comps.push_back(comp2);
        comps.push_back(comp3);
        socketToPlayerList[0].second.setColor(Color::Red);
        socketToPlayerList[0].second.setCompetitors(comps);
        socketToPlayerList[0].second.setIsTurn(true);
        QJsonObject jsObject1;
        QJsonObject jsObject2;
        jsObject2["size"] = 3;
        QJsonArray js;
        js.append("green");
        js.append(socketToPlayerList[1].second.getUsername());
        jsObject2["comp1"]  = js;
        QJsonArray js1;
        js1.append("blue");
        js1.append(socketToPlayerList[2].second.getUsername());
        jsObject2["comp2"]  = js1;
        QJsonArray js2;
        js1.append("yellow");
        js1.append(socketToPlayerList[3].second.getUsername());
        jsObject2["comp3"]  = js2;
        jsObject1["kind"] = "startGame";
        jsObject1["color"] ="red";
        jsObject1["comps"] = jsObject2;
        jsObject1["username"] =socketToPlayerList[0].second.getUsername();
        emit sendMessage(jsObject1,socketToPlayerList[0].first);
        players.append(socketToPlayerList[0].second);


    }
        if(true){

        Competitor comp1;
        Competitor comp2;
        Competitor comp3;
        comp1.setColor(Color::Blue);
        comp2.setColor(Color::Yellow);
        comp3.setColor(Color::Red);
        comp1.setSocketDescriptor(socketToPlayerList[2].first);
        comp2.setSocketDescriptor(socketToPlayerList[3].first);
        comp3.setSocketDescriptor(socketToPlayerList[0].first);
        comp1.setUsername(socketToPlayerList[1].second.getUsername());
        comp2.setUsername(socketToPlayerList[3].second.getUsername());
        comp3.setUsername(socketToPlayerList[0].second.getUsername());
        QVector<Competitor> comps;
        comps.push_back(comp1);
        comps.push_back(comp2);
        comps.push_back(comp3);
        socketToPlayerList[1].second.setColor(Color::Green);
        socketToPlayerList[1].second.setCompetitors(comps);
        QJsonObject jsObject1;
        QJsonObject jsObject2;
        jsObject2["size"] = 3;
        QJsonArray js;
        js.append("blue");
        js.append(socketToPlayerList[2].second.getUsername());
        jsObject2["comp1"]  = js;
        QJsonArray js1;
        js1.append("yellow");
        js1.append(socketToPlayerList[3].second.getUsername());
        jsObject2["comp2"]  = js1;
        QJsonArray js2;
        js1.append("red");
        js1.append(socketToPlayerList[0].second.getUsername());
        jsObject2["comp3"]  = js2;
        jsObject1["kind"] = "startGame";
        jsObject1["color"] ="red";
        jsObject1["comps"] = jsObject2;
        jsObject1["username"] =socketToPlayerList[1].second.getUsername();

        emit sendMessage(jsObject1,socketToPlayerList[1].first);
        players.append(socketToPlayerList[1].second);


    }
        if(true){

        Competitor comp1;
        Competitor comp2;
        Competitor comp3;
        comp1.setColor(Color::Green);
        comp2.setColor(Color::Yellow);
        comp3.setColor(Color::Red);
        comp1.setSocketDescriptor(socketToPlayerList[1].first);
        comp2.setSocketDescriptor(socketToPlayerList[3].first);
        comp3.setSocketDescriptor(socketToPlayerList[0].first);
        comp1.setUsername(socketToPlayerList[1].second.getUsername());
        comp2.setUsername(socketToPlayerList[3].second.getUsername());
        comp3.setUsername(socketToPlayerList[0].second.getUsername());
        QVector<Competitor> comps;
        comps.push_back(comp1);
        comps.push_back(comp2);
        comps.push_back(comp3);
        socketToPlayerList[2].second.setColor(Color::Blue);
        socketToPlayerList[2].second.setCompetitors(comps);
        QJsonObject jsObject1;
        QJsonObject jsObject2;
        jsObject2["size"] = 3;
        QJsonArray js;
        js.append("green");
        js.append(socketToPlayerList[1].second.getUsername());
        jsObject2["comp1"]  = js;
        QJsonArray js1;
        js1.append("yellow");
        js1.append(socketToPlayerList[3].second.getUsername());
        jsObject2["comp2"]  = js1;
        QJsonArray js2;
        js1.append("red");
        js1.append(socketToPlayerList[0].second.getUsername());
        jsObject2["comp3"]  = js2;
        jsObject1["kind"] = "startGame";
        jsObject1["color"] ="red";
        jsObject1["comps"] = jsObject2;
        jsObject1["username"] =socketToPlayerList[2].second.getUsername();

        emit sendMessage(jsObject1,socketToPlayerList[2].first);
        players.append(socketToPlayerList[2].second);


    }
        if(true){

        Competitor comp1;
        Competitor comp2;
        Competitor comp3;
        comp1.setColor(Color::Green);
        comp2.setColor(Color::Blue);
        comp3.setColor(Color::Red);
        comp1.setSocketDescriptor(socketToPlayerList[1].first);
        comp2.setSocketDescriptor(socketToPlayerList[2].first);
        comp3.setSocketDescriptor(socketToPlayerList[0].first);
        comp1.setUsername(socketToPlayerList[1].second.getUsername());
        comp2.setUsername(socketToPlayerList[2].second.getUsername());
        comp3.setUsername(socketToPlayerList[0].second.getUsername());
        QVector<Competitor> comps;
        comps.push_back(comp1);
        comps.push_back(comp2);
        comps.push_back(comp3);
        socketToPlayerList[3].second.setColor(Color::Yellow);
        socketToPlayerList[3].second.setCompetitors(comps);
        QJsonObject jsObject1;
        QJsonObject jsObject2;
        jsObject2["size"] = 3;
        QJsonArray js;
        js.append("green");
        js.append(socketToPlayerList[1].second.getUsername());
        jsObject2["comp1"]  = js;
        QJsonArray js1;
        js1.append("blue");
        js1.append(socketToPlayerList[2].second.getUsername());
        jsObject2["comp2"]  = js1;
        QJsonArray js2;
        js1.append("red");
        js1.append(socketToPlayerList[0].second.getUsername());
        jsObject2["comp3"]  = js2;
        jsObject1["kind"] = "startGame";
        jsObject1["color"] ="red";
        jsObject1["comps"] = jsObject2;
        jsObject1["username"] =socketToPlayerList[3].second.getUsername();

        emit sendMessage(jsObject1,socketToPlayerList[3].first);
        players.append(socketToPlayerList[3].second);


    }




}
game = new Game();
gameData = new GameData(socketToPlayerList);

}
void Bank::stopTheGame()
{
    QJsonObject response;
    QVector<int> socketDescs;
    response = game->stopGame( socketDescs);
    for(int it:socketDescs){
        emit sendMessage(response,it);
    }
}


void Bank::signUp(QJsonObject message,int socketDescriptor)
{
    QJsonObject jsObj;


jsObj["kind"] = "SignUp";
try{
        file.addPlayer(&message);


           jsObj["success"] = true;
           emit sendMessage(jsObj,socketDescriptor);
           return;



}catch(int errorType){
    jsObj["success"] = false;
    if(errorType == 0){
        jsObj["errorMessage"] = "username exists please try another one";
        emit sendMessage(jsObj,socketDescriptor);
        return;
    }
    if(errorType == 1){
         jsObj["errorMessage"] = "error while signing you up please try again";
         emit sendMessage(jsObj,socketDescriptor);
    }
}

}

void Bank::logIn(QString username, QString password, int socketDescriptor)
{
    QJsonObject jsObj;
    jsObj["kind"] = "LogIn";
    try{

     file.logIn(username,password);


        jsObj["success"] = true;
        emit sendMessage(jsObj,socketDescriptor);



    }catch(int a){

        if(a == 1){
        jsObj["errorMessage"] = "there cant be multiple login users";
        jsObj["success"] = false;
        emit sendMessage(jsObj,socketDescriptor);
        return ;
        }
        if(a == 0){
        jsObj["errorMessage"] = "Wrong Username or Password";
        jsObj["success"] = false;
        emit sendMessage(jsObj,socketDescriptor);
        return ;
        }
    }

}

void Bank::addReadyToPlayNumber(int socketDescriptor,QString username)
{
    if(socketToPlayerList.size() !=0)
        for(auto &it:socketToPlayerList)
             if(it.first == socketDescriptor)
                 return;


    Player player;
    player.setUsername(username);
    player.setSocketDescriptor(socketDescriptor);
    QPair <int,Player> pair(socketDescriptor,player);
    socketToPlayerList.push_back(pair);
    readyToPlayNumbers++;
    if(readyToPlayNumbers == multiPlayerMode)
        startTheGame();
}

void Bank::lowerReadyToPlayNumber(int socketDescriptor)
{
    for(int i = 0; i < socketToPlayerList.size();i++){
     if(socketToPlayerList.at(i).first == socketDescriptor){
         socketToPlayerList.removeAt(i);
         break;
     }
    }
    readyToPlayNumbers--;
    stopTheGame();
}

void Bank::logOut(QString username)
{
    file.logOut(username);
}

void Bank::gaming(QJsonObject message,int socketDescriptor)
{
    QJsonObject response;
    QVector<int> socketDescs;
    socketDescs.append(socketDescriptor);

if(message["kindOfGame"] == "getBoardInformation"){
      response = game->getBoardInformation(socketDescs);
      response["kindOfGame"] = "getBoardInformation";
}
else
if(message["kindOfGame"] == "buildHouse"){
    response = game->buildHouse(message,socketDescs);
}
else
if(message["kindOfGame"] == "buildRoad"){
   response = game->buildRoad(message,socketDescs);
}

else
if(message["kindOfGame"] == "transaction"){
   response = game->transactionToPlayers(message,socketDescs);
}

else
if(message["kindOfGame"] == "endOfTurn"){
  response = game->endOfTurn(socketDescs);
}
else{
    response["kind"] = "invalid request";
}


for(int it:socketDescs){
    emit sendMessage(response,it);
}
socketDescs.clear();
bool iswinner = false;
response = game->winner(iswinner,socketDescs);
if(iswinner){
    for(int it:socketDescs){
        emit sendMessage(response,it);
    }
}
}



void Bank::incomingConnection(qintptr socketDescriptor)
{

     Player player;
     qDebug() << "new connection";
     BankThread * bankTh = new BankThread(socketDescriptor,this);

     connect(bankTh,&QThread::finished,bankTh,&QThread::deleteLater);
     connect(bankTh,&BankThread::signUp,this,&Bank::signUp);


     connect(this,&Bank::sendMessage,bankTh,&BankThread::setMessage);
     connect(bankTh,&BankThread::logIn,this,&Bank::logIn);
     connect(bankTh,&BankThread::logOut,this,&Bank::logOut);
     connect(bankTh,&BankThread::readyPlay,this,&Bank::addReadyToPlayNumber);
     connect(bankTh,&BankThread::notReadyPlay,this,&Bank::lowerReadyToPlayNumber);
     connect(bankTh,&BankThread::gaming,this,&Bank::gaming);


     bankTh->start();


//static int i =0;
//i++;
//qDebug() << hasPendingConnections();

//    QPointer<QTcpSocket> tcpSocket = new QTcpSocket;


//    tcpSocket->setSocketDescriptor(socketDescriptor);

//    connect(tcpSocket, &QAbstractSocket::disconnected,
//            tcpSocket, &QObject::deleteLater);

//    connect(tcpSocket, &QAbstractSocket::destroyed,
//            this, &Bank::deleteSocket);
//    socketToPlayer[tcpSocket] = Player();


//    if(countOfLogedInPlayers() == 3){
//        #ifdef Q_OS_WIN // windows
//            Sleep(uint(TIME_TO_WAIT));
//        #else // linux,...
//            struct timespec ts = { TIME_TO_WAIT / 1000, (TIME_TO_WAIT % 1000) * 1000 * 1000 };
//            nanosleep(&ts, NULL);
//        #endif
//          if(countOfLogedInPlayers() == 3){
//           emit gameStarted(true);
//           return;
//          }
//    }

}








