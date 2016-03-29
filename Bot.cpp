// stl
#include <iostream>
#include <string>
#include <cstdlib>

//project
#include "Bot.h"
#include "Move.h"

//tools
#include "tools/StringManipulation.h"

Bot::Bot() :
		armiesLeft(0), timebank(0), timePerMove(0), maxRounds(0), parser(this)
{
}

Bot::~Bot()
{

}

void Bot::playGame()
{
	while (true) {
		// Wait for input
		parser.parseInput();
	}
}

void Bot::pickStartingRegion()
{
	std::cout << general.pickStartingRegions(startingRegionsreceived) << std::endl;
}

void Bot::placeArmies()
{
	for (Move m : general.getDeployment()) {
		std::cout << botName << "place_armies" << m.from->id << " " << m.number_of_troops << ", ";
	}
	std::cout << std::endl;

	//addArmies(ownedRegions[region], armiesLeft);
}

void Bot::makeMoves()
{
	// START HERE!
	/// Output No moves when you have no time left or do not want to commit any moves.
	// std::cout << "No moves "  << std::endl;
	/// Anatomy of a single move
	//  std::cout << botName << " attack/transfer " << from << " " << to << " "<< armiesMoved;
	/// When outputting multiple moves they must be seperated by a comma
	for (Move m : general.getAttack()) {
		std::cout << botName << "attack/transfer" << m.from << " " << m.to <<
			" " << m.number_of_troops << ", ";
	}
	std::cout << std::endl;

	/*std::vector<std::string> moves;
	for (size_t j = 0; j < ownedRegions.size(); ++j)
	{
		std::stringstream move;
		int i = ownedRegions[j];
		if (regions[i].getArmies() <= 1)
			continue;

		int target = regions[i].getNeighbor(std::rand() % regions[i].getNbNeighbors());
		// prefer enemy regions
		for ( unsigned k = 0; k < 5; ++k)
		{
			if(regions[target].getOwner() != ME) break;
			target = regions[i].getNeighbor(std::rand() % regions[i].getNbNeighbors());
		}
		move << botName << " attack/transfer " << i << " "
 				<< target << " "
				<< (regions[i].getArmies() - 1);
		moves.push_back(move.str());
	}

	std::cout << string::join(moves) << std::endl;*/
}

/*void Bot::addWasteland(const unsigned &noRegion)
{
	wastelands.push_back(noRegion);
}*/


void Bot::setBotName(const std::string& name)
{
	botName = name;
}
void Bot::setOpponentBotName(const std::string& name)
{
	opponentBotName = name;
}
void Bot::setArmiesLeft(const int& nbArmies)
{
	armiesLeft = nbArmies;
}
void Bot::setTimebank(const int &newTimebank)
{
	timebank = newTimebank;
}
void Bot::setTimePerMove(const int &newTimePerMove)
{
	timePerMove = newTimePerMove;
}
void Bot::setMaxRounds(const int &newMaxRounds)
{
	maxRounds = newMaxRounds;
}

void Bot::clearStartingRegions()
{
	startingRegionsreceived.clear();
}

void Bot::addStartingRegion(const unsigned& noRegion)
{
	startingRegionsreceived.push_back(noRegion);
}

void Bot::addOpponentStartingRegion(const unsigned& noRegion)
{
	opponentStartingRegions.push_back(noRegion);
}
void Bot::opponentPlacement(const unsigned & noRegion, const int & nbArmies)
{
	// suppress unused variable warnings
	(void) noRegion;
	(void) nbArmies;

	// TODO: STUB
}
void Bot::opponentMovement(const unsigned &noRegion, const unsigned &toRegion, const int &nbArmies)
{
	// suppress unused variable warnings
	(void) noRegion;
	(void) toRegion;
	(void) nbArmies;

	// TODO: STUB
}