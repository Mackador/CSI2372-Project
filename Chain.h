#ifndef CHAIN_H
#define CHAIN_H
#include <vector>
#include <iostream>
#include <string>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class Chain_Base {
    virtual void set_interface() = 0;
    
public:
    
};

template <class T> class Chain {
public:
    Chain();
    Chain(istream&, const CardFactory*);
    Chain<T>& operator+=(Card*);
    int sell();
    vector<Card*> elems;
    friend ostream& operator<<(ostream& output, const Chain& printChain) {
        
        if(printChain.elems.empty()){
            output << endl;
            return output;
        }
        char spaces = ' ';
        output << printChain.elems[0]->getName() << spaces;
        for (int i = 0; i < printChain.elems.size(); i++) {
            printChain.elems[0]()->print(output);
            output << spaces;
        }
        output << endl;
        return output;
    }
    
    
};

template <class T> Chain<T>::Chain() = default;

template <class T> Chain<T>::Chain(istream& istream, const CardFactory* cFactory) {
    std::string chLine;
    getline(istream, chLine);
    string spaces = " ";
    int firstSpace = chLine.find(spaces);
    chLine.erase(0, firstSpace + spaces.length());
    chLine.erase(std::remove(chLine.begin(), chLine.end(), ' '), chaLine.end());
    for (int i = 0; chLine[i] != '\0'; i++) {
        Card* card;
        char val = chLine[i];
        if (val == 'B'){
            card = new Blue;
        } 
        else if (val == 'G'){
            card = new Green;
        }
        else if (val == 'C'){
            card = new Chili;
        }  
        else if (val == 'g'){
            card = new Garden;
        }
        else if (val == 's'){
            card = new Soy;
        }
        else if (val == 'S'){
            card = new Stink;
        }   
        else if (val == 'b'){
            card = new Black;
        }
        else if (val == 'R'){
            card = new Red;
        }
        else{
            throw invalid_argument("cardType is invalid");
        }
        elems.push_back(card);
    }
}

template <class T> Chain<T>& Chain<T>::operator+=(Card* card) {
    if (card->getName() == T::name){
        elems.push_back(card);
    } else{
        throw IllegalTypeException();
    }
    
    return *this;
}

template <class T> int Chain<T>::sell() {
    
    for (int coins = 4; coins > 0; i--)
	{
		if (elems.size() >= elems[0]->getCardsPerCoin(coins))
			return coins;
	}
	return 0;
}




#endif //CHAIN_H
