#pragma once

#include "Array.h"

#include <iostream>
#include <stdexcept>

template<typename T>
Array<T>::Array() : data(nullptr), capacity(0), length(0) {}

template<typename T>
Array<T>::Array(const Array& other) : data(nullptr), capacity(0), length(0) {
    if (other.length > 0) {
        data = new T[other.capacity];
        for (size_t i = 0; i < other.length; ++i) {
            data[i] = other.data[i];
        }
    }
    capacity = other.capacity;
    length = other.length;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        capacity = 0;
        length = 0;

        if (other.length > 0) {
            data = new T[other.capacity];
            for (size_t i = 0; i < other.length; ++i) {
                data[i] = other.data[i];
            }
        }
        capacity = other.capacity;
        length = other.length;
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    if (data != nullptr)
        delete[] data;
}

template<typename T>
void Array<T>::push_back(const T& value) {
    if (length >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[length++] = std::move(value);
}

template<typename T>
void Array<T>::pop_back() {
    if (length > 0) {
        --length;
    } else {
        throw std::out_of_range("Array is empty");
    }
}

template<typename T>
void Array<T>::remove_at(size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < length - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --length;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
size_t Array<T>::size() const {
    return length;
}

template<typename T>
bool Array<T>::empty() const {
    return length == 0;
}

template<typename T>
void Array<T>::clear() {
    length = 0;
}

template<typename T>
void Array<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < length; ++i) {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}