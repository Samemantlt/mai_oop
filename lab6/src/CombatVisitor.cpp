#include "CombatVisitor.h"

CombatVisitor::CombatVisitor(const Npc& victim) : victim(victim) { }

void CombatVisitor::visit(Squirrel& squirrel) {
	if (dynamic_cast<const Squirrel*>(&victim)) {
		should_kill = true;
	}
}

void CombatVisitor::visit(SlaveTrader& slave_trader) {
	if (dynamic_cast<const Squirrel*>(&victim)) {
		should_kill = true;
	}
}

void CombatVisitor::visit(Knight& knight) {
	if (dynamic_cast<const SlaveTrader*>(&victim)) {
		should_kill = true;
	}
}

bool CombatVisitor::get_should_kill() const { return should_kill; }
