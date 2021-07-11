#ifndef PLAYER_H
#define PLAYER_H

#include<QString>
#include<QTcpSocket>
#include"Card/card.h"
#include"Color/Color.h"
#include"competitor.h"

#include <QList>
class Player
{
public:
    Player() = default;
private:


public:


    bool getIsTurn() const;

    const QString &getPassword() const;

    void setPassword(const QString &password);

    void setIsTurn(bool isTurn);




    Color getColor() const;

    void setColor(Color color);

    unsigned int getScore() const;

    void setScore(unsigned int score);

    const QList<Card *> &getCards() const;

    void setCards(const QList<Card *> &cards);


public:


    bool getLogedIn() const;

    void setLogedIn(bool newLogedIn);

    bool getPlaying() const;

    void setPlaying(bool newPlaying);

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);



    int getSocketDescriptor() const;
    void setSocketDescriptor(int newSocketDescriptor);

    const QVector<Competitor> &getCompetitors() const;
    void setCompetitors(const QVector<Competitor> &newCompetitors);

private:
    QString username;

    QList<Card*> cards;
    unsigned int score;
    Color color;
    QVector<Competitor> competitors;
    bool isTurn;
    QString password;
    bool logedIn;
    bool playing;
    int socketDescriptor;







};

#endif // PLAYER_H
