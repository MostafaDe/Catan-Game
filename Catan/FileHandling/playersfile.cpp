#include "playersfile.h"
#define DIR "G:\\Term 2\\AP\\Ap_final_project\\git\\AP-Final-Project\\Catan\\FileHandling\\playersData.json"
PlayersFile::PlayersFile()
{

    file = new  QFile(DIR);
    if(!(*file).open(QIODevice::ReadOnly))
        qDebug() << "not opened"; // throw exception
    QByteArray bArray = (*file).readAll();
    (*file).close();
    QJsonDocument jsDoc = QJsonDocument::fromJson(bArray);
    jsObject = new  QJsonObject(jsDoc.object());
}





//PlayersFile *PlayersFile::createObject()
//{
//    static int  count = 0;

//    if(count == 0 ){
//        PlayersFile* newObject = new PlayersFile();
//        count++;
//        return newObject ;
//    }
//    else
//        return nullptr;
//}

bool PlayersFile::addPlayer(QJsonObject *_jsObject)
{

if(usernameExist((*_jsObject)["username"].toString()))
    throw 0;
    if(!(*file).open(QIODevice::WriteOnly)){
        qDebug() << "not opened";
        throw 1;

}
    QJsonDocument jsDoc ;

    (*jsObject)[(*_jsObject)["username"].toString()] = (*_jsObject);// also some check to object
    jsDoc.setObject((*jsObject));
    file->write(jsDoc.toJson());

    (*file).close();
    return true;


}

bool PlayersFile::usernameExist(QString username)
{
 if((*jsObject)[username].isNull())
     return false;
 else
     return true;
}

bool PlayersFile::deletePlayer(QString username)
{
    if(!(*file).open( QIODevice::WriteOnly)){
        qDebug() << "not opened";
        return false;
    }
    QJsonDocument jsDoc ;

    (*jsObject).remove(username);
    jsDoc.setObject((*jsObject));
    file->write(jsDoc.toJson());

    (*file).close();
    return true;


}

bool PlayersFile::logIn(QString username, QString password)
{
    if(!usernameExist(username))
        throw 0;
    for(int i = 0; i < logInUsernames.size();i++){
        if(logInUsernames.at(i) == username)
            throw  1;
    }
     if((*jsObject)[username].toObject()["password"] == password){
         logInUsernames.append(username);
          return true;

     }

     return true;
}

void PlayersFile::logOut(QString username)
{
    for(int i = 0;i<logInUsernames.size();i++){
        if(username == logInUsernames.at(i)){
            logInUsernames.removeAt(i);
            break;
        }
    }
}





PlayersFile::~PlayersFile()
{
    delete jsObject;
    delete file;
}
