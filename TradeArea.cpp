#include "TradeArea.h"

TradeArea::TradeArea(istream&, const CardFactory*) {

}

TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
}

bool TradeArea::legal(Card*) {

}

Card* TradeArea::trade(string) {

}

int TradeArea::numCards() {
    return cards.size();
}