#include <string>
#include <iostream>

int main()  {

    std::string name = "Johanna";
    std::string greeting = "Hello, " + name + "!"; 

    std::cout << "The size of int is: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "The size of double is: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "The size of char is: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "The size of greeting is: " << sizeof(greeting) << " bytes" << std::endl;
    std::cout << "The size of name is: " << sizeof(name) << " bytes" << std::endl;
    std::cout << "The length of name is: " << name.length() << " characters" << std::endl;
    
    std::cout << greeting << std::endl;

    double my_var = 9.99;
    int my_var_two = my_var;
    int my_var_three = static_cast<int>(my_var);
    std::cout << "my_var: " << my_var << std::endl; std::cout << "my_var_two: " << my_var_two << std::endl;
    std::cout << "my_var_three: " << my_var_three << std::endl;

    std::string student_name;
    std::string age_in_string;
    
    std::cout << "Please enter your name:" << std::endl;
    std::getline(std::cin, student_name);
    
    std::cout << "Now, enter you age" << std::endl;
    std::cin >> age_in_string;

    int age = stoi(age_in_string);

    std::cout << "The name is: " << student_name << " and the age is: " << age << std::endl;
    std::cout << std::endl;

    return 0;
}