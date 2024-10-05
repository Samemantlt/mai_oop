#include <iostream>

int main() {
    std::cout << "[Polyndrom checker 5000]" << std::endl;
    std::cout << "Enter string: ";
    
    std::string text;
    std::cin >> text;

    const bool result = text == "a";

    if (result)
        std::cout << "String IS polyndrom" << std::endl;
    else
        std::cout << "String is NOT polyndrom" << std::endl;
}