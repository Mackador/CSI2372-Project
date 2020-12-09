#include "Hand.h"

Hand& Hand::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

Card* Hand::play() {
    Card* c = cards.front();
    cards.pop_front();
    return c;
}

Card* Hand::top() {
    Card* c = cards.front();
    return c;
}

Card* Hand::operator[](int i) {
    vector<Card*> v{begin(cards), end(cards)};
    return v.at(i);
}

ostream& operator<<(ostream &out, const Hand &hand) {
    for (Card* card : hand.cards) {
        out << *card;
    }
    return out;
}