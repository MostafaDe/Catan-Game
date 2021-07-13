#include "player.h"







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

int Player::getCountOfShowaleyeCards() const
{
    return countOfShowaleyeCards;
}

void Player::setCountOfShowaleyeCards(int newCountOfShowaleyeCards)
{
    countOfShowaleyeCards = newCountOfShowaleyeCards;
}

int Player::getCountOfPointCards() const
{
    return countOfPointCards;
}

void Player::setCountOfPointCards(int newCountOfPointCards)
{
    countOfPointCards = newCountOfPointCards;
}

int Player::getCountOfWheatCards() const
{
    return countOfWheatCards;
}

void Player::setCountOfWheatCards(int newCountOfWheatCards)
{
    countOfWheatCards = newCountOfWheatCards;
}

int Player::getCountOfSheepCards() const
{
    return countOfSheepCards;
}

void Player::setCountOfSheepCards(int newCountOfSheepCards)
{
    countOfSheepCards = newCountOfSheepCards;
}

int Player::getCountOfRockCards() const
{
    return countOfRockCards;
}

void Player::setCountOfRockCards(int newCountOfRockCards)
{
    countOfRockCards = newCountOfRockCards;
}

int Player::getCountOfWoodCards() const
{
    return countOfWoodCards;
}

void Player::setCountOfWoodCards(int newCountOfWoodCards)
{
    countOfWoodCards = newCountOfWoodCards;
}

int Player::getCountOfBrickCards() const
{
    return countOfBrickCards;
}

void Player::setCountOfBrickCards(int newCountOfBrickCards)
{
    countOfBrickCards = newCountOfBrickCards;
}

int Player::getCountOfRoadBuildingCards() const
{
    return countOfRoadBuildingCards;
}

void Player::setCountOfRoadBuildingCards(int newCountOfRoadBuildingCards)
{
    countOfRoadBuildingCards = newCountOfRoadBuildingCards;
}

int Player::getCountOfYearOfPlentyCards() const
{
    return countOfYearOfPlentyCards;
}

void Player::setCountOfYearOfPlentyCards(int newCountOfYearOfPlentyCards)
{
    countOfYearOfPlentyCards = newCountOfYearOfPlentyCards;
}

int Player::getCountOfMonopolyCards() const
{
    return countOfMonopolyCards;
}

void Player::setCountOfMonopolyCards(int newCountOfMonopolyCards)
{
    countOfMonopolyCards = newCountOfMonopolyCards;
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





const QString &Player::getPassword() const {
    return password;
}

void Player::setPassword(const QString &password) {
    Player::password = password;
}


