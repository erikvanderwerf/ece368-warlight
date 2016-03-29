#ifndef BOT_H
#define BOT_H

// stl
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>

// project
#include "main.h"
#include "General.h"
#include "Move.h"
#include "Parser.h"


class Bot: boost::noncopyable
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

	void pickStartingRegion();
	void placeArmies();
	void makeMoves();

	//void addRegion(const unsigned& noRegion, const unsigned& noSuperRegion);
	//void addSuperRegion(const unsigned& noSuperRegion, const int& reward);
	//void addNeighbors(const unsigned& noRegion, const unsigned& Neighbors);
	//void addWasteland(const unsigned& noRegion);

	/// Setters for settings
	void setBotName(const std::string& name);
	void setOpponentBotName(const std::string& name);
	void setArmiesLeft(const int& nbArmies);
	void setTimebank(const int& newTimebank);
	void setTimePerMove(const int& newTimePerMove);
	void setMaxRounds(const int& newMaxRounds);

	/**
	 * Adds armies to a region
	 * @param noRegion region to add to
	 * @param nbArmies number of Armies
	 */
	//void addArmies(const unsigned& noRegion, const int& nbArmies);
	/**
	 * Moves armies on the map
	 * @param noRegion starting region
	 * @param toRegion target region
	 * @param nbArmies number of Armies
	 */
	//void moveArmies(const unsigned& noRegion, const unsigned& toRegion, const int& nbArmies);

	void clearStartingRegions();
	void addStartingRegion(const unsigned& noRegion);

	void addOpponentStartingRegion(const unsigned& noRegion);

	void opponentPlacement(const unsigned& noRegion, const int& nbArmies);
	void opponentMovement(const unsigned& noRegion, const unsigned& toRegion, const int& nbArmies);

	//void setPhase(const Phase phase);

	/**
	 * Evaluates the current phase and in turn figures out the proper action for the current move
	 * Hook in your army placements and attack moves here
	 */
	//void executeAction();
	/**
	 * Updates the regions from the game engine
	 * @param noRegion region identifier
	 * @param playerName player who owns it
	 * @param nbArmies number of armies he gets
	 */
	//void updateRegion(const unsigned& noRegion, const std::string& playerName, const int& nbArmies);

	General general;
	std::string botName;
	std::string opponentBotName;
private:
	std::ifstream in;
	std::vector<int> startingRegionsreceived;
	std::vector<unsigned> opponentStartingRegions;
	//std::vector<int> ownedRegions;
	//std::vector<int> wastelands;
	int armiesLeft;
	int timebank;
	int timePerMove;
	int maxRounds;
	Parser parser;

};

#endif // BOT_H
