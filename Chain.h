#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "CardFactory.h"
using namespace std;



class Chain_Base {
    virtual void set_interface() = 0;
    char beanType;
public:
    char getBeanType() { return beanType; }
};

template <class T> class Chain {
public:
    Chain(istream&, const CardFactory*);
    Chain();
    Chain<T>& operator+=(Card*);
    int sell();
    friend ostream& operator<<(ostream& out, const Chain& chain1) {
        if(chain1.chain.empty()){
            out << endl;
            return out;
        }

        char delimeter = ' ';
        out << chain1.chain.front()->getName() << delimeter;
        for (int i = 0; i < chain1.chain.size(); i++) {
            chain1.chain.front()->print(out);
            out << delimeter;
        }
        out << endl;
        return out;
    }
    
    vector<Card*> chain;
};

template <class T> Chain<T>::Chain() = default;

template <class T> Chain<T>::Chain(istream& istream, const CardFactory* factory) {
    std::string chainString;
    getline(istream, chainString);

    string delimiter = " ";
    // Deletes the bean name
    int pos = chainString.find(delimiter);
    chainString.erase(0, pos + delimiter.length());
    // Remove whitespaces
    chainString.erase(std::remove(chainString.begin(), chainString.end(), ' '), chainString.end());

    for (int i = 0; chainString[i] != '\0'; i++) {
        Card* card;
        char val = chainString[i];
        if (val == 'B')
        card = new Blue;
        else if (val == 'C')
            card = new Chili;
        else if (val == 'S')
            card = new Stink;
        else if (val == 'G')
            card = new Green;
        else if (val == 's')
            card = new Soy;
        else if (val == 'b')
            card = new Black;
        else if (val == 'R')
            card = new Red;
        else if (val == 'g')
            card = new Garden;
        else
            throw invalid_argument("cardType is invalid");

        chain.push_back(card);
    }
}

template <class T> Chain<T>& Chain<T>::operator+=(Card* card) {
    if (card->getName() == T::name){
        chain.push_back(card);
    } else{
        throw IllegalTypeException();
    }
    
    return *this;
}

template <class T> int Chain<T>::sell() {
    
    for (int coins = 4; coins > 0; i--)
	{
		if (chain.size() >= chain[0]->getCardsPerCoin(coins))
			return coins;
	}
	return 0;
}




#endif //CHAIN_H
