#include "Npc.h"

Npc::Npc(std::string name, Point position) : name(std::move(name)), position(position) { }

const std::string& Npc::get_name() const {
	return name;
}

const Point& Npc::get_position() const {
	return position;
}

void Npc::set_position(const Point& point) {
	position = point;
}

bool Npc::is_alive() const {
	return alive;
}

void Npc::die() {
	alive = false;
}

Squirrel::Squirrel(const std::string& name, const Point& position) : Npc(name, position) { }

std::string Squirrel::get_type_name() {
	return type_name;
}

char Squirrel::get_type_symbol() {
	return 'B';
}

int Squirrel::get_move_distance() {
	return 5;
}

int Squirrel::get_kill_distance() {
	return 5;
}

SlaveTrader::SlaveTrader(const std::string& name, const Point& position) : Npc(name, position) { }

std::string SlaveTrader::get_type_name() {
	return type_name;
}

char SlaveTrader::get_type_symbol() {
	return 'T';
}

int SlaveTrader::get_move_distance() {
	return 10;
}

int SlaveTrader::get_kill_distance() {
	return 10;
}

Knight::Knight(const std::string& name, const Point& position) : Npc(name, position) { }

std::string Knight::get_type_name() {
	return type_name;
}

char Knight::get_type_symbol() {
	return 'K';
}

int Knight::get_move_distance() {
	return 30;
}

int Knight::get_kill_distance() {
	return 10;
}
