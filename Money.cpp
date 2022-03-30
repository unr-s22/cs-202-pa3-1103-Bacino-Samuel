#include "Money.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

Money::Money(){}

Money::Money(int d, int c){
    dollars = d ;
    cents = c ;
}

int Money::getDollars(){
    return dollars ;
}

int Money::getCents(){
    return cents;
}

bool Money::operator<(const Money& rhs) const {
    return dollars < rhs.dollars ;
}
bool Money::operator>(const Money& rhs) const{
    return dollars > rhs.dollars ;
}
bool Money::operator<=(const Money& rhs) const{
    return dollars <= rhs.dollars && cents == rhs.cents ;
}
bool Money::operator>=(const Money& rhs) const{
    return dollars >= rhs.dollars && cents == rhs.cents ;
}
bool Money::operator!=(const Money& rhs) const{
    return dollars != rhs.dollars && cents != rhs.cents ;
}
bool Money::operator==(const Money& rhs) const{
    return dollars == rhs.dollars && cents == rhs.cents ;
}

Money Money::operator+(const Money &m1) const {
    int totalDollars = 0 ;
    int totalCents = 0 ;

    totalDollars = m1.dollars + dollars ;
    totalCents = m1.cents + cents ;
    if(totalCents >= 100){
        totalDollars = totalDollars + 1;
        totalCents = totalCents - 100 ;
    }

    Money newMoney = Money(totalDollars,totalCents);
    return newMoney ;
}
Money Money::operator-(const Money &m1) const{
    int totalDollars = 0 ;
    int totalCents = 0 ;

    totalDollars = m1.dollars - dollars ;
    totalCents = m1.cents - cents ;
    if(totalCents <= 0){
        totalDollars = totalDollars - 1;
        totalCents = totalCents + 100 ;
    }

    Money newMoney = Money(totalDollars,totalCents);
    return newMoney ;
}

ostream& operator<<(ostream &out, const Money &m){
    out << "$" << m.dollars << "." << m.cents << endl ;
    return out ;
}
