#include "Deck.h"
#include "CardFactory.h"

Deck::Deck(istream &file, const CardFactory* cardFactory) {
    string line;
    file >> line;
    for (char c : line) {
        push_back(cardFactory->stringToCard(c));
    }
}

Card* Deck::draw() {
    Card* c = back();
    pop_back();
    return c;
}

ostream& operator<<(ostream &out, const Deck &deck) {
    for (Card* card : deck) {
        out << *card;
    }
    return out;
}