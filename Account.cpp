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
    if (acc.needsUpdate) {
        if (acc.tD > 0) {
            for (int i=0; i < acc.tD; i++) {
                acc.newBal == acc.initialBalance + acc.deposits[i];
                std::cout << "{{{" << acc.newBal;
            }
        }
        if (acc.tW > 0) {
            for (int i=0; i < acc.tW; i++) {
                acc.newBal == acc.initialBalance - acc.withdraws[i];
                std::cout << "{{{" << acc.newBal;
            }
        }
    }

    stream << "Account Details\n--------------------------\nCurrent Balance:" 
    << acc.initialBalance << "--------------------------\nNumber of Deposits: " 
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