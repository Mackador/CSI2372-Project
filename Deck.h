#include <iostream>
#include "CardFactory.h"

using namespace std;

class Deck {
    Deck(istream&, const CardFactory*);
    Card* draw();
};