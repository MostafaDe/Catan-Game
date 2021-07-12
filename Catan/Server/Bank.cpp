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
if(multiPlayerMode == 3){
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

    emit sendMessage(jsObject1,socketToPlayerList[0].first);
    players.append(socketToPlayerList[0].second);

}
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
        emit sendMessage(jsObject1,socketToPlayerList[1].first);
        players.append(socketToPlayerList[1].second);
}
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
        emit sendMessage(jsObject1,socketToPlayerList[2].first);
        players.append(socketToPlayerList[2].second);
}
        game = new Game(players);

}
if(multiPlayerMode == 4){

}
}

void Bank::stopTheGame()
{

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
        jsObj["errorMessage"] = "usename exists please try another one";
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
    Player player;
    player.setUsername(username);
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








