#include <map>

#include "Bot.h"
#include "General.h"

General::General(Bot* b) : bot(b) {
	Attack* a = new Attack(&map);
	Defense* d = new Defense(&map);

	attackAdvisor = a;
	defenseAdvisor = d;
}

General::~General() {
}

Region* General::pickStartingRegions(int time, size_t num, std::unordered_set<Region*> pickfrom) {
	std::map<Region*, int> regions;
	for (Region* region : pickfrom) {
		int score = 0;

		// Centrality of region
		std::cerr << "Centrality" << std::endl;
		int cent = map.getCentrality(region);
		std::cerr << region->id << ": " << cent << std::endl;

		regions.insert(std::pair<Region*, int>(region, score));
	}

	// Get the highest value region
	std::cerr << "Num: " << regions.size() << std::endl;

	std::pair<Region*, int> r(nullptr, 0);
	for (std::pair<Region*, int> region: regions)
		if (r.second < region.second || r.first == nullptr) r = region;
	return r.first;
}

std::vector<Move> General::getAttack() {
	if (map.isDirty()) calculateTurn();
	return attacks;
}

std::vector<Move> General::getDeployment() {
	if (map.isDirty()) calculateTurn();
	return deployment;
}

void General::calculateTurn() {
	// Clean up
	map.setClean();
	attacks.clear();
	deployment.clear();

	// Get things for this turn
	auto atk = attackAdvisor->generateMoves();
	auto def = defenseAdvisor->generateMoves();

	int i = 0;

	while (bot->armies > 0) {
		Move move = atk.at(i++);

		deployment.push_back(move);
		attacks.push_back(move);
		bot->armies -= move.armies;
	}
}