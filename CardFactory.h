#include <iostream>
#include "Deck.h"
using namespace std;

class CardFactory {
    Deck deck;
    public:
        CardFactory();
        static CardFactory* getFactory();
        Deck getDeck();
};