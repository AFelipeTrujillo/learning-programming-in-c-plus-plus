#include <iostream>

int main() {
    
    std::cout << "\033[31mThis is red text\033[0m" << std::endl;
    std::cout << "\033[32mThis is green text\033[0m" << std::endl;
    std::cout << "\033[1;34mBold Blue Text\033[0m" << std::endl;
    std::cout << "\033[4;33mUnderlined Yellow Text\033[0m" << std::endl;
    std::cout << "\033[5mThis text blinks\033[0m" << std::endl;
    
    return 0;
}