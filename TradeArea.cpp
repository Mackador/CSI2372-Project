#include "TradeArea.h"

TradeArea::TradeArea(istream&, const CardFactory*) {

}

TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

bool TradeArea::legal(Card* card) {
    return card == cards.front();
}

Card* TradeArea::trade(string) {
    // trade
}

int TradeArea::numCards() {
    return cards.size();
}