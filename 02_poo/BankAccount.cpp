#include "BankAccount.h"
#include <iostream>
#include <stdexcept>

BankAccount::BankAccount(double initial_balance) : balance(initial_balance) {}

void BankAccount::deposit(double amount) {
    
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive.");
        // throw 404;
    } 

    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }

    if (amount > balance) {
        throw std::runtime_error("Insufficient funds for withdrawal.");
    }

    balance -= amount;
}

void BankAccount::getBalance() const {
    std::cout << "Balance actual: " << balance << std::endl;
}

BankAccount::~BankAccount() {
    std::cout << "Destruyendo cuenta..." << std::endl;
}