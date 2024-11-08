#pragma once

template<typename T>
class Array {
public:
    Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    void push_back(const T& value);
    void pop_back();
    void remove_at(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    bool empty() const;
    void clear();

    // Iterator support
    T* begin() { return data; }
    T* end() { return data + length; }
    const T* begin() const { return data; }
    const T* end() const { return data + length; }

private:
    T* data;
    size_t capacity;
    size_t length;

    void resize(size_t new_capacity);
};

// Include implementation explicitly because header file contains templates
#include "Array.ipp"
