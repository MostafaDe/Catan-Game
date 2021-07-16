#ifndef DICE_H
#define DICE_H


class Dice
{
public:
    Dice();
    void generateRandomDices();
    int getDice1() const;
    void setDice1(int newDice1);

    int getDice2() const;
    void setDice2(int newDice2);

private:
    int dice1;
    int dice2;
};

#endif // DICE_H
