//
// Created by Mackador on 12/7/2020.
//

#ifndef FINALPROJECT_TABLE_H
#define FINALPROJECT_TABLE_H


#include "CardFactory.h"
#include "Player.h"
#include "DiscardPile.h"
#include "TradeArea.h"

#include <fstream>
#include <sstream>

class Table {
    Player* players[2];
    Deck* deck;
    DiscardPile* discardPile;
    TradeArea* tradeArea;
public:
    Table(istream&, const CardFactory*);
    Table(Player* p1, Player* p2, Deck* d, DiscardPile* dP, TradeArea* tA);
    bool win(string&);
    void printHand(bool);
    friend ostream& operator<<(ostream & out, const Table &table);
    void write(ofstream&);
    Player* getPlayer1();
    Player* getPlayer2();
    Deck* getDeck();
    DiscardPile* getDiscardPile();
    TradeArea* getTradeArea();
};


#endif //FINALPROJECT_TABLE_H
