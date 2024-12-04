#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "YetAnotherContainer.h"
#include "YetAnotherMemoryResource.h"

TEST(YetAnotherListOfIntTests, SimpleTests) {
    YetAnotherMemoryResource memory_resource;

    const std::pmr::polymorphic_allocator polymorphic_allocator(&memory_resource);
    YetAnotherList<int> list(polymorphic_allocator);

    list.push_back(1);

    ASSERT_THAT(list.to_vector(), testing::ElementsAre(1));
}

TEST(YetAnotherListOfIntTests, SimpleTests2) {
    YetAnotherMemoryResource memory_resource;

    const std::pmr::polymorphic_allocator polymorphic_allocator(&memory_resource);
    YetAnotherList<int> list(polymorphic_allocator);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_THAT(list.to_vector(), testing::ElementsAre(1, 2, 3));
}

TEST(YetAnotherListOfIntTests, SimpleTests3) {
    YetAnotherMemoryResource memory_resource;

    const std::pmr::polymorphic_allocator polymorphic_allocator(&memory_resource);
    YetAnotherList<int> list(polymorphic_allocator);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.remove_at(0);

    list.push_back(4);

    ASSERT_THAT(list.to_vector(), testing::ElementsAre(2, 3, 4));
}