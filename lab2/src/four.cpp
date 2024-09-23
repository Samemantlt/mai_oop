#include "four.h"

#include <cstring>

Four::Four(size_t size)
{
    this->size = size;
    this->array = new u_int8_t[size];
    std::fill(this->array, &this->array[size], 0);
}

Four::Four(std::string number)
{
    this->size = number.size();
    this->array = new u_int8_t[number.size()];

    std::copy(number.rbegin(), number.rend()--, this->array);
}

Four::Four(const Four &source)
{
    this->size = source.size;
    this->array = new u_int8_t[size];
    std::copy(source.array, &source.array[size], this->array);
}

Four::~Four() noexcept
{
    if (this->array != nullptr)
        delete[] this->array;
}

size_t Four::getValuableSize() const
{
    for (size_t i = this->size; i > 0; i--)
    {
        if (this->array[i - 1] != '0')
            return i;
    }
    return 1;
}

std::string Four::toString()
{
    auto vSize = this->getValuableSize();
    char* reversed = new char[vSize];
    for (size_t i = 0; i < vSize; i++)
    {
        reversed[i] = this->array[vSize - 1 - i];
    }

    return std::string(reversed, getValuableSize());
}

bool Four::operator==(const Four &other) const
{
    return getValuableSize() == other.getValuableSize() && std::memcmp(array, other.array, getValuableSize()) == 0;
}

Four operator+(const Four& lhs, const Four& rhs)
{
    Four result(lhs);

    size_t minSize = std::min(lhs.size, rhs.size);

    bool overflow = false;
    for (size_t i = 0; i < minSize; i++)
    {
        result.array[i] += rhs.array[i] - u'0';
        if (overflow)
        {
            result.array[i] += 1;
            overflow = false;
        }
        if (result.array[i] >= '4')
        {
            result.array[i] -= 4;
            overflow = true;
        }
    }
    if (overflow)
    {
        result.array[minSize]++;
    }

    return result;
}

Four operator-(const Four& lhs, const Four& rhs)
{
    Four result(lhs);

    size_t minSize = std::min(lhs.size, rhs.size);

    bool overflow = false;
    for (size_t i = 0; i < minSize; i++)
    {
        result.array[i] -= rhs.array[i] - u'0';
        if (overflow)
        {
            result.array[i] -= 1;
            overflow = false;
        }
        if (result.array[i] < '0')
        {
            result.array[i] += 4;
            overflow = true;
        }
    }
    if (overflow)
    {
        result.array[minSize]--;
    }

    return result;
}

Four Four::operator+=(const Four &rhs)
{
    return *this = *this + rhs;
}

Four Four::operator-=(const Four &rhs)
{
    return *this = *this - rhs;
}
