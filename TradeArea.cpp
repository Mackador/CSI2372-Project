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

bool TradeArea::legal(Card* card) {
    for (Card* c : cards) {
        if (c->getName() == card->getName()) {
            return true;
        }
    }
    return false;
}

Card* TradeArea::trade(string s) {
    auto pos = find_if(cards.cbegin(), cards.cend(), [=](Card* cardInTradeArea) { return s == cardInTradeArea->getName(); });
    Card *c = *pos;
    cards.erase(pos);
    return c;
}

int TradeArea::numCards() {
    return cards.size();
}





ostream& operator<<(ostream &out, const TradeArea &tradeArea) {
    if (tradeArea.cards.size() == 0) {
        out << "Empty";
    } else {
        for (Card *card : tradeArea.cards) {
            cout << *card;
        }
    }
    return out;
}