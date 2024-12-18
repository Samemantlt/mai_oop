#include "NpcFactory.h"

std::shared_ptr<Npc> NpcFactory::create_npc(const std::string& type, const std::string& name, Point position) {
	if (type == Squirrel::type_name)
		return std::make_shared<Squirrel>(name, position);
	if (type == SlaveTrader::type_name)
		return std::make_shared<SlaveTrader>(name, position);
	if (type == Knight::type_name)
		return std::make_shared<Knight>(name, position);

	throw std::runtime_error("Unknown type of NPC passed");
}
