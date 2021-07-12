#ifndef PLAYERSFILE_H
#define PLAYERSFILE_H

#include<QJsonDocument>
#include<QJsonObject>
#include<QString>
#include<QFile>
using namespace std;
class PlayersFile
{
public:
//    static PlayersFile* createObject();
    PlayersFile();
    bool addPlayer(QJsonObject* jsObject); // if adding was succesful return true else return false
    bool usernameExist(QString username);
    bool deletePlayer(QString username);// if deleting was succesful return true else return false
//    QJsonValue & operator[](QString username);/* implement latter */
    bool logIn(QString username,QString password);// if logIn was succesful return true else return false
//    void logOut(QString username,QString password);/* implement latter */
    void logOut(QString username);
    bool EditPlayer(QString username);
    ~PlayersFile();

private:
    QJsonObject* jsObject;
    QFile* file;
    QList<QString> logInUsernames;





};

#endif // PLAYERSFILE_H
