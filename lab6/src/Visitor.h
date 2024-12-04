#pragma once

#include <memory>
#include <utility>

#include "Point.h"
#include "Npc.h"

class Visitor {
public:
	virtual void visit(Squirrel& squirrel) = 0;
	virtual void visit(SlaveTrader& slave_trader) = 0;
	virtual void visit(Knight& knight) = 0;
};

