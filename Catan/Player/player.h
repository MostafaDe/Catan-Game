#ifndef PLAYER_H
#define PLAYER_H

#include<QString>
#include<QTcpSocket>

#include"Color/Color.h"
#include"competitor.h"

#include <QList>
class Player
{




public:



    Player() = default;
    const QString &getPassword() const;

    void setPassword(const QString &password);






    Color getColor() const;

    void setColor(Color color);

    unsigned int getScore() const;

    void setScore(unsigned int score);







    bool getPlaying() const;

    void setPlaying(bool newPlaying);

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);



    int getSocketDescriptor() const;
    void setSocketDescriptor(int newSocketDescriptor);

    const QVector<Competitor> &getCompetitors() const;
    void setCompetitors(const QVector<Competitor> &newCompetitors);


    int getCountOfPointCards() const;
    void setCountOfPointCards(int newCountOfPointCards);

    int getCountOfWheatCards() const;
    void setCountOfWheatCards(int newCountOfWheatCards);

    int getCountOfSheepCards() const;
    void setCountOfSheepCards(int newCountOfSheepCards);

    int getCountOfRockCards() const;
    void setCountOfRockCards(int newCountOfRockCards);

    int getCountOfWoodCards() const;
    void setCountOfWoodCards(int newCountOfWoodCards);

    int getCountOfBrickCards() const;
    void setCountOfBrickCards(int newCountOfBrickCards);






    bool getIsTurn() const;
    void setIsTurn(bool newIsTurn);

    int getCountOfHouseCards() const;
    void setCountOfHouseCards(int newCountOfHouseCards);

    int getCountOfBigCityCards() const;
    void setCountOfBigCityCards(int newCountOfBigCityCards);

    int getCountOfRoadCards() const;
    void setCountOfRoadCards(int newCountOfRoadCards);

private:
    QString username;


    unsigned int score = 0;
    Color color;
    QVector<Competitor> competitors;
    bool isTurn = false;
    QString password;

    int socketDescriptor;

    int countOfPointCards = 0 ;
    int countOfWheatCards = 0;
    int countOfSheepCards  = 0;
    int countOfRockCards  = 0 ;
    int countOfWoodCards  = 0;
    int countOfBrickCards  = 0;
    int countOfHouseCards = 5;
    int countOfBigCityCards = 4;
    int countOfRoadCards = 23;







};

#endif // PLAYER_H
