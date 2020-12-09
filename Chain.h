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
class Chain : public Chain_Base {
    vector<T*> cards;
public:
    Chain() = default;
    Chain<T>(istream&, const CardFactory*);
    int sell() const override;
    Chain_Base& operator+=(Card*) override;
    void print(ostream&) const override;
};

#endif //FINALPROJECT_CHAIN_H
