#include <iostream>

class BankAccount {
    private:
        double balance;
    
    public:
        
        
        //BankAccount(double initial_balance) {
        //    this->balance = initial_balance;
        //}
        

        // The constructor can also be defined using an initializer list, 
        // which is a more efficient way to initialize member variables.
        BankAccount(double initial_balance) : balance(initial_balance) {

        }

        void deposit(double amount) {
            if (amount > 0 ) {
                this->balance += amount;
            }
        }

        void withdraw(double amount) {
            if(amount >0 && amount <= this->balance) {
                this->balance -= amount;
            }
        }

        // const member function: 
        // a member function that does not modify the state of the object.
        void getBalance() const { 
            std::cout << "Current balance: " << this->balance << std::endl; 
        }

        ~BankAccount() { 
            std::cout << "Bank account is being destroyed." << std::endl; 
        }
};

int main () {
    BankAccount myAccount(100);
    myAccount.getBalance();
    myAccount.deposit(50); 
    myAccount.getBalance();
    myAccount.withdraw(30); 
    myAccount.getBalance();
    std::cout << "END OF MAIN FUNCTION" << std::endl;
    return 0;
}