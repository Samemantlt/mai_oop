#pragma once

#include <vector>
#include <list>

#include "Npc.h"
#include "CombatVisitor.h"
#include "NpcFileStore.h"
#include "Observable.h"

struct NpcKillEvent {
    std::shared_ptr<Npc> initiator;
    std::shared_ptr<Npc> victim;
};

class Game : public Observable<NpcKillEvent> {
public:
    explicit Game();

    explicit Game(std::vector<std::shared_ptr<Npc>> characters);

    void perform_combat(double distance);

    [[nodiscard]] const std::vector<std::shared_ptr<Npc>> &get_characters() const;

    void add_npc(const std::shared_ptr<Npc> &npc);

private:
    std::vector<std::shared_ptr<Npc>> characters;
};
