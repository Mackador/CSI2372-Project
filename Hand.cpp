#include "Hand.h"

Hand::Hand(istream &file, const CardFactory* cardFactory) {

}

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

ostream& operator<<(ostream &out, const Hand &hand) {
    for (Card* card : hand.cards) {
        out << *card;
    }
    return out;
}