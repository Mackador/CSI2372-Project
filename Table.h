#include <iostream>
#include "TradeArea.h"
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"

using namespace std;

class Table {
    Player* players[2];
    Deck* deck;
    DiscardPile* discardPile;
    TradeArea* tradeArea;
    public:
        Table(istream&, const CardFactory*);
        bool win(string&);
        void printHand(bool);
};