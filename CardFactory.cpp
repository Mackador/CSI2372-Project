#include "CardFactory.h"
#include "algorithm"

CardFactory::CardFactory() {
    for (size_t i = 0; i < 104; i++) {
        if (i < 20) {
            deck.push_back(new Blue());
        } else if (i < 38) {
            deck.push_back(new Chili());
        } else if (i < 54) {
            deck.push_back(new Stink());
        } else if (i < 68) {
            deck.push_back(new Green());
        } else if (i < 80) {
            deck.push_back(new Soy());
        } else if (i < 90) {
            deck.push_back(new Black());
        } else if (i < 98) {
            deck.push_back(new Red());
        } else {
            deck.push_back(new Garden());
        }
    }
    random_shuffle(deck.begin(), deck.end());
}

CardFactory* CardFactory::getFactory() {

}

Deck CardFactory::getDeck() {
    return deck;
}