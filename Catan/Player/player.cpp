#include "player.h"




bool Player::getLogedIn() const
{
    return logedIn;
}

void Player::setLogedIn(bool newLogedIn)
{
    logedIn = newLogedIn;
}

bool Player::getPlaying() const
{
    return playing;
}

void Player::setPlaying(bool newPlaying)
{
    playing = newPlaying;
}

const QString &Player::getUsername() const
{
    return username;
}

void Player::setUsername(const QString &newUsername)
{
    username = newUsername;
}

int Player::getSocketDescriptor() const
{
    return socketDescriptor;
}

void Player::setSocketDescriptor(int newSocketDescriptor)
{
    socketDescriptor = newSocketDescriptor;
}

const QVector<Competitor> &Player::getCompetitors() const
{
    return competitors;
}

void Player::setCompetitors(const QVector<Competitor> &newCompetitors)
{
    competitors = newCompetitors;
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


