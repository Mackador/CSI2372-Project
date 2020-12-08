#ifndef FINALPROJECT_DECK_H
#define FINALPROJECT_DECK_H

#include "Card.h"

#include <vector>
#include <iostream>

using namespace std;

class CardFactory;

class Deck : public vector<Card*> {
public:
    Deck() = default;
    Deck(istream&, const CardFactory*);
    Card* draw();
    friend ostream& operator<<(ostream&, const Deck&);
};


#endif //FINALPROJECT_DECK_H
