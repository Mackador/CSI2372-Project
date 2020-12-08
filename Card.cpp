#include "Card.h"

const int Blue::cardsPerCoin[4] = {4, 6, 8, 10};
const string Blue::name = "Blue";
int Blue::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Blue::getName() const { return name; }
void Blue::print(ostream &out) const { out << name[0]; }

const int Chili::cardsPerCoin[4] = {3, 6, 8, 9};
const string Chili::name = "Chili";
int Chili::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Chili::getName() const { return name; }
void Chili::print(ostream &out) const { out << name[0]; }

const int Stink::cardsPerCoin[4] = {3, 5, 7, 8};
const string Stink::name = "Stink";
int Stink::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Stink::getName() const { return name; }
void Stink::print(ostream &out) const { out << name[0]; }

const int Green::cardsPerCoin[4] = {3, 5, 6, 7};
const string Green::name = "Green";
int Green::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Green::getName() const { return name; }
void Green::print(ostream &out) const { out << name[0]; }

const int Soy::cardsPerCoin[4] = {2, 4, 6, 7};
const string Soy::name = "soy";
int Soy::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Soy::getName() const { return name; }
void Soy::print(ostream &out) const { out << name[0]; }

const int Black::cardsPerCoin[4] = {2, 4, 5, 6};
const string Black::name = "black";
int Black::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Black::getName() const { return name; }
void Black::print(ostream &out) const { out << name[0]; }

const int Red::cardsPerCoin[4] = {2, 3, 4, 5};
const string Red::name = "Red";
int Red::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Red::getName() const { return name; }
void Red::print(ostream &out) const { out << name[0]; }

const int Garden::cardsPerCoin[4] = {0, 2, 3, 0};
const string Garden::name = "garden";
int Garden::getCardsPerCoin(int coins) const { return cardsPerCoin[coins-1]; }
string Garden::getName() const { return name; }
void Garden::print(ostream &out) const { out << name[0]; }

ostream& operator<<(ostream &out, Card &card) {
    card.print(out);
    return out;
}