#ifndef TABLE_H
#define TABLE_H


#include "Deck.h"
#include "DiscardPile.h"
#include "CardFactory.h"
#include "TradeArea.h"


#include "Player.h"

#include <iostream>
#include <fstream>

class Table {
public:

	Deck* gameDeck;
	vector<Player> players;
	TradeArea* tradeArea;
	DiscardPile* discardPile;

public:
	Table(string& playerName1, string& playerName2);
	~Table();
	bool winner(string&);

	friend ostream& operator << (ostream&, Table);
	Table(istream&, CardFactory*);

};

Table::Table(string& playerName1, string& playerName2) {

	Player player1(playerName1);
	Player player2(playerName2);
	players.push_back(player1);
	players.push_back(player2);
	discardPile = new DiscardPile();
	tradeArea = new TradeArea();
	CardFactory* cardFactory = CardFactory::getFactory();
	gameDeck = new Deck(cardFactory);
}

Table::~Table() {}

bool Table::winner(string& playerName) {
	if (players[0].getNumCoins() > players[1].getNumCoins())
		playerName = players[0].getName();
	else
		playerName = players[1].getName();
	return gameDeck->empty();
}

Table::Table(istream& in, CardFactory* cardFactory)
{
	Player* player1 = new Player(in, cardFactory);
	Player* player2 = new Player(in, cardFactory);

	players.push_back(*player1);
	players.push_back(*player2);

	discardPile = new DiscardPile(in, cardFactory);
	tradeArea = new TradeArea(in, cardFactory);
	gameDeck = new Deck(in, cardFactory);

}

ostream& operator<<(ostream& out, Table table)
{
	out << "------Table------\n";
	for (Player player : table.players) {
		out << player << "\n";
	}
	out << "Top of discard pile:\n" << *table.discardPile << "\n" << "Trading area:\n" << *table.tradeArea << "\n";
	out << "-----------------\n";

	return out;
}

#endif //TABLE_H
