#include "four.h"

#include <cstring>
#include <regex>
#include <vector>

template <typename T>
T* reallocArray(T* old, const size_t oldSize, const size_t newSize) {
    T* newArray = new T[newSize];
    std::copy(old, &old[oldSize], newArray);
    return newArray;
}

Four::Four(const size_t size)
{
    this->size = size;
    this->array = new u_int8_t[size];
    std::fill(this->array, &this->array[size], 0);
}

Four::Four(std::string number)
{
    this->size = number.size();
    this->array = new u_int8_t[number.size()];

    static const std::regex digits_regex("^0|([1-3][0-3]*)$");
    if (!std::regex_match(number, digits_regex))
        throw std::exception();

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
    delete[] this->array;
    this->array = nullptr;
    this->size = 0;
}

std::strong_ordering operator<=>(const Four& lhs, const Four& rhs) {
    const auto thisSize = lhs.getValuableSize();
    const auto otherSize = rhs.getValuableSize();

    if (thisSize != otherSize)
        return thisSize <=> otherSize;

    for (size_t i = thisSize - 1; i > 0; i--) {
        const auto thisValue = lhs.get(i);
        const auto otherValue = rhs.get(i);

        if (thisValue != otherValue)
            return thisValue <=> otherValue;
    }

    return lhs.get(0) <=> rhs.get(0);
}

bool operator==(const Four& lhs, const Four& rhs) {
    return lhs <=> rhs == std::strong_ordering::equal;
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

void Four::ensureArrayCapacity(const size_t newSize) {
    if (newSize <= this->size)
        return;

    const size_t oldSize = this->size;
    const auto oldArray = this->array;

    this->array = reallocArray(this->array, this->size, newSize);
    delete [] oldArray;

    for (size_t i = oldSize; i < newSize; i++) {
        this->array[i] = u'0';
    }
    this->size = newSize;
}

u_int8_t Four::get(const size_t index) const {
    if (index >= this->size)
        return u'0';

    return this->array[index];
}

std::string Four::toString() const
{
    const auto vSize = this->getValuableSize();
    std::vector<char> reversed(vSize);
    for (size_t i = 0; i < vSize; i++)
    {
        reversed[i] = static_cast<char>(this->array[vSize - 1 - i]);
    }

    return {reversed.begin(), reversed.end()};
}

Four operator+(const Four& lhs, const Four& rhs)
{
    Four result(lhs);

    const size_t minSize = std::min(lhs.size, rhs.size);
    const auto maxSize = std::max(lhs.size, rhs.size);
    result.ensureArrayCapacity(maxSize);

    bool overflow = false;
    for (size_t i = 0; i < maxSize; i++)
    {
        result.array[i] += rhs.get(i) - u'0';
        if (overflow)
        {
            result.array[i] += 1;
            overflow = false;
        }
        if (result.array[i] >= u'4')
        {
            result.array[i] -= 4;
            overflow = true;
        }
    }
    if (overflow)
    {
        result.ensureArrayCapacity(maxSize + 1);
        result.array[maxSize]++;
    }

    return result;
}

Four operator-(const Four& lhs, const Four& rhs)
{
    if (lhs < rhs)
        throw std::exception();

    Four result(lhs);

    const size_t minSize = std::min(lhs.size, rhs.size);
    const auto maxSize = std::max(lhs.size, rhs.size);
    result.ensureArrayCapacity(maxSize);

    bool overflow = false;
    for (size_t i = 0; i < maxSize; i++)
    {
        result.array[i] -= rhs.get(i) - u'0';
        if (overflow)
        {
            result.array[i] -= 1;
            overflow = false;
        }
        if (result.array[i] < u'0')
        {
            result.array[i] += 4;
            overflow = true;
        }
    }
    if (overflow)
        throw "Unreachable exception";

    return result;
}

Four Four::operator+=(const Four &rhs)
{
    // TODO: check whether array leaks
    return *this = *this + rhs;
}

Four Four::operator-=(const Four &rhs)
{
    return *this = *this - rhs;
}
