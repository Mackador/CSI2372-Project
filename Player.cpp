#include "Player.h"

Player::Player(string &name) {
    this->name = name;
}

Player::Player(istream &stream, const CardFactory* cardFactory) {
    hand = new Hand(stream, cardFactory);
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
    return numChains;
}

int Player::getNumChain() {
    return chains.size();
}

Chain<Card*>& Player::operator[](int i) {
    return chains.at(i);
}

void Player::buyThirdChain() {

}

void Player::printHand(ostream& stream, bool arg) {
    if (arg) {
        stream << "whole";
    } else {
        stream << hand->top();
    }
}