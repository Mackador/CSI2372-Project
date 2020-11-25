#include "DiscardPile.h"

DiscardPile::DiscardPile(istream &, const CardFactory *) {

}

DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
}

Card* DiscardPile::pickUp() {
    Card *res = cards.at(0);
    cards.erase(cards.begin(), cards.begin() + 1);
    return res;
}

Card* DiscardPile::top() {
    return cards.front();
}

void DiscardPile::print(ostream& stream) {
    for
}