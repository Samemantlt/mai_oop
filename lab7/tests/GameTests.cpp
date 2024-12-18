#include <gtest/gtest.h>

#include "Game.h"

int count_alive_characters(const Game& game) {
	int count = 0;
	for (const auto& character : game.get_characters()) {
		if (character->is_alive())
			count++;
	}
	return count;
}

TEST(GameTests, TwoSquirrelsSmallDistanceTest) {
	std::vector<std::shared_ptr<Npc>> characters{
		std::make_shared<Squirrel>("S_1", Point(0, 0)),
		std::make_shared<Squirrel>("S_2", Point(0, 1)),
	};

	Game game(characters);

	// Act
	game.run(2);

	ASSERT_LE(count_alive_characters(game), 2);
	ASSERT_GE(count_alive_characters(game), 1);
}


TEST(GameTests, KnightAndSquirrelTest) {
	std::vector<std::shared_ptr<Npc>> characters{
			std::make_shared<Squirrel>("S_1", Point(0, 0)),
			std::make_shared<Knight>("K_1", Point(0, 1)),
	};

	Game game(characters);

	// Act
	game.run(2);

	ASSERT_LE(count_alive_characters(game), 2);
	ASSERT_GE(count_alive_characters(game), 1);
}

TEST(GameTests, KnightAndSquirrelBigDistanceTest) {
	std::vector<std::shared_ptr<Npc>> characters{
			std::make_shared<Squirrel>("S_1", Point(0, 0)),
			std::make_shared<Knight>("K_1", Point(50, 50)),
	};

	Game game(characters);

	// Act
	game.run(2);

	ASSERT_EQ(count_alive_characters(game), 2);
}

TEST(GameTests, GeneratedGameTest) {
	Game game = Game::generate();

	ASSERT_EQ(count_alive_characters(game), Game::INITIAL_NPC_COUNT);

	// Act
	game.run(15);

	ASSERT_LE(count_alive_characters(game), Game::INITIAL_NPC_COUNT);
	ASSERT_GE(count_alive_characters(game), 1);
}