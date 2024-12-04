#include <iostream>

#include "YetAnotherContainer.h"
#include "YetAnotherMemoryResource.h"


int main() {
    YetAnotherMemoryResource memory_resource;
    std::pmr::polymorphic_allocator<> polymorphic_allocator(&memory_resource);

    YetAnotherList<int> list(polymorphic_allocator);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::cout << "Elements (length " << list.size() << "):\n";
    for (auto &element: list) {
        std::cout << element << "\n";
    }

    return 0;
}
