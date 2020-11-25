#include <iostream>
#include <vector>

using namespace std;

class DiscardPile {
    vector<Card*> cards;
    public:
        DiscardPile(istream&, const CardFactory*);
        DiscardPile& operator+=(Card*);
        Card* pickUp();
        Card* top();
        void print(ostream&);
};