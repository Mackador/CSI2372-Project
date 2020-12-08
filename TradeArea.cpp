#include "TradeArea.h"

TradeArea::TradeArea(istream &file, const CardFactory* cardFactory) {
    string line;
    file >> line;
    for (char c : line) {
        cards.push_back(cardFactory->stringToCard(c));
    }
}

TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

int TradeArea::numCards() {
    return cards.size();
}

ostream& operator<<(ostream &out, const TradeArea &tradeArea) {
    for (Card* card : tradeArea.cards) {
        cout << *card;
    }
    return out;
}