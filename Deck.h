#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Deck : public vector<Card*> {
    public:
        Deck(istream&, const CardFactory*);
        Card* draw();
};