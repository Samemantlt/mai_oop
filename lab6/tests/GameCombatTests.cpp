#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "Game.h"

TEST(GameCombatTests, TwoSquirrelsTest) {
    Game game(
        std::vector<std::shared_ptr<Npc>> {
            std::make_shared<Squirrel>("Squirrel_1", Point(1, 1)),
            std::make_shared<Squirrel>("Squirrel_2", Point(1, 2))
        }
    );

    game.perform_combat(1);

    ASSERT_TRUE(game.get_characters().empty());
}

TEST(GameCombatTests, SquirrelAndSlaveTraderTest) {
    auto squirrel = std::make_shared<Squirrel>("Squirrel_1", Point(1, 1));
    auto slave_trader = std::make_shared<SlaveTrader>("SlaveTrader_1", Point(1, 2));

    Game game(
            std::vector<std::shared_ptr<Npc>> {
                    squirrel,
                    slave_trader
            }
    );

    game.perform_combat(1);

    ASSERT_THAT(game.get_characters(), testing::ElementsAre(slave_trader));
}

TEST(GameCombatTests, SquirrelAndKnightTest) {
    auto squirrel = std::make_shared<Squirrel>("Squirrel_1", Point(1, 1));
    auto knight = std::make_shared<Knight>("Knight_1", Point(1, 2));

    Game game(
            std::vector<std::shared_ptr<Npc>> {
                    squirrel,
                    knight
            }
    );

    game.perform_combat(1);

    ASSERT_THAT(game.get_characters(), testing::ElementsAre(squirrel, knight));
}

TEST(GameCombatTests, SlaveTraderAndKnightTest) {
    auto slave_trader = std::make_shared<SlaveTrader>("SlaveTrader_1", Point(1, 2));
    auto knight = std::make_shared<Knight>("Knight_1", Point(1, 2));

    Game game(
            std::vector<std::shared_ptr<Npc>> {
                    slave_trader,
                    knight
            }
    );

    game.perform_combat(1);

    ASSERT_THAT(game.get_characters(), testing::ElementsAre(knight));
}

TEST(GameCombatTests, TwoSquirrelsSmallDistanceTest) {
    auto squirrel = std::make_shared<Squirrel>("Squirrel_1", Point(1, 1));
    auto squirrel2 = std::make_shared<Squirrel>("Squirrel_1", Point(1, 3));
    Game game(
            std::vector<std::shared_ptr<Npc>> {
                    squirrel,
                    squirrel2
            }
    );

    game.perform_combat(1);

    ASSERT_THAT(game.get_characters(), testing::ElementsAre(squirrel, squirrel2));
}