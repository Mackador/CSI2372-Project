#include "DiscardPile.h"

DiscardPile::DiscardPile(istream &file, const CardFactory* cardFactory) {
    string line;
    file >> line;
    for (char c : line) {
        cards.push_back(cardFactory->stringToCard(c));
    }
}

DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

Card* DiscardPile::pickUp() {
    Card* c = cards.back();
    cards.pop_back();
    return c;
}

Card * DiscardPile::top() const {
    Card* c = cards.back();
    return c;
}

void DiscardPile::print(ostream& out) {
    for (Card* card : cards) {
        out << *card;
    }
}

int DiscardPile::numCards() {
    return cards.size();
}

ostream& operator<<(ostream &out, const DiscardPile &discardPile) {
    if (discardPile.cards.size() == 0) {
        out << "Empty";
    } else {
        out << *discardPile.top();
    }
    return out;
}