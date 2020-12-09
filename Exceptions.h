//
// Created by Mackador on 12/8/2020.
//

#ifndef FINALPROJECT_EXCEPTIONS_H
#define FINALPROJECT_EXCEPTIONS_H

#include <string>
#include <sstream>

class IllegalTypeException
{
public:
    IllegalTypeException() {}
    virtual const char* what() const throw()
    {
        return "Illegal Type Exception: Wrong type";
    }
};

class NotEnoughCoinsException
{
public:
    NotEnoughCoinsException() {}
    virtual const char* what() const throw()
    {
        return ("Not Enough Coins Exception: You do not have enough coins.");
    }
};


#endif //FINALPROJECT_EXCEPTIONS_H
