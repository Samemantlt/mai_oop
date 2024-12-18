#include "Game.h"
#include "BattleObserver.h"

int main() {
	Game game = Game::generate();
	std::shared_ptr<BattleObserver> battle_observer = std::make_shared<BattleObserver>();
	game.add_observer(battle_observer);

	game.run(30);

	return 0;
}
