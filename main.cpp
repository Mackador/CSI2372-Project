#include <iostream>
#include "Card.h"
#include "Chain.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Player.h"
#include "Table.h"

int main() {

    string p1Name, p2Name;

    cout << "Enter Player 1's name: ";
    cin >> p1Name;
    cout << "Enter Player 2's name: ";
    cin >> p2Name;

    Player p1(p1Name), p2(p2Name);
    Player players[] = {p1, p2};
    CardFactory cardFactory;
    Deck deck;
    Table table(cin, &cardFactory);


    while (!deck.empty()) {
        for (Player p : players) {
            table.printHand(false);
        }
    }

    return 0;
}