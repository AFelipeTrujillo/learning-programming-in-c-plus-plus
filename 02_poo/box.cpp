#include <iostream>

template <typename T> class Box {
    private:
        T content;
    
    public:
        void setContent(T c) {
            this->content = c;
        }

        void getContent() const {
            std::cout << "Content is: " << this->content << std::endl;
        }
};

int main() {

    Box<int> my_int_box;
    my_int_box.setContent(12);
    my_int_box.getContent();

    Box<std::string> my_string_box;
    my_string_box.setContent("Andy");
    my_string_box.getContent();

    Box<double> my_double_box;
    my_double_box.setContent(12.45);
    my_double_box.getContent();
    
    return 0;
}