#include <iostream>
#include "Chain.h"
#include "Hand.h"
using namespace std;

class Player {
    string name;
    int coins = 0;
    int numChains = 0;
    vector<Chain<Card*>> chains;
    Hand* hand;
    public:
        Player(string&);
        Player(istream&, const CardFactory*);
        string getName();
        int getNumCoins();
        Player& operator+=(int);
        int getMaxNumChains();
        int getNumChain();
        Chain<Card*>& operator[](int i);
        void buyThirdChain();
        void printHand(ostream&, bool);
};