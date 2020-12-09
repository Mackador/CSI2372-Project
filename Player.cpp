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

    Chain_Base *chainBase;
    string temp;

    for (int i = 0; i < numChains; i++) {
        file >> line;
        auto in = stringstream(line);
        if (line == "Blue") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Blue>(in, cardFactory);
        } else if (line == "Chili") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Chili>(in, cardFactory);
        } else if (line == "Stink") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Stink>(in, cardFactory);
        } else if (line == "Green") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Green>(in, cardFactory);
        } else if (line == "soy") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Soy>(in, cardFactory);
        } else if (line == "black") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Black>(in, cardFactory);
        } else if (line == "Red") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Red>(in, cardFactory);
        } else if (line == "garden") {
            file >> temp;
            auto in = stringstream(temp);
            chainBase = new Chain<Garden>(in, cardFactory);
        }
        chains.push_back(chainBase);
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

Card* Player::play() {
    return hand.play();
}

void Player::addToChain(Card* c) {
    Chain_Base* chainBase;
    std::string s = c->getName();
    if (s == "Blue")
        chainBase = new Chain<Blue>();
    else if (s == "Blue")
        chainBase = new Chain<Chili>();
    else if (s == "Chili")
        chainBase = new Chain<Stink>();
    else if (s == "Stink")
        chainBase = new Chain<Stink>();
    else if (s == "Green")
        chainBase = new Chain<Green>();
    else if (s == "soy")
        chainBase = new Chain<Soy>();
    else if (s == "black")
        chainBase = new Chain<Black>();
    else if (s == "garden")
        chainBase = new Chain<Garden>();
    else { cout << "Invalid"; }

    *chainBase += c;
    chains.push_back(chainBase);
}


ostream& operator<<(ostream& out, Player* p) {
    out << p->name << endl;
    out << p->numCoins << endl;
    out << p->maxNumChains << endl;
    out << p->numChains << endl;
    out << p->hand;
    for (Chain_Base* c : p->chains) {
        out << endl;
        c->print(out);
    }
    return out;
}