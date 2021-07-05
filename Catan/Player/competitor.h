#ifndef COMPETITOR_H
#define COMPETITOR_H

#include<QString>
#include"Color/Color.h"
class Competitor
{
public:
    Competitor() = default;

private:
public:
    const QString &getName() const;

    int getScore() const;

    void setScore(int score);

    void setName(const QString &name);

private:
    QString name;
    int score;
public:
    Color getColor() const;

    void setColor(Color color);

private:
    Color color;


};

#endif // COMPETITOR_H
