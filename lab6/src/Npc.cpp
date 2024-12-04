#include "Npc.h"
#include "Visitor.h"

Npc::Npc(std::string name, Point position) : name(std::move(name)), position(position) { }

const std::string& Npc::get_name() const {
	return name;
}

const Point& Npc::get_position() const {
	return position;
}

Squirrel::Squirrel(const std::string& name, const Point& position) : Npc(name, position) { }

void Squirrel::accept(Visitor& visitor) {
	visitor.visit(*this);
}

std::string Squirrel::get_type_name() {
	return type_name;
}

SlaveTrader::SlaveTrader(const std::string& name, const Point& position) : Npc(name, position) { }

void SlaveTrader::accept(Visitor& visitor) {
	visitor.visit(*this);
}

std::string SlaveTrader::get_type_name() {
	return type_name;
}

Knight::Knight(const std::string& name, const Point& position) : Npc(name, position) { }

void Knight::accept(Visitor& visitor) {
	visitor.visit(*this);
}

std::string Knight::get_type_name() {
	return type_name;
}
