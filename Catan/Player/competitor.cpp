#include "competitor.h"



const QString &Competitor::getName() const {
    return name;
}

void Competitor::setName(const QString &name) {
    Competitor::name = name;
}

int Competitor::getScore() const {
    return score;
}

void Competitor::setScore(int score) {
    Competitor::score = score;
}

Color Competitor::getColor() const {
    return color;
}

void Competitor::setColor(Color color) {
    Competitor::color = color;
}
