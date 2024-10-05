#include <iostream>

#include "four.h"

int main() {
    std::cout << "[Four calculator]" << std::endl;

    std::string a_string, b_string;

    std::cout << "Enter four number A: ";
    std::cin >> a_string;
    Four a(a_string);

    std::cout << "Enter four number B: ";
    std::cin >> b_string;
    Four b(b_string);

    std::cout << "Sum: " << (a + b).toString() << std::endl;
    try {
        const auto subtract_result = (a - b).toString();
        std::cout << "Subtract: " << subtract_result << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << "Subtract error: " << e.what() << std::endl;
    }

    std::cout << "A < B: " << (a < b) << std::endl;
    std::cout << "A > B: " << (a > b) << std::endl;

    std::cout << "A <= B: " << (a <= b) << std::endl;
    std::cout << "A >= B: " << (a >= b) << std::endl;

    std::cout << "A == B: " << (a == b) << std::endl;
    std::cout << "A != B: " << (a != b) << std::endl;
}
