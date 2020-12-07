#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CardFactory;

class Chain_Base {
    virtual void set_interface() = 0;
    char beanType;

public:
    char getType() { return beanType; }
};

template <class T> class Chain {
public:
    Chain(istream&, const CardFactory*);
    Chain();
    Chain<T>& operator+=(T*);
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
    //Card* getCardFromString(char cardType);
        //vector<Card*> chain;
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
        //Card* card = getCardFromString(chainString[i]);
        chain.push_back(card);
    }
}

template <class T> Chain<T>& Chain<T>::operator+=(T* card) {
    chain.push_back(card);
    return *this;
}

template <class T> int Chain<T>::sell() {
    if (chain.empty()){
        return 0;
    }
    int numOfCoins = chain.front()->getCoinsPerCard(chain.size());
    return numOfCoins;
}


// template <class T> Card* Chain<T>::getCardFromString(char cardType) {
//     Card* card;
//     if (cardType == 'B')
//         card = new Blue;
//     else if (cardType == 'C')
//         card = new Chili;
//     else if (cardType == 'S')
//         card = new Stink;
//     else if (cardType == 'G')
//         card = new Green;
//     else if (cardType == 's')
//         card = new Soy;
//     else if (cardType == 'b')
//         card = new Black;
//     else if (cardType == 'R')
//         card = new Red;
//     else if (cardType == 'g')
//         card = new Garden;
//     else
//         throw invalid_argument("cardType is invalid");

//     return card;
// }


#endif //CHAIN_H
