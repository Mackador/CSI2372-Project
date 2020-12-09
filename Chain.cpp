#include "Chain.h"

template <class T>
Chain<T>::Chain(istream &file, const CardFactory *cardFactory) {
    string line;
    file >> line;
    for (char c : line) {
        cards.push_back(cardFactory->stringToCard(c));
    }
}

template <class T>
Chain_Base& Chain<T>::operator+=(Card* card) {
    if (card->getName() == T::name) {
        cards.push_back(card);
    } else {
        throw IllegalTypeException();
    }
    return *this;
}

template <class T>
int Chain<T>::sell() const {
    for (int i = 4; i > 0; i--)
    {
        if (cards.size() >= cards[0]->getCardsPerCoin(i))
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