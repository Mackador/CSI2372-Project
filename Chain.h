#include <iostream>
#include <vector>
#include "CardFactory.h"

using namespace std;

template <class T>
class Chain {
    vector<Card*> cards;
    public:
        Chain(istream&, const CardFactory*);
        Chain<T>& operator+=(Card*);
        int sell();
};