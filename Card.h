#include <iostream>
using namespace std;

class Card {
    public:
        virtual int getCardsPerCoin(int);
        virtual string getName();
        virtual void print(ostream&);
};

class Blue: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Chili: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Stink: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Green: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Soy: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Black: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Red: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};

class Garden: public Card {
    public:
        int getCardsPerCoin(int coins);
        string getName();
        void print(ostream &out);
};