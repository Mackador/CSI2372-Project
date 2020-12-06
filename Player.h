#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

#include <iostream>

using namespace std;

class Player {
    string name;
    int numCoins;
    int maxNumChains;
    int numChains;
    Hand hand;
public:
    Player(string&);
    //Player(istream&, const CardFactory*);
    string getName();
    int getNumCoins();
    Player& operator+=(int);
    int getMaxNumChains();
    int getNumChains();
    //Chain& operator[](int i);
    void buyThirdChain();
    void printHand(ostream&, bool);
    void addToHand(Card*);
    friend ostream& operator<<(ostream&, Player);
};

// Constructs a player object using their name as input
Player::Player(string& n) {
    name = n;
    numCoins = 0;
    numChains = 0;
    maxNumChains = 2;
}

// Returns the name of the player
string Player::getName() {
    return name;
}

// Adds n coins to the player's coins
Player& Player::operator+=(int n) {
    numCoins += n;
    return *this;
}

int Player::getMaxNumChains() {
    return maxNumChains;
}

int Player::getNumCoins() {
    return numCoins;
}

// Chain& operator[](int i);

void Player::buyThirdChain() {
    numCoins -= 2;
    maxNumChains = 3;
}

void Player::printHand(ostream &out, bool all) {
    if (all) {
        out << hand;
    } else { out << hand.top(); }
}

void Player::addToHand(Card* card) {
    hand += card;
}

#endif //PLAYER_H
