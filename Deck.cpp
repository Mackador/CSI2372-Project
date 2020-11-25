#include "Deck.h"

Deck::Deck(istream& stream, const CardFactory*) {

}

Card* Deck::draw() {
    Card* card = front();
    this->erase(this->begin(), this->begin() + 1);
    return card;
}