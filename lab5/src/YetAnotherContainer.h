#pragma once

#include <memory>
#include <memory_resource>

template<class T>
struct Node {
    T item;
    Node<T> *next;

    Node() : item{}, next(nullptr) {}

    ~Node() {
        delete next;
    }
};

template<class T, class Allocator = std::pmr::polymorphic_allocator<T>>
class YetAnotherList {
public:
    explicit YetAnotherList(const Allocator &allocator) : allocator(allocator) {
        first = this->allocator.template allocate_object<Node<T>>();
        last = first;
    }

    ~YetAnotherList() {
        allocator.deallocate_object(first);
    }

    T &operator[](size_t index) {
        return *std::next(begin(), index);
    }

    const T &operator[](size_t index) const {
        return *std::next(begin(), index);
    }

    void push_back(const T &item) {
        last->item = item;
        last->next = allocator.template allocate_object<Node<T>>(1);
        last = last->next;
    }

    void remove_at(int index) {
        if (index == 0) {
            auto to_delete = first;
            first = first->next;

            to_delete->next = nullptr;
            allocator.deallocate_object(to_delete);

            return;
        }

        Node<T> *node = first;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
        auto to_delete = node->next;
        node->next = to_delete->next;

        to_delete->next = nullptr;
        allocator.deallocate_object(to_delete);

        if (to_delete == last) {
            last = node;
        }
    }

    size_t size() {
        int actualLength = 0;
        Node<T> *node = first;
        while (node->next != nullptr) {
            node = node->next;
            actualLength++;
        }

        return actualLength;
    }

    std::vector<T> to_vector() {
        std::vector<T> result;
        for (const auto &item: *this) {
            result.push_back(item);
        }
        return result;
    }

    class Iterator : std::forward_iterator_tag {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = value_type *;
        using reference = value_type &;

        explicit Iterator(Node<T> *node) : m_ptr(node) {}

        reference operator*() const { return m_ptr->item; }

        pointer operator->() { return &m_ptr->item; }

        // Prefix increment
        Iterator &operator++() {
            m_ptr = m_ptr->next;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        Node<T> *m_ptr;
    };

    Iterator begin() { return Iterator(first); }

    Iterator end() { return Iterator(last); }

private:
    Node<T> *first;
    Node<T> *last;
    Allocator allocator;
};


using category = std::iterator_traits<YetAnotherList<void *, void *>::Iterator>::iterator_category;
static_assert(std::is_same<category, std::forward_iterator_tag>::value);
