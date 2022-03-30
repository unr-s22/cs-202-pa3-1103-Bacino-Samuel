#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;

class Money {
    private:
        int cents ;
        int dollars ;
    public:
        Money(int,int);
        Money();

        int getDollars();
        int getCents();

        bool operator<(const Money& rhs) const;
        bool operator>(const Money& rhs) const;
        bool operator<=(const Money& rhs) const;
        bool operator>=(const Money& rhs) const; 
        bool operator!=(const Money& rhs) const;
        bool operator==(const Money& rhs) const;

        Money operator+(const Money &m1) const; 
        Money operator-(const Money &m1) const;

        friend ostream& operator<<(ostream &out, const Money &m);
};

#endif