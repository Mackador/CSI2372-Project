#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck : public vector<Card*> {
public:
    //Deck(istream, const CardFactory*);
    Card* draw();
    friend std::ostream& operator<<(std::ostream&, const Deck&);
};

Card* Deck::draw() {
    Card* c = back();
    pop_back();
    return c;
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (Card* card : deck) {
        out << *card << " ";
    }
    return out;
}

#endif //DECK_H
