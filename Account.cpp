#include <iostream>
#include <vector>
#include "Account.h"

Account::Account(Money c){
    Account::initialBalance = c;
}

void Account::makeDeposit (Money c) {
    needsUpdate = true;
    tD++;
    deposits.push_back(c);
}

void Account::makeWithdrawals (Money c) {
    needsUpdate = true;
    tW++;
    withdraws.push_back(c);
}

std::ostream& operator<<(std::ostream &stream, const Account &acc){
    Money z(0,0);
    if (acc.needsUpdate) {
        int d, c;
        for (Money a : acc.deposits) {
            z = z+a;
        }
        for (Money w : acc.withdraws) {
            z = z-w;
        }
    }

    stream << "Account Details\n--------------------------\nCurrent Balance: " 
    << acc.initialBalance+z << "--------------------------\nNumber of Deposits: " 
    << acc.tD << "\n--------------------------" << std::endl;

    for (int i=0; i < acc.deposits.size(); i++) {
        stream << "(" << i+1 << ") " << acc.deposits[i] << std::endl;
    }

    stream << "--------------------------\nNumber of Withdrawals: " 
    << acc.tW << "\n--------------------------" << std::endl;

    for (int i=0; i < acc.withdraws.size(); i++) {
        stream << "(" << i+1 << ") " << acc.withdraws[i] << std::endl;
    }

    return stream;
}