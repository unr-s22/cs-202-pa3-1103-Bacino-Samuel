#include <iostream>
#include <vector>
#include "Account.h"

Account::Account(Money cash) {
    initialBalance = cash;
}

void Account::makeDeposit (Money) {
    Account::needsUpdate = true;
    Account::tD++;
    Account::deposits.push_back(initialBalance);
}

void Account::makeWithdrawals (Money) {
    Account::needsUpdate = true;
    Account::tW++;
    Account::withdraws.push_back(initialBalance);
}

std::ostream& operator<<(std::ostream &stream, const Account &acc){
    stream<< "Account Details\n--------------------------\nCurrent Balance:" << acc.initialBalance
    << "\n--------------------------\nNumber of Deposits: " << acc.tD << "\n--------------------" << std::endl;
    for (int i=0; i < acc.deposits.size(); i++) {
        stream << "(" << i << ") " << acc.deposits[i] << std::endl;
    }

    stream << "--------------------------\nNumber of Withdrawals: " << acc.tW << "\n--------------------" << std::endl;
    for (int i=0; i < acc.withdraws.size(); i++) {
        stream << "(" << i << ") " << acc.withdraws[i] << std::endl;
    }

    return stream;
}