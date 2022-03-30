#include <iostream>
#include "Money.h"
#include "Account.h"
#include <vector>

int main() {
    Money z(200, 0);  //+
    Money y(300, 23); //+
    Money x(501, 22); //+
    Money w(300, 10); //-
    Money v(201, 34); //-
    Money o(100, 1);  // >>
    Money k(99, 99);  // <<

    Money b(300, 23); //initial
    Account a(b); //account creation
    std::cout << b << std::endl;

    //deposits
    a.makeDeposit(z);
    a.makeDeposit(y);
    a.makeDeposit(x);
    std::cout << a << std::endl;

    //withdrawals
    a.makeWithdrawals(w);
    a.makeWithdrawals(v);
    std::cout << a << std::endl;

    //operators
    if (o > k) {
        std::cout << "100.1 > 99.99: " << a.initialBalance << std::endl;
    }
    if (k < o) {
        std::cout << "99.99 < 100.1: " << a.initialBalance << std::endl;
    }
    if (k <= o) {
        std::cout << "99.99 <= 100.1: " << a.initialBalance << std::endl;
    }
    if (o >= k) {
        std::cout << "100.1 >= 99.99: " << a.initialBalance << std::endl;
    }
    if (o == o) {
        std::cout << "100.1 == 100.1: " << a.initialBalance << std::endl;
    }
    if (k != o) {
        std::cout << "99.99 != 100.1: " << a.initialBalance << std::endl;
    }
    
    return 0;
}