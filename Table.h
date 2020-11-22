#include <iostream>
#include "CardFactory.h"

using namespace std;

class Table {
    public:
        Table(istream&, const CardFactory*);
        bool win(string&);
        void printHand(bool);
};