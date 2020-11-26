#include "Chain.h"

template <class T>
Chain<T>::Chain(istream&, const CardFactory*) {

}

template <typename T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

template <typename T>
int Chain<T>::sell() {

}