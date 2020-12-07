#ifndef PROJECT2_DISCARDPILE_H
#define PROJECT2_DISCARDPILE_H

#include <vector>

#include "Card.h"

class DiscardPile {
    vector<Card*> cards;
public:
    //DiscardPile(istream&, const CardFactory*);
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void print(ostream&);
    friend std::ostream& operator<<(std::ostream&, const DiscardPile&);
};

DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
}

Card* DiscardPile::pickUp() {
    Card* c = cards.back();
    cards.pop_back();
    return c;
}

Card* DiscardPile::top() {
    Card* c = cards.front();
    return c;
}

void DiscardPile::print(ostream& out) {
    for (Card* card : cards) {
        out << *card << " ";
    }
}

#endif //PROJECT2_DISCARDPILE_H