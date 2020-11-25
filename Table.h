#include <iostream>
#include "TradeArea.h"
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"

using namespace std;

class Table {
    Player* p1;
    Player* p2;
    Deck* deck;
    DiscardPile* discardPile;
    TradeArea* tradeArea;
    public:
        Table(istream&, const CardFactory*);
        bool win(string&);
        void printHand(bool);
};