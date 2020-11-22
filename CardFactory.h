#include <iostream>
#include "Deck.h"

using namespace std;

class CardFactory {
    CardFactory();
    static CardFactory* getFactory();
    Deck getDeck();
};