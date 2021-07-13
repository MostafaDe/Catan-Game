#ifndef COMPETITOR_H
#define COMPETITOR_H

#include<QString>
#include"Color/Color.h"
class Competitor
{
public:
    Color getColor() const;

    void setColor(Color color);

    int getSocketDescriptor() const;
    void setSocketDescriptor(int newSocketDescriptor);

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);
    Competitor() = default;


    int getScore() const;

    void setScore(int score);



private:
    QString username;
    int score = 0;
    Color color;
    int socketDescriptor;


};

#endif // COMPETITOR_H
