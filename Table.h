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

    Player* getPlayers(int index) const;
    Deck* getDeck() const;
    DiscardPile* getDiscardPile() const;
    TradeArea* getTradeArea() const;


};


#endif //FINALPROJECT_TABLE_H
