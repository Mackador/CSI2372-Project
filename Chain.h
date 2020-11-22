#include <iostream>
#include "CardFactory.h"

using namespace std;

class Chain {
    Chain(istream&, const CardFactory*);
    Chain<T>& operator+=(Card*);
    int sell();
};