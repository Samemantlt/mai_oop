#include "Game.h"

#include <queue>
#include <random>

Game::Game(std::vector<std::shared_ptr<Npc>> characters) : characters(std::move(characters)) { }

Game::Game() : characters() { }

const std::vector<std::shared_ptr<Npc>>& Game::get_characters() const {
	return characters;
}

void Game::move_loop() {
	std::random_device rd;
	std::mt19937 gen(rd());

	while (is_running) {
		for (auto& npc : characters) {
			if (!npc->is_alive())
				continue;

			std::uniform_int_distribution<> dis(
					-npc->get_move_distance(),
					npc->get_move_distance()
			);

			Point new_position(
				std::clamp(npc->get_position().get_x() + dis(gen), 0, MAP_WIDTH - 1),
				std::clamp(npc->get_position().get_y() + dis(gen), 0, MAP_WIDTH - 1)
			);

			npc->set_position(new_position);
		}

		for (size_t i = 0; i < characters.size(); ++i) {
			for (size_t j = i + 1; j < characters.size(); ++j) {
				std::shared_ptr<Npc> npc1 = characters[i];
				std::shared_ptr<Npc> npc2 = characters[j];

				if (!npc1->is_alive() || !npc2->is_alive())
					continue;

				double distance = (npc1->get_position() - npc2->get_position()).length();

				if (distance <= std::max(npc1->get_kill_distance(), npc2->get_kill_distance())) {
					battle_queue.push(std::make_tuple(npc1, npc2));
					battle_queue_semaphore.release();
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void Game::combat_loop() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	while (is_running || !battle_queue.empty()) {
		while (true) {
			if (!is_running)
				return;

			battle_queue_semaphore.try_acquire_for(std::chrono::milliseconds(500));
			if (!battle_queue.empty())
				break;
		}

		auto task = battle_queue.pop_front();
		auto npc1 = std::get<0>(task);
		auto npc2 = std::get<1>(task);

		if (npc1->is_alive() && npc2->is_alive()) {
			int attackPoints = dis(gen);
			int defensePoints = dis(gen);

			if (attackPoints > defensePoints) {
				npc2->die();
				notify_observers({npc1, npc2, attackPoints, defensePoints, &cout_mutex});
			} else {
				npc1->die();
				notify_observers({npc2, npc1, attackPoints, defensePoints, &cout_mutex});
			}
		}
	}
}

void Game::print_map()
{
	std::vector<std::vector<char>> map(MAP_WIDTH,
			std::vector<char>(MAP_WIDTH, '.'));

	for (const auto& npc : characters) {
		if (npc->is_alive()) {
			map[npc->get_position().get_y()][npc->get_position().get_x()] = npc->get_type_symbol();
		}
	}

	{
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "\nMap:\n";
		for (const auto& row : map) {
			for (char cell : row) {
				std::cout << cell;
			}
			std::cout << "\n";
		}
	}
}

void Game::print_loop() {
	while (is_running) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		print_map();
	}
}

void Game::run(int game_duration) {
	print_map();

	std::cout << "Game will start in 3 seconds...\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::thread print_thread([this]() { print_loop(); });
	std::thread move_thread([this]() { move_loop(); });
	std::thread combat_thread([this]() { combat_loop(); });

	std::this_thread::sleep_for(std::chrono::seconds(game_duration));
	is_running = false;

	battle_queue_semaphore.release(); // Make combat_loop check is_running

	print_thread.join();
	move_thread.join();
	combat_thread.join();

	std::cout << "\nGame ended!\nSurvivors:\n";
	int survivors_count = 0;
	for (const auto& npc : characters) {
		if (npc->is_alive()) {
			survivors_count++;
			std::cout << npc->get_type_name() << " \"" << npc->get_name() << "\": ("
					  << npc->get_position().get_x() << "," << npc->get_position().get_y() << ")\n";
		}
	}
	std::cout << "Survivors count: " << survivors_count << "\n";
}

Game Game::generate() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, Game::MAP_WIDTH - 1);
	std::uniform_int_distribution<> type_dis(0, 2);
	std::vector<std::shared_ptr<Npc>> characters;

	for (int i = 0; i < INITIAL_NPC_COUNT; ++i) {
		int x = dis(gen);
		int y = dis(gen);
		int type = type_dis(gen);

		switch (type) {
			case 0: {
				std::string name = "Knight_";
				name.append(std::to_string(i));

				characters.push_back(std::make_shared<Knight>(name, Point(x, y)));
				break;
			}
			case 1: {
				std::string name = "Squirrel_";
				name.append(std::to_string(i));

				characters.push_back(std::make_shared<Squirrel>(name, Point(x, y)));
				break;
			}
			case 2: {
				std::string name = "SlaveTrader_";
				name.append(std::to_string(i));

				characters.push_back(std::make_shared<SlaveTrader>(name, Point(x, y)));
				break;
			}
		}
	}

	return Game(characters);
}
