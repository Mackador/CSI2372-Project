#include "main.h"

int main() {
    Player* player1;
    Player* player2;
    Table* table;
    CardFactory* cardFactory = CardFactory::getFactory();
    Deck* deck;
    TradeArea* tradeArea;
    DiscardPile* discardPile;
    
    char ans;
    cout << "Would you like to load paused game? (Y)es/(N)o";
	cin >> ans;
    if(ans = 'N'){
        cin.ignore(256, '\n');
		string n1;
		cout <<"What is the name of the first player?";
		getline(cin, n1, '\n');
		cin.clear();
        string n2;
		cout << "What is the name of the second player?";
		getline(cin, n2);
        table = new Table(n1, n2);
        for (Player player : table->players) {
			for (int i = 0; i < 5; i++) {
				player.addToHand(table->gameDeck->draw());
			}

		}
    }
    else {
			//load the old game
			
		}
    string winner;
    while(!table->winner(winner)){
        cout << "Would you like to pause the game? (Y)es/(N)o ";
		cin >> ans;
		if (ans == 'Y'){
            //Pause game
        }
        
				


    }
    
    
    return 0;
}