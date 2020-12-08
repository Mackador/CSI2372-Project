//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_DISCARDPILE_H
#define FINALPROJECT_DISCARDPILE_H

#include <vector>

#include "Card.h"
#include "CardFactory.h"

class DiscardPile {
    vector<Card*> cards;
public:
    DiscardPile(istream&, const CardFactory*);
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card * top() const;
    void print(ostream&);
    friend ostream& operator<<(std::ostream&, const DiscardPile&);
};


#endif //FINALPROJECT_DISCARDPILE_H
