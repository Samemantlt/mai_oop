#include <iostream>
#include "polindrom.h"


int main() {
    std::cout << "[Polyndrom checker 4000]" << std::endl;
    std::cout << "Enter string: ";
    
    std::string text;
    std::cin >> text;

    bool result = is_polyndrom(text);

    if (result)
        std::cout << "String IS polyndrom" << std::endl;
    else
        std::cout << "String is NOT polyndrom" << std::endl;
}