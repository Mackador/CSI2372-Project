#include "Table.h"

template <class T> T* loadLine(istream &file, const CardFactory* cardFactory) {
    string line;
    file >> line;
    istringstream lineStream(line);

    /*if (!in || !lineStream) {
        throw corrupt_game_file_exception();
    }*/

    return new T(lineStream, cardFactory);
}

Table::Table(istream &file, const CardFactory* cardFactory) {
    deck = loadLine<Deck>(file, cardFactory);
    discardPile = loadLine<DiscardPile>(file, cardFactory);
    tradeArea = loadLine<TradeArea>(file, cardFactory);
    players[0] = new Player(file, cardFactory);
    players[1] = new Player(file, cardFactory);
}

Table::Table(Player* p1, Player* p2, Deck* d, DiscardPile* dP, TradeArea* tA) {
    players[0] = p1;
    players[1] = p2;
    deck = d;
    discardPile = dP;
    tradeArea = tA;
}

ostream& operator<<(ostream &out, const Table &table) {
    Player* p1 = table.players[0];
    Player* p2 = table.players[1];
    Deck* d = table.deck;
    DiscardPile* dp = table.discardPile;
    TradeArea* ta = table.tradeArea;

    out << "Player 1:" << endl;
    out << p1 << endl;
    out << "Player 2:" << endl;
    out << p2 << endl;
    out << "Deck: " << *d << endl;
    out << "DiscardPile: " << *dp << endl;
    out << "TradeArea: " << *ta << endl;
    return out;
}

void Table::write() {
    Player* p1 = players[0];
    Player* p2 = players[1];
    Deck* d = deck;
    DiscardPile* dp = discardPile;
    TradeArea* ta = tradeArea;

    //p1.write();
    //p2.write();
    //(*d).write();
    //(*dp).write();
    //(*ta).write();
}

Player* Table::getPlayer1() {
    return players[0];
}

Player* Table::getPlayer2() {
    return players[1];
}

Deck* Table::getDeck() {
    return deck;
}

DiscardPile* Table::getDiscardPile() {
    return discardPile;
}

TradeArea* Table::getTradeArea() {
    return tradeArea;
}
void Table::clearTradeArea() {
    for (Card* c : tradeArea->cards) {
        *discardPile += c;
    }
    tradeArea->cards.clear();
}