#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
    private:
        double balance;
    
    public:
        BankAccount(double initial_balance);
        void deposit(double amount); 
        void withdraw(double amount); 
        void getBalance() const; 
        ~BankAccount();
};

#endif