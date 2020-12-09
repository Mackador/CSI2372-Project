#ifndef FINALPROJECT_CARD_H
#define FINALPROJECT_CARD_H


#include <iostream>
using namespace std;

class Card {
public:
    Card() = default;
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual string getName() const  = 0;
    virtual void print(ostream& out) const = 0;
    friend ostream& operator<<(ostream &out, Card &card);
};

class Blue : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};


class Chili : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};


class Stink : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};


class Green : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};


class Soy : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};


class Black : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};

class Red : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};


class Garden : public Card {
    static const int cardsPerCoin[4];
public:
    static const string name;
    int getCardsPerCoin(int coins) const override;
    string getName() const override;
    void print(ostream &out) const override;
};

#endif //FINALPROJECT_CARD_H
