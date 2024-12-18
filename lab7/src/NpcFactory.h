#pragma once

#include "Npc.h"

class NpcFactory {
public:
	static std::shared_ptr<Npc> create_npc(const std::string& type, const std::string& name, Point position);
};
