#ifndef TRADEAREA_H
#define TRADEAREA_H
#include "Card.h"
#include <vector>
#include <list>
#include <iostream>
#include "CardFactory.h"

class TradeArea {
public:
	TradeArea();
	~TradeArea();
	
	TradeArea& operator += (Card*);
	Card* tradeCards(string);

	bool legalPlay(Card*);
	bool emptyHand();
	int numCards();
	string getCardType(int);

	friend ostream& operator << (ostream&, TradeArea);
	TradeArea(istream&, CardFactory*);

	
	list<string> cardTypes;
	list<Card*>* playerCards;
	
};

template <typename Container>
bool contains(Container const& container, typename Container::const_reference reference) {
	return std::find(container.begin(), container.end(), reference) != container.end();
}

template <class InputIterator, class T>
InputIterator findName(InputIterator firstName, InputIterator lastName, const T& value) {
	while (firstName != lastName) {
		if ((*firstName)->getName().compare(value) == 0) 
			return firstName;
		++firstName;
	}
	return lastName;
}


bool containsName(list<Card*> const& container, string& reference) {

	list<Card*>::const_iterator firstName = container.begin();
	list<Card*>::const_iterator lastName = container.end();

	while (firstName != lastName) {
		if ((*firstName)->getName().compare(reference) == 0) 
			return true;
		++firstName;
	}
	return false;
}

TradeArea::TradeArea()
{
	playerCards = new list<Card*>;
	cardTypes = list<string>();
}

TradeArea::~TradeArea()
{
	playerCards->clear();
	cardTypes.clear();
}

TradeArea& TradeArea::operator+=(Card* card)
{

	(*playerCards).insert((*playerCards).begin(), card);
	if (contains(cardTypes, card->getName()) == false) {
		cardTypes.emplace_front(card->getName());

	}

	return *this;
}

bool TradeArea::legalPlay(Card* card)
{
	return (playerCards->size() < 3 || contains(cardTypes, card->getName()));
}

bool TradeArea::emptyHand()
{
	return playerCards->empty();
}

Card* TradeArea::tradeCards(string cardName)
{
	if (!empty()) {
		list<Card*>::iterator iter = playerCards->begin();
		while (iter != playerCards->end()) {
			if (cardName.compare((**iter).getName()) == 0) {
				Card* temp = *iter;
				playerCards->erase(iter);
				if (!containsName(*playerCards, cardName)) {
					cardTypes.remove(cardName);
				}
				return temp;
			}
			iter++;
		}
	}
	else {
		return nullptr;
	}
	return nullptr;
}

int TradeArea::numCards()
{
	return playerCards->size();
}

TradeArea::TradeArea(istream& in, CardFactory* cardFactory)
{
	playerCards = new list<Card*>;
	cardTypes = list<string>();

	char cardType[256];
	in.getline(cardType, 256);
	int counter = 0;

	while (cardType[counter] != NULL) {
		counter++;
	}

	counter--;
	for (int i = counter; i >= 0; i--) {
		Card* cardToAdd = ((*cardFactory).getCard(cardType[i]));
		(*this) += cardToAdd;
	}



}

string TradeArea::getCardType(int i)
{
	list<string>::iterator iter = cardTypes.begin();
	while (i > 0 && iter != cardTypes.end()) {
		iter++;
		i--;

	}
	return *iter;
}


ostream& operator<<(ostream& out, TradeArea tradeArea)
{
	for (list<Card*>::iterator it = tradeArea.playerCards->begin(); it != tradeArea.playerCards->end(); it++) {
		out << (*it);
	}
	return out;

}

#endif //TRADEAREA_H
