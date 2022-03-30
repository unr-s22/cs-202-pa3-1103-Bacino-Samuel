#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>
#include <vector>
#include "Money.h"

class Account{

    std::vector <Money> withdraws;
    std::vector <Money> deposits;

    int tD = 0, tW = 0;
    bool needsUpdate = false;
public:
    Money initialBalance;
    Account(Money);


    void makeDeposit(Money);
    void makeWithdrawals(Money);
    
    friend std::ostream& operator << (std::ostream &stream, const Account &acc);
};


#endif //ACCOUNT_H
