#pragma once

#include <vector>
#include <list>
#include <semaphore>

#include "Npc.h"
#include "Observable.h"
#include "ConcurrentQueue.h"

struct BattleEvent {
    std::shared_ptr<Npc> initiator;
    std::shared_ptr<Npc> victim;
	int attackPoints;
	int defensePoints;
	std::mutex* cout_mutex;
};

class Game : public Observable<BattleEvent> {
public:
	static constexpr int MAP_WIDTH = 100;
	static constexpr int INITIAL_NPC_COUNT = 50;

    explicit Game();

    explicit Game(std::vector<std::shared_ptr<Npc>> characters);

    [[nodiscard]] const std::vector<std::shared_ptr<Npc>> &get_characters() const;

	void run(int game_duration);

	static Game generate();

private:
	void move_loop();
	void combat_loop();
	void print_loop();
	void print_map();

	volatile bool is_running = true;

	ConcurrentQueue<std::tuple<std::shared_ptr<Npc>, std::shared_ptr<Npc>>> battle_queue{};
	std::counting_semaphore<INT32_MAX> battle_queue_semaphore{0};
	std::mutex cout_mutex;
    std::vector<std::shared_ptr<Npc>> characters;
};
