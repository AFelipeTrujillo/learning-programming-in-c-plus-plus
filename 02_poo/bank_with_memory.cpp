#include "BankAccount.h"
#include <memory>
#include <iostream>

int main () {

    auto smartAccount = std::make_unique<BankAccount>(1000);
    smartAccount->getBalance();
    smartAccount->deposit(200);
    smartAccount->getBalance();

    return 0;
}