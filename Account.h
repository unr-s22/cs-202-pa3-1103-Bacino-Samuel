#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>
#include <vector>
#include "Money.h"

class Account{
    Money initialBalance;

    std::vector <Money> withdraws;
    std::vector <Money> deposits;

    int tD, tW;
    bool needsUpdate = false;
public:
    Account(Money);

    void makeDeposit(Money);
    void makeWithdrawals(Money);
    
    friend std::ostream& operator << (std::ostream &stream, const Account &acc);
};


#endif //ACCOUNT_H
