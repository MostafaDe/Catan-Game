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
    int id;
    QTcpSocket* socket;
public:
    QTcpSocket *getSocket() const;

    bool getIsTurn() const;

    const QString &getPassword() const;

    void setPassword(const QString &password);

    void setIsTurn(bool isTurn);

    const QList<Competitor *> &getCompetitors() const;

    void setCompetitors(const QList<Competitor *> &competitors);

    Color getColor() const;

    void setColor(Color color);

    unsigned int getScore() const;

    void setScore(unsigned int score);

    const QList<Card *> &getCards() const;

    void setCards(const QList<Card *> &cards);

    void setSocket(QTcpSocket *socket);

public:
    int getId() const;

    void setId(int id);

private:
    QList<Card*> cards;
    unsigned int score;
    Color color;
    QList<Competitor*> competitors;
    bool isTurn;
    QString password;






};

#endif // PLAYER_H
