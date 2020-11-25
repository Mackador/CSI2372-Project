#include "Player.h"

Player::Player(string &name) {
    this->name = name;
    coins = 0;
}

Player::Player(istream &, const CardFactory *) {

}

string Player::getName() {
    return name;
}

int Player::getNumCoins() {
    return coins;
}

Player& Player::operator+=(int n) {
    coins += n;
}

int Player::getMaxNumChains() {

}

int Player::getNumChain() {

}

Chain& Player::operator[](int i) {

}

void Player::buyThirdChain() {

}

void Player::printHand(ostream& stream, bool arg) {
    if (arg) {
        stream << "whole";
    } else {
        stream << hand.top();
    }
}