#include <iostream>
using namespace std;

class Card {
    virtual int getCardsPerCoin(int);
    virtual string getName();
    virtual void print(ostream&);
};

class Blue: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Chili: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Stink: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Green: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Soy: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Black: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Red: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};

class Garden: public Card {
    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream &out);
};