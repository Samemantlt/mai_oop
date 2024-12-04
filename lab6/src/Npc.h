#pragma once

#include <utility>
#include <memory>

#include "Point.h"

class Visitor;

class Npc {
public:
	explicit Npc(std::string name, Point position);

	virtual void accept(Visitor& visitor) = 0;

	[[nodiscard]] virtual std::string get_type_name() = 0;

	[[nodiscard]] const std::string& get_name() const;

	[[nodiscard]] const Point& get_position() const;

	bool operator==(const Npc& other) const = default;

private:
	std::string name;
	Point position;
};

class Squirrel : public Npc {
public:
	Squirrel(const std::string& name, const Point& position);

	void accept(Visitor& visitor) override;

	[[nodiscard]] std::string get_type_name() override;

	inline static const std::string type_name = "Squirrel";
};

class SlaveTrader : public Npc {
public:
	SlaveTrader(const std::string& name, const Point& position);

	void accept(Visitor& visitor) override;

	[[nodiscard]] std::string get_type_name() override;

	inline static const std::string type_name = "SlaveTrader";
};

class Knight : public Npc {
public:
	Knight(const std::string& name, const Point& position);

	void accept(Visitor& visitor) override;

	[[nodiscard]] std::string get_type_name() override;

	inline static const std::string type_name = "Knight";
};
