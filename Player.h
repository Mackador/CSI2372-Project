#include <iostream>
using namespace std;

class Player {
    string name;
    int coins;
    Hand hand;
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