#include <iostream>

#include "Game.h"
#include "NpcFactory.h"
#include "KillObserver.h"

int show_menu() {
	std::cout << "\n";
	std::cout << "Menu:\n";
	std::cout << "1 - Print all characters\n";
	std::cout << "2 - Battle\n";
	std::cout << "3 - Add Npc\n";
	std::cout << "4 - Save game to file\n";
	std::cout << "5 - Load game from file\n";
	std::cout << "0 - Exit\n";

	std::cout << "Enter your selection: ";

	int result;
	std::cin >> result;
	return result;
}

void print_characters(const Game& game) {
	std::cout << "Characters\n";
	std::cout << "Type: Name (X Y)\n";
	for (auto& character : game.get_characters()) {
		std::cout << character->get_type_name() << ": " << character->get_name() << " (" << character->get_position()
				  << ")\n";
	}
}

void add_npc_menu(Game& game) {
	std::string type;
	std::cout << "Enter type (Squirrel, Knight or SlaveTrader): ";
	std::cin >> type;

	std::string name;
	std::cout << "Enter name (string): ";
	std::cin >> name;

	Point position;
	std::cout << "Enter position (int int) (eg. 1 1): ";
	std::cin >> position;

	auto npc = NpcFactory::create_npc(type, name, position);
	game.add_npc(npc);
}

void save_file_menu(Game& game) {
	std::string file_path;
	std::cout << "Enter save file path: ";
	std::cin >> file_path;

	NpcFileStore file_store(file_path);
	file_store.save(game.get_characters());
}

Game load_file_menu() {
	std::string file_path;
	std::cout << "Enter save file path: ";
	std::cin >> file_path;

	NpcFileStore file_store(file_path);
	auto characters = file_store.load();

	return Game(characters);
}

void perform_menu() {
	Game game;
	std::shared_ptr<KillObserver> kill_observer = std::make_shared<KillObserver>();

	game.add_observer(kill_observer);

	while (true) {
		int button = show_menu();
		std::cout << std::endl;

		switch (button) {
			case 1:
				print_characters(game);
				break;
			case 2:
				double distance;
				std::cout << "Enter distance: ";
				std::cin >> distance;

				game.perform_combat(distance);
				print_characters(game);
				break;
			case 3:
				add_npc_menu(game);
				break;
			case 4:
				save_file_menu(game);
				break;
			case 5:
				game = load_file_menu();
				game.add_observer(kill_observer);
				break;
			case 0:
				return;
		}
	}
}

int main() {
	perform_menu();
	return 0;
}
