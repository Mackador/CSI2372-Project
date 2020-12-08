//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H


#include "Hand.h"
#include "CardFactory.h"
#include "Chain.h"
#include "Exceptions.h"

#include <iostream>
#include "fstream"
#include "sstream"

using namespace std;


class Player {
    string name;
    int numCoins;
    int maxNumChains;
    int numChains;
    Hand hand;
    vector<Chain_Base*> chains;

public:
    Player(string&);
    Player(istream&, const CardFactory*);
    string getName();
    int getNumCoins();
    Player& operator+=(int);
    int getMaxNumChains();
    int getNumChains();
    Chain_Base& operator[](int i);
    void buyThirdChain();
    void printHand(ostream&, bool);
    void addToHand(Card*);
    void play();
    friend ostream& operator<<(ostream&, Player*);
};

#endif //FINALPROJECT_PLAYER_H
