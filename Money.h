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

        friend bool operator<(const Money&, const Money&);
        friend bool operator>(const Money&, const Money&);
        friend bool operator<=(const Money&, const Money&);
        friend bool operator>=(const Money&, const Money&); 
        friend bool operator!=(const Money&, const Money&);
        friend bool operator==(const Money&, const Money&);

        friend Money operator + (const Money&, const Money&);
        friend Money operator - (const Money&, const Money&);

        friend ostream& operator<<(ostream &out, const Money &m);
};

#endif