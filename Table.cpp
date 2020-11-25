#include "Table.h"

Table::Table(istream &file, const CardFactory* cardFactory) {
    deck = cardFactory->getDeck();
    discardPile = new DiscardPile(file, cardFactory);
    tradeArea = new TradeArea(file, cardFactory);
    p1 = new Player(1);
}

void Table::printHand(bool arg) {

}