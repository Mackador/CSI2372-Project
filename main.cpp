#include <iostream>
#include "Card.h"
#include "Chain.h"
#include "Coins.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Player.h"
#include "Table.h"
#include "TradeArea.h"

int main() {

    string p1Name, p2Name;

    cout << "Enter Player 1's name: ";
    cin >> p1Name;
    cout << "Enter Player 2's name: ";
    cin >> p2Name;

    Player p1(p1Name), p2(p2Name);
    Deck deck;
    Hand p1Hand, p2Hand;
    Table table;



    Player players[] = {p1, p2};

    while (deck.hasCards()) {
        for (Player p : players) {
            table.printHand();
            p.
        }
    }

    return 0;
}