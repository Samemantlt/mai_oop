#include <gtest/gtest.h>

#include "Game.h"
#include "NpcFileStore.h"

TEST(NpcFileStoreTests, TwoSquirrelsTest) {
    std::vector<std::shared_ptr<Npc>> original{
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 1)),
            std::make_shared<Squirrel>("Squirrel_2", Point(1, 2))
    };

    NpcFileStore fileStore("save.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
    for (auto i = 0; i < original.size(); i++) {
        ASSERT_EQ(*original[i], *copy[i]);
    }
}

TEST(NpcFileStoreTests, SquirrelAndSlaveTraderTest) {
    std::vector<std::shared_ptr<Npc>> original{
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 1)),
            std::make_shared<SlaveTrader>("SlaveTrader_1", Point(1, 2))
    };

    NpcFileStore fileStore("save2.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
    for (auto i = 0; i < original.size(); i++) {
        ASSERT_EQ(*original[i], *copy[i]);
    }
}

TEST(NpcFileStoreTests, SquirrelAndKnightTest) {
    std::vector<std::shared_ptr<Npc>> original{
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 1)),
            std::make_shared<Knight>("Knight_1", Point(1, 2))
    };

    NpcFileStore fileStore("save3.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
    for (auto i = 0; i < original.size(); i++) {
        ASSERT_EQ(*original[i], *copy[i]);
    }
}

TEST(NpcFileStoreTests, SlaveTraderAndKnightTest) {
    std::vector<std::shared_ptr<Npc>> original{
            std::make_shared<SlaveTrader>("SlaveTrader_1", Point(1, 2)),
            std::make_shared<Knight>("Knight_1", Point(1, 2))
    };

    NpcFileStore fileStore("save4.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
    for (auto i = 0; i < original.size(); i++) {
        ASSERT_EQ(*original[i], *copy[i]);
    }
}

TEST(NpcFileStoreTests, TwoSquirrelsSmallDistanceTest) {
    std::vector<std::shared_ptr<Npc>> original{
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 1)),
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 3))
    };

    NpcFileStore fileStore("save5.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
    for (auto i = 0; i < original.size(); i++) {
        ASSERT_EQ(*original[i], *copy[i]);
    }
}

TEST(NpcFileStoreTests, EmptyTest) {
    std::vector<std::shared_ptr<Npc>> original;

    NpcFileStore fileStore("save5.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
}

TEST(NpcFileStoreTests, ManySquirrelsTest) {
    std::vector<std::shared_ptr<Npc>> original{
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 1)),
            std::make_shared<Squirrel>("Squirrel_2", Point(1, 2)),
            std::make_shared<Squirrel>("Squirrel_3", Point(1, 3)),
            std::make_shared<Squirrel>("Squirrel_4", Point(1, 4)),
            std::make_shared<Squirrel>("Squirrel_5", Point(1, 5)),
            std::make_shared<Squirrel>("Squirrel_6", Point(1, 6)),
    };

    NpcFileStore fileStore("save5.txt");
    fileStore.save(original);

    auto copy = fileStore.load();

    ASSERT_TRUE(original.size() == copy.size());
    for (auto i = 0; i < original.size(); i++) {
        ASSERT_EQ(*original[i], *copy[i]);
    }
}