#include "Card.h"

int Blue::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
    }
}

string Blue::getName() {
    return "Blue";
}

void Blue::print(ostream &out) {
    out << "B";
}

int Chili::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 8;
        case 4: return 9;
    }
}

string Chili::getName() {
    return "Chili";
}

void Chili::print(ostream &out) {
    out << "C";
}

int Stink::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 7;
        case 4: return 8;
    }
}

string Stink::getName() {
    return "Stink";
}

void Stink::print(ostream &out) {
    out << "S";
}

int Green::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 6;
        case 4: return 7;
    }
}

string Green::getName() {
    return "Green";
}

void Green::print(ostream &out) {
    out << "G";
}

int Soy::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 7;
    }
}

string Soy::getName() {
    return "Soy";
}

void Soy::print(ostream &out) {
    out << "s";
}

int Black::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
    }
}

string Black::getName() {
    return "Black";
}

void Black::print(ostream &out) {
    out << "b";
}

int Red::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 4: return 5;
    }
}

string Red::getName() {
    return "Red";
}

void Red::print(ostream &out) {
    out << "R";
}

int Garden::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 0;
        case 2: return 2;
        case 3: return 3;
        case 4: return 0;
    }
}

string Garden::getName() {
    return "Garden";
}

void Garden::print(ostream &out) {
    out << "g";
}