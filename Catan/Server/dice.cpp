#include "dice.h"
#include<stdlib.h>
using namespace std;
Dice::Dice()
{
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;
}

void Dice::generateRandomDices()
{
 dice1 = (rand() % 6) + 1;
 dice2 = (rand() % 6) + 1;
}

int Dice::getDice1() const
{
    return dice1;
}

void Dice::setDice1(int newDice1)
{
    dice1 = newDice1;
}

int Dice::getDice2() const
{
    return dice2;
}

void Dice::setDice2(int newDice2)
{
    dice2 = newDice2;
}
