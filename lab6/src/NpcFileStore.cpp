#include "NpcFileStore.h"

#include <utility>
#include <fstream>

#include "NpcFactory.h"

NpcFileStore::NpcFileStore(std::string file_path) : filePath(std::move(file_path)) { }

std::vector<std::shared_ptr<Npc>> NpcFileStore::load() {
	std::ifstream input(filePath);

	std::vector<std::shared_ptr<Npc>> result;

	int32_t count;
	input >> count;

	for (int32_t i = 0; i < count; i++) {
		std::string type, name;
		Point position;

		input >> type >> name >> position;

		auto npc = NpcFactory::create_npc(type, name, position);
		result.push_back(npc);
	}

	return result;
}

void NpcFileStore::save(const std::vector<std::shared_ptr<Npc>>& characters) {
	std::ofstream output(filePath);

	output << characters.size() << std::endl;

	for (auto& character : characters) {
		output << character->get_type_name() << " " << character->get_name() << " " << character->get_position()
			   << "\n";
	}

	output.flush();
	output.close();
}

std::string NpcFileStore::get_file_path() const {
	return filePath;
}
