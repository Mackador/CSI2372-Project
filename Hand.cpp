#include "Hand.h"

Hand::Hand(istream&, const CardFactory*) {

}

Hand& Hand::operator+=(Card* card) {
    hand.push_back(card);
}

Card* Hand::play() {
    Card* card = hand.front();
    hand.pop_front();
    return card;
}

Card* Hand::top() {
    return hand.front();
}

Card* Hand::operator[](int i) {

}