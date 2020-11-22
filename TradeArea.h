#include <iostream>
using namespace std;

class TradeArea {
    TradeArea(istream&, const CardFactory*);
    TradeArea& operator+=(Card*);
    bool legal(Card*);
    Card* trade(string);
    int numCards();
};