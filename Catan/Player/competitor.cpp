#include "competitor.h"




int Competitor::getScore() const {
    return score;
}

void Competitor::setScore(int score) {
    Competitor::score = score;
}

const QString &Competitor::getUsername() const
{
    return username;
}

void Competitor::setUsername(const QString &newUsername)
{
    username = newUsername;
}

Color Competitor::getColor() const {
    return color;
}

void Competitor::setColor(Color color) {
    Competitor::color = color;
}

int Competitor::getSocketDescriptor() const
{
    return socketDescriptor;
}

void Competitor::setSocketDescriptor(int newSocketDescriptor)
{
    socketDescriptor = newSocketDescriptor;
}
