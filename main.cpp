#include "main.h"

static void save(Table& table) {
    ofstream saveFile("new_save.txt");
    if (saveFile) {
        saveFile << table;
        saveFile.close();
    }
}

static Table* load(Table* table, Player* p1, Player* p2, Deck* deck, DiscardPile* discardPile, TradeArea* tradeArea, CardFactory* instance) {
    string fileName;
    cout << "Please enter the file name:" << endl;
    cin >> fileName;
    ifstream file(fileName);
    if (file.is_open()) {
        table = new Table(file, instance);
        return table;
    } else { return NULL; }
}

int main() {
    Table* table;
    Player* p1;
    Player* p2;
    Deck* deck;
    DiscardPile* discardPile;
    TradeArea* tradeArea;
    CardFactory* instance = CardFactory::getFactory();

    string choice;
    cout << "Would you like to load from a previous save or play a new game? (Y/N)" << endl;
    cin >> choice;
    if (choice == "Y") {
        table = load(table, p1, p2, deck, discardPile, tradeArea, instance);
        p1 = table->getPlayer1();
        p2 = table->getPlayer2();
        deck = table->getDeck();
        discardPile = table->getDiscardPile();
        tradeArea = table->getTradeArea();

    } else if (choice == "N") {
        string p1Name;
        cout << "Please enter Player 1's name:" << endl;
        cin >> p1Name;
        string p2Name;
        cout << "Please enter Player 2's name:" << endl;
        cin >> p1Name;
        p1 = new Player(p1Name);
        p2 = new Player(p1Name);
        deck = new Deck(instance->getDeck());
        discardPile = new DiscardPile();
        tradeArea = new TradeArea();
        table = new Table(p1, p2, deck, discardPile, tradeArea);

        for (int i = 0; i < 5; i++) {
            p1->addToHand(deck->draw());
            p2->addToHand(deck->draw());
        }

    } else {
        cout << "You gave an invalid input. Please reload the program.";
    }

    Player* players[2] = {p1, p2};

    string winner;
    while (!table->win(winner)) {
        string choice;
        cout << "Would you like to save the game or continue playing? (S/C)" << endl;
        cin >> choice;

        if (choice == "S") {
            save(*table);
            return 0;

        } else if (choice == "S") {
            for (Player* p : players) {
                p->play();
                // If TradeArea is not empty Add beancards from the TradeArea to chains or discard them.
                p->play();
                // If chain is ended, cards for chain are removed and player receives coin(s)



                for (int i = 0; i < 2 && !deck->empty(); i++) {
                    p->addToHand(deck->draw());
                }
            }
        }
    }
    return 0;
}