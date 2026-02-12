#include <vector>
#include <iostream>

void multiply_by_two(std::vector<int>& vec) {
    // size_t is an unsigned integer type that is used to represent the size of objects in bytes.
    // It is commonly used for array indexing and loop counters.
    for (size_t i = 0; i < vec.size(); ++i) { 
        vec[i] *= 2; 
    }
}

void show_vector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) { 
        std::cout << vec[i] << " "; 
    } 
    std::cout << std::endl;
}

void show_vector_with_for_loop(const std::vector<int>& vec) { 
    
    for (const int &element : vec) { 
        std::cout << element << " "; 
    } 
    std::cout << std::endl;
}

int main() {
    std::vector <int> inventory = {10, 20, 30, 40, 50};
    std::cout << "Original inventory: "; show_vector(inventory); multiply_by_two(inventory); std::cout << "Updated inventory: "; show_vector(inventory);
    multiply_by_two(inventory);
    std::cout << "For Loop: "; show_vector_with_for_loop(inventory); 
    std::cout << std::endl;
    return 0;
}