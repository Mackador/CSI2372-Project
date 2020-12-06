#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <iostream>
#include <list>

using namespace std;

class Hand {
    list<Card*> cards;
public:
    Hand() = default;
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
    friend ostream& operator<<(ostream&, const Hand&);
};

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
        out << card << " ";
    }
    return out;
}

#endif //HAND_H
