#include <iostream>
using namespace std;

class Card {
    virtual int getCardsPerCoin(int);
    virtual string getName();
    virtual void print(ostream&);
};

class Blue: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 4;
            case 2: return 6;
            case 3: return 8;
            case 4: return 10;
        }
    }
    string getName() {
        return "Blue";
    }
    void print(ostream &out);
};

class Chili: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 3;
            case 2: return 6;
            case 3: return 8;
            case 4: return 9;
        }
    }
    string getName() {
        return "Chili";
    }
    void print(ostream &out);
};

class Stink: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 7;
            case 4: return 8;
        }
    }
    string getName() {
        return "Stink";
    }
    void print(ostream &out);
};

class Green: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 6;
            case 4: return 7;
        }
    }
    string getName() {
        return "Green";
    }
    void print(ostream &out);
};

class Soy: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 6;
            case 4: return 7;
        }
    }
    string getName() {
        return "Soy";
    }
    void print(ostream &out);
};

class Black: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 5;
            case 4: return 6;
        }
    }
    string getName() {
        return "Black";
    }
    void print(ostream &out);
};

class Red: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 2;
            case 2: return 3;
            case 3: return 4;
            case 4: return 5;
        }
    }
    string getName() {
        return "Red";
    }
    void print(ostream &out);
};

class Garden: public Card {
    int getCardsPerCoin(int coins) {
        switch (coins) {
            case 1: return 0;
            case 2: return 2;
            case 3: return 3;
            case 4: return 0;
        }
    }
    string getName() {
        return "Garden";
    }
    void print(ostream &out);
};