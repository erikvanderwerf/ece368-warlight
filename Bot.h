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
#include "Parser.h"
#include "Region.h"
#include "SuperRegion.h"



class Bot: boost::noncopyable
{

public:
	enum Phase
	{
		NONE, PICK_STARTING_REGION, PLACE_ARMIES, ATTACK_TRANSFER
	};

	Bot();
	virtual ~Bot();

	void playGame();    ///< plays a single game of Warlight

	void pickStartingRegion();
	void placeArmies();
	void makeMoves();   ///< makes moves for a single turn

	void addRegion(const unsigned& noRegion, const unsigned& noSuperRegion);
	void addSuperRegion(const unsigned& noSuperRegion, const int& reward);
	void addNeighbors(const unsigned& noRegion, const unsigned& Neighbors);
	void addWasteland(const unsigned& noRegion);

	/// Setters for settings
	void setBotName(const std::string& name);
	void setOpponentBotName(const std::string& name);
	void setArmiesLeft(const int& nbArmies);
	void setTimebank(const int& newTimebank);
	void setTimePerMove(const int& newTimePerMove);
	void setMaxRounds(const int& newMaxRounds);

    /// Utilities
    //std::vector<int> getNeutralNeighbors(int Node);    ///Returns a vector of indexes that are the neutral neightbors
    //std::vector<int> getEnemyNeighbors(int Node);    ///Returns a vector of indexes that are enemy neighbors
    //std::vector<int> getPlayerNeighbors(int Node);   ///Returns a vector of indexes that are owned by you
    //std::vector<int> getLargestEnemies(int Node);     ///Returns a vector of the indexes of the enemies from largest to smallest
    //std::vector<Regions> getNeighborsInSameSuperRegion(Region Node);
    //int numNeighborsNotMe(int Node);   ///returns an integer of the number of neighbors that are not you at a certain region
    //int getNumberOfArmies(int Node);
    //std::vector<int> getOwnedRegions(int Node);
    //std::vector<int> getNeutralNeighbors(int Node);    ///Returns a vector of indexes that are the neutral neightbors
    //std::vector<int> getEnemyNeighbors(int Node);    ///Returns a vector of indexes that are enemy neighbors
    //std::vector<int> getPlayerNeighbors(int Node);
    
	/**
	 * Adds armies to a region
	 * @param noRegion region to add to
	 * @param nbArmies number of Armies
	 */
	void addArmies(const unsigned& noRegion, const int& nbArmies);
	/**
	 * Moves armies on the map
	 * @param noRegion starting region
	 * @param toRegion target region
	 * @param nbArmies number of Armies
	 */
	void moveArmies(const unsigned& noRegion, const unsigned& toRegion, const int& nbArmies);

	void clearStartingRegions();
	void addStartingRegion(const unsigned& noRegion);

	void addOpponentStartingRegion(const unsigned& noRegion);

	void opponentPlacement(const unsigned& noRegion, const int& nbArmies);
	void opponentMovement(const unsigned& noRegion, const unsigned& toRegion, const int& nbArmies);

	void startDelay(const int& delay);

	void setPhase(const Phase phase);

	/**
	 * Evaluates the current phase and in turn figures out the proper action for the current move
	 * Hook in your army placements and attack moves here
	 */
	void executeAction();
	/**
	 * Updates the regions from the game engine
	 * @param noRegion region identifier
	 * @param playerName player who owns it
	 * @param nbArmies number of armies he gets
	 */
	void updateRegion(const unsigned& noRegion, const std::string& playerName, const int& nbArmies);

	void resetRegionsOwned();

private:
	std::ifstream in;
	std::vector<Region> regions;
	std::vector<SuperRegion> superRegions;
	std::string botName;
	std::string opponentBotName;
	std::vector<int> startingRegionsreceived;
	std::vector<unsigned> opponentStartingRegions;
	std::vector<int> ownedRegions;
	std::vector<int> wastelands;
	//bool compareRegionsByArmies(std::vector<Region> regs, int regionIndex0, int regionIndex1);
	int armiesLeft;
	int timebank;
	int timePerMove;
	int maxRounds;
	Parser parser;
	Phase phase;
};

#endif // BOT_H
