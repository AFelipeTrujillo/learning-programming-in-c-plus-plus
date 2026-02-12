#include <iostream>

int main () {

    int my_var = 100;
    int& reference_to_my_var = my_var;
    int* pointer_to_my_var = &my_var;

    std::cout << "Value of my_var: " << my_var << std::endl; 
    std::cout << "Value of reference_to_my_var: " << reference_to_my_var << std::endl; 
    std::cout << "Value of pointer_to_my_var: " << pointer_to_my_var << std::endl; 
    std::cout << "Dereferenced pointer_to_my_var: " << *pointer_to_my_var << std::endl;

    int vida = 100;
    int& reference_to_vida = vida;
    int* pointer_to_vida = &vida;

    *pointer_to_vida = 50;

    std::cout << "Value of vida: " << vida << std::endl; 
    std::cout << "Value of reference_to_vida: " << reference_to_vida << std::endl; 
    std::cout << "Value of pointer_to_vida: " << pointer_to_vida << std::endl; 
    std::cout << "Dereferenced pointer_to_vida: " << *pointer_to_vida << std::endl;

    return 0;
}