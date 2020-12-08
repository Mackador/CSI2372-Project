//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_HAND_H
#define FINALPROJECT_HAND_H


#include "Card.h"
#include "CardFactory.h"

#include <iostream>
#include <list>

using namespace std;

class Hand {
    list<Card*> cards;
public:
    Hand() = default;
    Hand(istream&, const CardFactory*);
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
    friend ostream& operator<<(ostream&, const Hand&);
};


#endif //FINALPROJECT_HAND_H
