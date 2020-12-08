#include "CardFactory.h"

CardFactory::CardFactory(): deck(Deck()) {
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

CardFactory* CardFactory::instance = nullptr;

CardFactory* CardFactory::getFactory() {
    if (instance == nullptr) {
        instance = new CardFactory;
    }
    return instance;
}

Deck CardFactory::getDeck() {
    return deck;
}

Card * CardFactory::stringToCard(char c) const {
    switch (c) {
        case 'B': return new Blue;
        case 'C': return new Chili;
        case 'S': return new Stink;
        case 'G': return new Green;
        case 's': return new Soy;
        case 'b': return new Black;
        case 'R': return new Red;
        case 'g': return new Garden;
        default: return nullptr;
    }
}