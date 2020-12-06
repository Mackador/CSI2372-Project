#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdexcept>
#include <climits>

using namespace std;

class Card {
public:
    Card() = default;
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual string getName() const  = 0;
    virtual void print(ostream& out) const = 0;
    friend ostream& operator<<(ostream &out, Card &card) {
        card.print(cout);
        return out;
    }
};

class Blue : public Card {
    const int cardsPerCoin[4] = {4, 6, 8, 10};
    const string name = "Blue";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Chili : public Card {
    const int cardsPerCoin[4] = {3, 6, 8, 9};
    const string name = "Chili";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Stink : public Card {
    const int cardsPerCoin[4] = {3, 5, 7, 8};
    const string name = "Stink";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Green : public Card {
    const int cardsPerCoin[4] = {3, 5, 6, 7};
    const string name = "Green";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Soy : public Card {
    const int cardsPerCoin[4] = {2, 4, 6, 7};
    const string name = "soy";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Black : public Card {
    const int cardsPerCoin[4] = {2, 4, 5, 6};
    const string name = "black";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Red : public Card {
    const int cardsPerCoin[4] = {2, 3, 4, 5};
    const string name = "Red";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

class Garden : public Card {
    const int cardsPerCoin[4] = {0, 2, 3, 0};
    const string name = "garden";
public:
    int getCardsPerCoin(int coins) const override { return cardsPerCoin[coins-1]; }
    string getName() const override { return name; }
    void print(ostream &out) const override { out << name[0]; }
};

#endif //CARD_H
