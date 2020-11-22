#include <iostream>
#include "CardFactory.h"
#include "Chain.h"

using namespace std;

class Player {
    public:
        Player(string&);
        Player(istream&, const CardFactory*);
        string getName();
        int getNumCoins();
        Player& operator+=(int);
        int getMaxNumChains();
        int getNumChain();
        Chain& operator[](int i);
        void buyThirdChain();
        void printHand(ostream&, bool);
};