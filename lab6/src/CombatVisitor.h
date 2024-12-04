#pragma once

#include "Npc.h"
#include "Visitor.h"

class CombatVisitor : public Visitor {
public:
	explicit CombatVisitor(const Npc& enemy);

public:
	void visit(Squirrel& squirrel) override;
	void visit(SlaveTrader& slave_trader) override;
	void visit(Knight& knight) override;

	[[nodiscard]] bool get_should_kill() const;

private:
	const Npc& victim;
	bool should_kill = false;
};

