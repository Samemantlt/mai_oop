#pragma once

#include <stdint.h>
#include <string>

class Four
{
public:
    Four(size_t size);

    Four(std::string number);

    Four(const Four &source);

    std::string toString();

    virtual ~Four() noexcept;
    
    bool operator==(const Four &other) const;
    
    friend Four operator+(const Four& lhs, const Four& rhs);
    friend Four operator-(const Four& lhs, const Four& rhs);

    Four operator+=(const Four& rhs);
    Four operator-=(const Four& rhs);

private:
    size_t size;
    u_int8_t *array;

    size_t getValuableSize() const;
};
