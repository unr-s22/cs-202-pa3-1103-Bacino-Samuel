#include <iostream>
#include <vector>
#include "Account.h"

Account::Account(Money cash) {
    initialBalance = cash;
}

void Account::makeDeposit (Money) {
    needsUpdate = true;
    tD++;
    deposits.push_back(initialBalance);
}

void Account::makeWithdrawals (Money) {
    needsUpdate = true;
    tW++;
    withdraws.push_back(initialBalance);
}

std::ostream& operator<<(std::ostream &stream, const Account &acc){
    stream<< "Account Details\n--------------------------\nCurrent Balance:" << acc.initialBalance
    << "--------------------------\nNumber of Deposits: " << acc.tD << "\n--------------------------" << std::endl;
    for (int i=0; i < acc.deposits.size(); i++) {
        stream << "(" << i << ") " << acc.deposits[i] << std::endl;
    }

    stream << "--------------------------\nNumber of Withdrawals: " << acc.tW << "\n--------------------------" << std::endl;
    for (int i=0; i < acc.withdraws.size(); i++) {
        stream << "(" << i << ") " << acc.withdraws[i] << std::endl;
    }

    return stream;
}