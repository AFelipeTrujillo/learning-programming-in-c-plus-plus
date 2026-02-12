#include "BankAccount.h"
#include <iostream>

int main(){
    std::cout << "Creating a bank account with an initial balance of 100." << std::endl;
    BankAccount myAccount(100); 
    myAccount.getBalance(); 
    myAccount.deposit(80); 
    myAccount.getBalance(); 
    myAccount.withdraw(20); 
    myAccount.getBalance(); 

    try {
        // this will throw an exception because 
        // the withdrawal amount exceeds the current balance
        myAccount.withdraw(500);
    } catch (const std::runtime_error& e) { 
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) { 
        std::cerr << "Invalid argument: " << e.what() << std::endl; 
    } catch (const std::exception& e) { 
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl; 
    }

    myAccount.getBalance();

    try {
        myAccount.deposit(-50);
    } catch(int e) {
        std::cerr << "Error code: " << e << " - Deposit amount must be positive." << std::endl;
    } catch (const std::invalid_argument& e) { 
        std::cerr << "Invalid argument: " << e.what() << std::endl; 
    } catch (const std::exception& e) { 
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl; 
    }

    try {
        BankAccount my_new_account(200);
        my_new_account.getBalance();
        my_new_account.withdraw(300);
    } catch(int e) {
        std::cerr << "Error code: " << e << " - Deposit amount must be positive." << std::endl;
    } catch (const std::invalid_argument& e) { 
        std::cerr << "Invalid argument: " << e.what() << std::endl; 
    } catch (const std::exception& e) { 
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl; 
    }

    std::cout << "END OF MAIN FUNCTION" << std::endl;
    return 0;
}