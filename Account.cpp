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
    if (Account::needsUpdate) {
        int valC, valD;
        valC = Account::initialBalance.getCents();
        valD = Account::initialBalance.getDollars();
        
        if (Account::deposits.size() > 0) {
            for (int i=0; i < Account::deposits.size(); i++) {
                valC += Account::deposits[i].getCents();
                valD += Account::deposits[i].getDollars();
            }
        }

        if (Account::withdraws.size() > 0) {
            for (int i=0; i < Account::withdraws.size(); i++) {
                valC -= Account::withdraws[i].getCents();
                valD -= Account::withdraws[i].getDollars();
            }
        }

        Account::initialBalance.setCents(valC);
        Account::initialBalance.setDollars(valD);
    }

    stream<< "Account Details\n--------------------------\nCurrent Balance:" << Account::initialBalance
    << "\n--------------------------\nNumber of Deposits: " << Account::tD << "\n--------------------" << std::endl;
    for (int i=0; i < Account::deposits.size(); i++) {
        stream << "(" << i << ") " << Account::deposits[i] << std::endl;
    }

    stream << "--------------------------\nNumber of Withdrawals: " << Account::tW << "\n--------------------" << std::endl;
    for (int i=0; i < Account::withdraws.size(); i++) {
        stream << "(" << i << ") " << Account::withdraws[i] << std::endl;
    }

    return stream;
}