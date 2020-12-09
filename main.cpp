#include "main.h"

static void save(Table& table) {

    ofstream saveFile("new_save.txt");
    if (saveFile) {
        saveFile << table;
        saveFile.close();
    }
}

static Table* load() {
    CardFactory* cardFactory = CardFactory::getFactory();

    ifstream inputFile("lastGameSaved.txt");
    if (inputFile.is_open()) {
        Table* table = new Table(inputFile, cardFactory);
        return table;
    }
    else
        return NULL;

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
        string fileName;
        cout << "Please enter the file name:" << endl;
        cin >> fileName;
        ifstream file(fileName);
        table = new Table(file, instance);
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

    while (!deck->empty()) {
        for (Player* p : players) {
            cout << "Would you like to pause the game? (Y/N)" << endl;
            cin >> choice;
            if(choice == "Y"){
                //save game
                //make sure exits the loops as well.
            } else{
                cout << *table;
                p->addToHand(deck->draw());
                if (tradeArea->numCards() != 0) {
                    //print trade area
                    cout << *tradeArea << endl;
                    cout << p << endl;
                    // Add beancards from the TradeArea to chains or discard them
                    //NEEDS TO BE IMPLEMENTED
                    cout << "Would you like to add beancards from the TradeArea to chains? (Y/N)" << endl;
                    cin >> choice;
                    if(choice == "Y"){
                        p->play();
                    } else {
                        //discard beancards from tradeArea
                        table->clearTradeArea();
                        /*for(int i = 0; i < tradeArea->numCards(); i++){
                            //this needs to be coded. I tried making a helper func in tradeArea but not compiling.

                        }*/
                        bool check;
                        do {
                            cout << "Playing top card: ";
                            p->printHand(cout, false);
                            p->play();

                            cout << p << endl;
                            cout << "Your hand is: " << endl;
                            p->printHand(cout, true);
                            bool check;
                            cout << "Play another card? (Y/N) " << endl;
                            cin >> check;
                        } while (check && !(p->isHandEmpty()));


                        
                    }

                    if (p->isHandEmpty()) {
                        p->printHand(cout, true);
                        cout << "Please select card to get rid of: (1-1000)" << endl;
                        int cardNum = 1000;

                        while (cardNum < 0 || cardNum >= p->length()) {
                            if (!(cin >> cardNum)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                            }
                        }

                        *discardPile += p->deleteCard(cardNum);

                    }

                }
            }
            
            // ......................
        }
    }

    return 0;
}