#include <iostream>
#include <list>
using namespace std;

class Hand {
    list<Card*> hand;
    public:
        Hand(istream&, const CardFactory*);
        Hand& operator+=(Card*);
        Card* play();
        Card* top();
        Card* operator[](int);
};