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
