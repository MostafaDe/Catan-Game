#include "player.h"


int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}

QTcpSocket *Player::getSocket() const {
    return socket;
}

void Player::setSocket(QTcpSocket *socket) {
    Player::socket = socket;
}

const QList<Card *> &Player::getCards() const {
    return cards;
}

void Player::setCards(const QList<Card *> &cards) {
    Player::cards = cards;
}

unsigned int Player::getScore() const {
    return score;
}

void Player::setScore(unsigned int score) {
    Player::score = score;
}

Color Player::getColor() const {
    return color;
}

void Player::setColor(Color color) {
    Player::color = color;
}

const QList<Competitor *> &Player::getCompetitors() const {
    return competitors;
}

void Player::setCompetitors(const QList<Competitor *> &competitors) {
    Player::competitors = competitors;
}

bool Player::getIsTurn() const {
    return isTurn;
}

void Player::setIsTurn(bool isTurn) {
    Player::isTurn = isTurn;
}

const QString &Player::getPassword() const {
    return password;
}

void Player::setPassword(const QString &password) {
    Player::password = password;
}


