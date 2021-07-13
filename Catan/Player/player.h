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

    int getCountOfShowaleyeCards() const;
    void setCountOfShowaleyeCards(int newCountOfShowaleyeCards);

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

    int getCountOfRoadBuildingCards() const;
    void setCountOfRoadBuildingCards(int newCountOfRoadBuildingCards);

    int getCountOfYearOfPlentyCards() const;
    void setCountOfYearOfPlentyCards(int newCountOfYearOfPlentyCards);

    int getCountOfMonopolyCards() const;
    void setCountOfMonopolyCards(int newCountOfMonopolyCards);

    bool getIsTurn() const;
    void setIsTurn(bool newIsTurn);

private:
    QString username;


    unsigned int score = 0;
    Color color;
    QVector<Competitor> competitors;
    bool isTurn = false;
    QString password;

    int socketDescriptor;

    int countOfShowaleyeCards = 0;
    int countOfPointCards = 0 ;
    int countOfWheatCards = 0;
    int countOfSheepCards  = 0;
    int countOfRockCards  = 0 ;
    int countOfWoodCards  = 0;
    int countOfBrickCards  = 0;
    int countOfRoadBuildingCards = 0;
    int countOfYearOfPlentyCards = 0 ;
    int countOfMonopolyCards  = 0;





};

#endif // PLAYER_H
