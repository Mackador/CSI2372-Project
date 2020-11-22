#include <iostream>
#include "CardFactory.h"

using namespace std;

class DiscardPile {
    DiscardPile(istream&, const CardFactory*);
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void print(ostream&);
};