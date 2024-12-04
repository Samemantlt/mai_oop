#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "YetAnotherContainer.h"
#include "YetAnotherMemoryResource.h"

struct SampleItem {
    int a;
    bool b;

    SampleItem(int a, bool b) : a(a), b(b) {}

    bool operator==(const SampleItem &other) const = default;
    bool operator!=(const SampleItem &other) const = default;
};

TEST(YetAnotherListOfStructTests, SimpleTests) {
    YetAnotherMemoryResource memory_resource;

    const std::pmr::polymorphic_allocator polymorphic_allocator(&memory_resource);
    YetAnotherList<SampleItem> list(polymorphic_allocator);

    list.push_back(SampleItem(1, true));

    ASSERT_THAT(list.to_vector(), testing::ElementsAre(
            SampleItem(1, true)
    ));
}

TEST(YetAnotherListOfStructTests, SimpleTests2) {
    YetAnotherMemoryResource memory_resource;

    const std::pmr::polymorphic_allocator polymorphic_allocator(&memory_resource);
    YetAnotherList<SampleItem> list(polymorphic_allocator);

    list.push_back(SampleItem(1, true));
    list.push_back(SampleItem(2, false));
    list.push_back(SampleItem(3, true));

    ASSERT_THAT(list.to_vector(), testing::ElementsAre(
            SampleItem(1, true),
            SampleItem(2, false),
            SampleItem(3, true)
    ));
}

TEST(YetAnotherListOfStructTests, SimpleTests3) {
    YetAnotherMemoryResource memory_resource;

    const std::pmr::polymorphic_allocator polymorphic_allocator(&memory_resource);
    YetAnotherList<SampleItem> list(polymorphic_allocator);

    list.push_back(SampleItem(1, true));
    list.push_back(SampleItem(2, false));
    list.push_back(SampleItem(3, true));

    list.remove_at(0);

    list.push_back(SampleItem(4, true));

    ASSERT_THAT(list.to_vector(), testing::ElementsAre(
            SampleItem(2, false),
            SampleItem(3, true),
            SampleItem(4, true)
    ));
}