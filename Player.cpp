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

    Chain_Base* cb;

    /*for (int i = 0; i < numChains; i++) {
        file >> line;
        auto in = stringstream(line);
        switch (line[0]) {
            case 'B':
                chains.push_back(new Chain<Blue>(in, cardFactory));
            case 'C':
                chains.push_back(new Chain<Chili>(in, cardFactory));
            case 'S':
                chains.push_back(new Chain<Stink>(in, cardFactory));
            case 'G':
                chains.push_back(new Chain<Green>(in, cardFactory));
            case 's':
                chains.push_back(new Chain<Soy>(in, cardFactory));
            case 'b':
                chains.push_back(new Chain<Black>(in, cardFactory));
            case 'R':
                chains.push_back(new Chain<Red>(in, cardFactory));
            case 'g':
                chains.push_back(new Chain<Garden>(in, cardFactory));
        }
    }*/



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
    return chains.size();
}

Chain_Base& Player::operator[](int i) {
    Chain_Base* cb = chains[i];
    return *cb;
}

void Player::buyThirdChain() {
    if (numCoins >= 2) {
        numCoins -= 2;
        maxNumChains = 3;
    } else {
        throw NotEnoughCoinsException();
    }
}

void Player::printHand(ostream &out, bool all) {
    if (all) {
        out << hand;
    } else { out << hand.top(); }
}

void Player::addToHand(Card* card) {
    hand += card;
}

void Player::play() {
    hand.play();
}

ostream& operator<<(ostream& out, Player* p) {
    out << "Name: " << p->getName() << endl;
    out << "Number of Coins: " << p->getNumCoins() << endl;
    out << "Hand: " << p->hand << endl;
    //out << "Chains: " << p->chains << endl;
    return out;
}