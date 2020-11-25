#include <iostream>
#include <list>
#include "CardFactory.h"

using namespace std;

class TradeArea {
    list<Card*> cards;
    public:
        TradeArea(istream&, const CardFactory*);
        TradeArea& operator+=(Card*);
        bool legal(Card*);
        Card* trade(string);
        int numCards();
};