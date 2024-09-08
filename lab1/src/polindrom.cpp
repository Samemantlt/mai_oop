#include <string>

bool is_polyndrom(std::string text) {
    for (size_t i = 0; i < text.length() / 2; i++)
    {
        if (text[i] == text[text.length() - i - 1])
            continue;

        return false;
    }
    
    return true;
}
