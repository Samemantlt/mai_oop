#pragma once

#include "Observable.h"
#include "Game.h"

class KillObserver : public Observer<NpcKillEvent> {
	void handle(const NpcKillEvent& event) override {
		std::cout << event.victim->get_type_name() << " '" << event.victim->get_name() << "' was killed by "
				  << event.initiator->get_type_name() << " '" << event.initiator->get_name() << "'" << std::endl;
	}
};