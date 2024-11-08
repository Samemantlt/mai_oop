#include "four.h"

#include <algorithm>
#include <cstring>
#include <regex>
#include <vector>

template<typename T>
T *realloc_array(T *old, const size_t oldSize, const size_t newSize) {
    T *new_array = new T[newSize];
    std::copy(old, &old[oldSize], new_array);
    return new_array;
}

Four::Four() {
    size = 1;
    array = new u_int8_t[size];
    array[0] = '0';
}

Four::Four(const size_t &n, const u_int8_t t) {
    if (t < '0' || t > '9')
        throw std::runtime_error("t is invalid");

    size = n;
    array = new u_int8_t[size];
    std::fill(array, &array[size], t);
}

Four::Four(const std::initializer_list<u_int8_t> &t) {
    for (const auto i : t) {
        if (i < '0' || i > '9')
            throw std::runtime_error("Passed list contains invalid characters");
    }

    size = t.size();
    array = new u_int8_t[size];
    std::ranges::reverse_copy(t, array);
}

Four::Four(const std::string& number) {
    size = number.size();
    array = new u_int8_t[number.size()];

    static const std::regex digits_regex("^0|([1-3][0-3]*)$");
    if (!std::regex_match(number, digits_regex))
        throw std::runtime_error("Passed std::string has invalid four number format");

    std::copy(number.rbegin(), number.rend()--, array);
}

Four::Four(const Four &other) {
    size = other.size;
    array = new u_int8_t[size];
    std::copy(other.array, &other.array[size], array);
}

Four::Four(Four&& other) noexcept : size(other.size), array(other.array) {
    other.size = 0;
    other.array = nullptr;
}

Four::~Four() noexcept {
    delete[] array;
    array = nullptr;
    size = 0;
}

std::string Four::to_string() const {
    const auto v_size = get_valuable_size();

    std::vector<char> reversed(v_size);
    for (size_t i = 0; i < v_size; i++) {
        reversed[i] = static_cast<char>(array[v_size - 1 - i]);
    }

    return {reversed.begin(), reversed.end()};
}

std::strong_ordering operator<=>(const Four &lhs, const Four &rhs) {
    const auto this_size = lhs.get_valuable_size();
    const auto other_size = rhs.get_valuable_size();

    if (this_size != other_size)
        return this_size <=> other_size;

    for (size_t i = this_size - 1; i > 0; i--) {
        const auto thisValue = lhs.get(i);
        const auto otherValue = rhs.get(i);

        if (thisValue != otherValue)
            return thisValue <=> otherValue;
    }

    return lhs.get(0) <=> rhs.get(0);
}

bool operator==(const Four &lhs, const Four &rhs) {
    return lhs <=> rhs == std::strong_ordering::equal;
}

Four Four::operator+=(const Four &rhs) {
    const auto max_size = std::max(size, rhs.size);
    ensure_array_capacity(max_size);

    bool overflow = false;
    for (size_t i = 0; i < max_size; i++) {
        array[i] += rhs.get(i) - u'0';
        if (overflow) {
            array[i] += 1;
            overflow = false;
        }
        if (array[i] >= u'4') {
            array[i] -= 4;
            overflow = true;
        }
    }
    if (overflow) {
        ensure_array_capacity(max_size + 1);
        array[max_size]++;
    }

    return *this;
}

Four Four::operator-=(const Four &rhs) {
    if (*this < rhs)
        throw std::runtime_error("Cannot subtract right value bigger than left value");

    const auto max_size = std::max(size, rhs.size);
    ensure_array_capacity(max_size);

    bool overflow = false;
    for (size_t i = 0; i < max_size; i++) {
        array[i] -= rhs.get(i) - u'0';
        if (overflow) {
            array[i] -= 1;
            overflow = false;
        }
        if (array[i] < u'0') {
            array[i] += 4;
            overflow = true;
        }
    }

    return *this;
}

Four operator+(const Four &lhs, const Four &rhs) {
    Four result = lhs;
    result += rhs;
    return result;
}

Four operator-(const Four &lhs, const Four &rhs) {
    Four result = lhs;
    result -= rhs;
    return result;
}

size_t Four::get_valuable_size() const {
    if (size == 0)
        return 0;

    for (size_t i = size; i > 0; i--) {
        if (array[i - 1] != '0')
            return i;
    }
    return 1;
}

void Four::ensure_array_capacity(const size_t newSize) {
    if (newSize <= size)
        return;

    const size_t oldSize = size;
    const auto oldArray = array;

    array = realloc_array(array, size, newSize);
    delete [] oldArray;

    for (size_t i = oldSize; i < newSize; i++) {
        array[i] = u'0';
    }
    size = newSize;
}

u_int8_t Four::get(const size_t index) const {
    if (index >= size)
        return u'0';

    return array[index];
}
