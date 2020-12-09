#ifndef FINALPROJECT_CHAIN_H
#define FINALPROJECT_CHAIN_H

#include <iostream>
#include <vector>
#include "CardFactory.h"
#include "Exceptions.h"

class Chain_Base {
public:
    virtual int sell() const = 0;
    virtual Chain_Base& operator+=(Card*) = 0;
    virtual void print(ostream&) const = 0;
    friend ostream& operator<<(ostream&, const Chain_Base&);
};

template <class T>
class Chain : public Chain_Base, public vector<T*> {
public:
    Chain() = default;
    Chain<T>(istream&, const CardFactory*);
    int sell() const override;
    Chain<T>& operator+=(Card*) override;
    void print(ostream&) const override;
};

template <class T>
Chain<T>::Chain(istream &file, const CardFactory *cardFactory) {
    string line;
    file >> line;
    for (char c : line) {
        Card* card = cardFactory->stringToCard(c);
        (*this).push_back((T*)card);
    }
}

template <class T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    if (card->getName() == T::name) {
        T* temp = new T();
        (*this).push_back(temp);
    } else {
        throw IllegalTypeException();
    }
    return *this;
}

template <class T>
int Chain<T>::sell() const {
    for (int i = 4; i > 0; i--)
    {
        if ((*this).size() >= (*this)[0]->getCardsPerCoin(i))
            return i;
    }
    return 0;
}

template <class T>
ostream& operator<<(ostream &out, const Chain<T> &chain) {
    for (T e : chain.cards) {
        cout << e;
    }
    return out;
}

template <class T>
void Chain<T>::print(ostream &out) const {
    out << T::name;
    out << " ";
    for (T* t : (*this)) {
        out << *t;
    }
}

#endif //FINALPROJECT_CHAIN_H
