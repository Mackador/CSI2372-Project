//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H


#include "Hand.h"
#include "CardFactory.h"

#include <iostream>
#include "fstream"

using namespace std;

class Player {
    string name;
    int numCoins;
    int maxNumChains;
    int numChains;
    Hand hand;
public:
    Player(string&);
    Player(istream&, const CardFactory*);
    string getName();
    int getNumCoins();
    Player& operator+=(int);
    int getMaxNumChains();
    int getNumChains();
    //Chain& operator[](int i);
    void buyThirdChain();
    void printHand(ostream&, bool);
    void addToHand(Card*);
    friend ostream& operator<<(ostream&, Player*);
};

#endif //FINALPROJECT_PLAYER_H
