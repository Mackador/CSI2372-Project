//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_CARDFACTORY_H
#define FINALPROJECT_CARDFACTORY_H

#include "Deck.h"

#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

class CardFactory {
    static CardFactory* instance;
    Deck deck;
public:
    CardFactory();
    static CardFactory* getFactory();
    Deck getDeck();
    Card* stringToCard(char) const;
};


#endif //FINALPROJECT_CARDFACTORY_H
