#ifndef BOT_H
#define BOT_H

// stl
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

// project
#include "main.h"
#include "General.h"
#include "Move.h"
#include "Parser.h"

class Bot : boost::noncopyable
{
public:
	/*enum Phase
	{
		NONE, PICK_STARTING_REGION, PLACE_ARMIES, ATTACK_TRANSFER
	};*/

	Bot();
	virtual ~Bot();

	/** void playGame();
	 * Plays a single game of Warlight from the beginning.
	 */
	void playGame();

	void pickStartingRegion(int time, std::unordered_set<Region*> regions);
	void placeArmies();
	void makeMoves();

	/// Setters for settings
	void setBotName(const std::string& name);
	void setOpponentBotName(const std::string& name);
	void setArmiesLeft(const int& nbArmies);
	void setTimebank(const int& newTimebank);
	void setTimePerMove(const int& newTimePerMove);
	void setMaxRounds(const int& newMaxRounds);

	/// Utilities
	void clearStartingRegions();
	void addStartingRegion(const unsigned& noRegion);

	void addOpponentStartingRegion(const unsigned& noRegion);

	void opponentPlacement(const unsigned& noRegion, const int& nbArmies);
	void opponentMovement(const unsigned& noRegion, const unsigned& toRegion, const int& nbArmies);

	bool volatile game_running;
	int armies, startingPickAmount;

	General general;
	std::string botName;
	std::string opponentBotName;

	std::vector<Region*> startingRegionsreceived;
	std::vector<unsigned int> opponentStartingRegions;
private:
	int timebank;
	int timePerMove;
	int maxRounds;
	Parser parser;
};

#endif // BOT_H
