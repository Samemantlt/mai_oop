#include "Game.h"

Game::Game(std::vector<std::shared_ptr<Npc>> characters) : characters(std::move(characters)) { }

Game::Game() : characters() { }

void Game::perform_combat(double distance) {
	std::list<std::shared_ptr<Npc>> dead_npcs;

	for (auto& initiator : characters) {
		for (auto& victim : characters) {
			if (&initiator == &victim)
				continue;
			if ((initiator->get_position() - victim->get_position()).length() > distance)
				continue;

			CombatVisitor combatVisitor(*victim);

			initiator->accept(combatVisitor);

			bool shouldKill = combatVisitor.get_should_kill();
			if (shouldKill) {
				dead_npcs.push_back(victim);
				notify_observers({ initiator, victim });
			}
		}
	}

	for (auto& npc : dead_npcs) {
		characters.erase(std::find(characters.begin(), characters.end(), npc));
	}
}

const std::vector<std::shared_ptr<Npc>>& Game::get_characters() const {
	return characters;
}

void Game::add_npc(const std::shared_ptr<Npc>& npc) {
	characters.push_back(npc);
}
