#pragma once

#include <utility>
#include <memory>

#include "Point.h"

class Npc {
public:
	explicit Npc(std::string name, Point position);

	[[nodiscard]] virtual std::string get_type_name() = 0;

	[[nodiscard]] virtual char get_type_symbol() = 0;

	[[nodiscard]] virtual int get_move_distance() = 0;

	[[nodiscard]] virtual int get_kill_distance() = 0;

	[[nodiscard]] const std::string& get_name() const;

	[[nodiscard]] const Point& get_position() const;

	void set_position(const Point& point);

	[[nodiscard]] bool is_alive() const;

	void die();

	bool operator==(const Npc& other) const = default;

private:
	std::string name;
	Point position;
	bool alive = true;
};

class Squirrel : public Npc {
public:
	Squirrel(const std::string& name, const Point& position);

	[[nodiscard]] std::string get_type_name() override;

	[[nodiscard]] char get_type_symbol() override;

	[[nodiscard]] int get_move_distance() override;

	[[nodiscard]] int get_kill_distance() override;

	inline static const std::string type_name = "Squirrel";
};

class SlaveTrader : public Npc {
public:
	SlaveTrader(const std::string& name, const Point& position);

	[[nodiscard]] std::string get_type_name() override;

	[[nodiscard]] char get_type_symbol() override;

	[[nodiscard]] int get_move_distance() override;

	[[nodiscard]] int get_kill_distance() override;

	inline static const std::string type_name = "SlaveTrader";
};

class Knight : public Npc {
public:
	Knight(const std::string& name, const Point& position);

	[[nodiscard]] std::string get_type_name() override;

	[[nodiscard]] char get_type_symbol() override;

	[[nodiscard]] int get_move_distance() override;

	[[nodiscard]] int get_kill_distance() override;

	inline static const std::string type_name = "Knight";
};
