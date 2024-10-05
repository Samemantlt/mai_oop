#pragma once

#include <string>

class Four {
public:
    explicit Four(size_t size);

    explicit Four(std::string number);

    Four(const Four &source);
    Four(Four &&source) noexcept = default;

    virtual ~Four() noexcept;

    [[nodiscard]] std::string toString() const;

    friend std::strong_ordering operator<=>(const Four& lhs, const Four& rhs);
    friend bool operator==(const Four& lhs, const Four& rhs);

    Four operator+=(const Four& rhs);
    Four operator-=(const Four& rhs);

    friend Four operator+(const Four& lhs, const Four& rhs);
    friend Four operator-(const Four& lhs, const Four& rhs);

private:
    size_t size;
    u_int8_t *array;

    [[nodiscard]] size_t getValuableSize() const;

    void ensureArrayCapacity(size_t newSize);

    [[nodiscard]] u_int8_t get(size_t index) const;
};
