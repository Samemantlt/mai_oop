#pragma once

#include <vector>
#include <memory>

#include "Npc.h"

class NpcFileStore {
public:
	explicit NpcFileStore(std::string file_path);

	std::vector<std::shared_ptr<Npc>> load();

	void save(const std::vector<std::shared_ptr<Npc>>& characters);

	[[nodiscard]] std::string get_file_path() const;

private:
	std::string filePath;
};
