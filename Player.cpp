#include "Player.h"

// Constructs a player object using their name as input
Player::Player(string& n) {
    name = n;
    numCoins = 0;
    numChains = 0;
    maxNumChains = 2;
}

Player::Player(istream& file, const CardFactory* cardFactory) {
    string line;
    string textHand;
    file >> line;
    name = line;
    file >> line;
    numCoins = stoi(line);
    file >> line;
    maxNumChains = stoi(line);
    file >> line;
    numChains = stoi(line);
    file >> line;
    for (char c : line) {
        hand += cardFactory->stringToCard(c);
    }
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

ostream& operator<<(ostream& out, Player* p) {
    out << "Name: " << p->getName() << endl;
    out << "Number of Coins: " << p->getNumCoins() << endl;
    out << "Chains: " << "chain" << endl;
    out << "Hand: " << p->hand << endl;
    return out;
}