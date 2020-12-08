//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_TRADEAREA_H
#define FINALPROJECT_TRADEAREA_H


#include "Card.h"
#include "CardFactory.h"

#include <iostream>
#include <list>
#include <iterator>

class TradeArea {
    list<Card*> cards;
public:
    TradeArea(istream&, const CardFactory*);
    TradeArea& operator+=(Card*);
    bool legal(Card*);
    Card* trade(string);
    int numCards();
    friend ostream& operator<<(ostream&, const TradeArea&);
};


#endif //FINALPROJECT_TRADEAREA_H
