#pragma once

#include "Observable.h"
#include "Game.h"

class BattleObserver : public Observer<BattleEvent> {
	void handle(const BattleEvent& event) override {
		std::lock_guard cout_lock(*event.cout_mutex);

		std::cout << "Battle: " << event.victim->get_name()
				  << " is attacked by "
				  << event.initiator->get_name()
				  << "(" << event.attackPoints << " / "
				  << event.defensePoints << ")\n";
	}
};