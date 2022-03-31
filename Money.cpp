#include "Money.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

Money::Money(){}

Money::Money(int d, int c){
    dollars = d;
    cents = c;
}

int Money::getDollars(){
    return dollars;
}

int Money::getCents(){
    return cents;
}

// <
bool operator < (const Money &lhs, const Money& rhs) {
    if (lhs.dollars < rhs.dollars){
        return true;
    } else if (lhs.dollars == rhs.dollars) {
        if(lhs.cents < rhs.cents){
            return true;
        }
    }
    return false;
}

// >
bool operator > (const Money &lhs, const Money& rhs) {
    if (lhs.dollars > rhs.dollars){
        return true;
    } else if (lhs.dollars == rhs.dollars) {
        if(lhs.cents > rhs.cents){
            return true;
        }
    }
    return false;
}

// <=
bool operator<=(const Money &lhs, const Money& rhs) {
    if (lhs.dollars <= rhs.dollars){
        return true;
    } else if (lhs.dollars == rhs.dollars) {
        if(lhs.cents <= rhs.cents){
            return true;
        }
    }
    return false;
}

// >=
bool operator>=(const Money &lhs, const Money& rhs) {
    if (lhs.dollars >= rhs.dollars){
        return true;
    } else if (lhs.dollars == rhs.dollars) {
        if(lhs.cents >= rhs.cents){
            return true;
        }
    }
    return false;
}

// !=
bool operator!=(const Money &lhs, const Money& rhs) {
    if (lhs.dollars != rhs.dollars){
        return true;
    } else if (lhs.dollars == rhs.dollars) {
        if(lhs.cents != rhs.cents){
            return true;
        }
    }
    return false;
}

// ==
bool operator==(const Money &lhs, const Money& rhs) {
    if (lhs.dollars == rhs.dollars){
        return true;
    } else if (lhs.dollars == rhs.dollars) {
        if(lhs.cents == rhs.cents){
            return true;
        }
    }
    return false;
}


// +
Money operator + (const Money &left, const Money &right){
    Money c(0,0);
    c.dollars = (left.dollars + right.dollars);
    c.cents = (left.cents + right.cents);

    if(c.cents >= 100){
        c.cents = (c.cents - 100);
        c.dollars = (c.dollars + 1); 
    }
    return c;
}

// -
Money operator - (const Money &left, const Money &right){
    Money c(0,0);
    c.dollars = (left.dollars - right.dollars);
    c.cents = (left.cents + right.cents);

    if(c.cents < 0 ){
        c.cents = (c.cents + 100);
        c.dollars = (c.dollars - 1);
    }
    return c;
}

// out
ostream& operator<<(ostream &out, const Money &m){
    out << "$" << m.dollars << "." << m.cents << endl;
    return out;
}
