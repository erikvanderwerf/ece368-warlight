//stl
#include <iostream>
#include <stdlib.h>
#include <stdexcept>

// project
#include "Bot.h"
#include "Parser.h"
#include "SuperRegion.h"

// tools
#include "tools/StringManipulation.h"

Parser::Parser(Bot* bot) :
		theBot(bot)
{
}

Parser::~Parser()
{
}

void Parser::parseInput()
{
	std::string inputType;
	std::cin >> inputType;
	if (inputType == "setup_map")
		parseSetupMap();
	else if (inputType == "settings")
		parseSettings();
	else if (inputType == "update_map")
		parseUpdateMap();
	else if (inputType == "opponent_moves")
		parseOpponentMoves();
	else if (inputType == "pick_starting_region")
		parsePickStartingRegion();
	else if (inputType == "go")
		parseGo();
	else
	{
		// Invalid inputType
		std::string line;
		getline(std::cin, line);
		std::cerr  << inputType << " " << line << std::endl;
	}
}

void Parser::parseSetupMap()
{
	std::string setupType;
	std::cin >> setupType;
	if (setupType == "super_regions")
		parseSuperRegions();
	else if (setupType == "regions")
		parseRegions();
	else if (setupType == "neighbors")
		parseNeighbors();
	else if (setupType == "wastelands")
		parseWastelands();
	else if (setupType == "opponent_starting_regions")
		parseOpponentStartingRegions();
}

void Parser::parseSettings()
{
	std::string settingType;
	std::cin >> settingType;
	if (settingType == "timebank")
	{
		int timebank;
		std::cin >> timebank;
		theBot->setTimebank(timebank);
	}
	else if (settingType == "time_per_move")
	{
		int timePerMove;
		std::cin >> timePerMove;
		theBot->setTimePerMove(timePerMove);
	}
	else if (settingType == "max_rounds")
	{
		int maxRounds;
		std::cin >> maxRounds;
		theBot->setMaxRounds(maxRounds);
	}
	else if (settingType == "your_bot")
	{
		std::string bot_name;
		std::cin >> bot_name;
		theBot->setBotName(bot_name);
	}
	else if (settingType == "opponent_bot")
	{
		std::string bot_name;
		std::cin >> bot_name;
		theBot->setOpponentBotName(bot_name);
	}
	else if (settingType == "starting_armies")
	{
		int nbArmies;
		std::cin >> nbArmies;
		theBot->setArmiesLeft(nbArmies);
	}
	else if (settingType == "starting_regions")
	{
		unsigned noRegion;
		while (std::cin >> noRegion)
		{
			theBot->addStartingRegion(noRegion);
			if (lineEnds())
				break;
		}
	}
}

void Parser::parseUpdateMap()
{
	std::string playerName;
	Player player;
	unsigned noRegion;
	int nbArmies;
	while (std::cin >> noRegion >> playerName >> nbArmies)
	{
		if (theBot->botName == playerName)
			player = ME;
		else if (theBot->opponentBotName == playerName)
			player = ENEMY;
		else
			player = NEUTRAL;
		theBot->general.map.updateRegion(noRegion, player, nbArmies);
		if (lineEnds())
			break;
	}
}

void Parser::parseOpponentMoves()
{

	std::string playerName, action;
	unsigned noRegion, toRegion;
	int nbArmies;
	while (std::cin.peek() != '\n' && std::cin >> playerName >> action)
	{
		if (action == "place_armies")
		{
			std::cin >> noRegion >> nbArmies;
			theBot->opponentPlacement(noRegion, nbArmies);
		}
		if (action == "attack/transfer")
		{
			std::cin >> noRegion >> toRegion >> nbArmies;
			theBot->opponentMovement(noRegion, toRegion, nbArmies);
		}
		if (lineEnds())
			break;
	}
}

void Parser::parseGo()
{
	std::string phase;
	int timebank;
	std::cin >> phase >> timebank;
	theBot->setTimebank(timebank);
	if (phase == "place_armies")
	{
		theBot->placeArmies();
		//return;
	}
	if (phase == "attack/transfer")
	{
		theBot->makeMoves();
		//return;
	}
	//throw std::invalid_argument("Cannot handle " + phase + "correctly");
}

void Parser::parseSuperRegions()
{
	unsigned super;
	int reward;
	while (std::cin >> super >> reward)
	{
		theBot->general.map.addSuperRegion(super, reward);
		if (lineEnds())
			break;
	}
}

void Parser::parseRegions()
{
	unsigned super, region;
	while (std::cin >> region >> super)
	{
		theBot->general.map.addRegion(region, super);
		if (lineEnds())
			break;
	}
}

void Parser::parsePickStartingRegion()
{
	int region;
	int delay;
	std::cin >> delay;
	theBot->setTimebank(delay);
	theBot->clearStartingRegions();
	while (std::cin >> region)
	{
		theBot->addStartingRegion(region);
		if (lineEnds())
			break;
	}
}

void Parser::parseOpponentStartingRegions()
{
	unsigned noRegion;
	while (std::cin >> noRegion)
	{
		theBot->addOpponentStartingRegion(noRegion);
		if (lineEnds())
			break;
	}
}

void Parser::parseNeighbors()
{

	unsigned region;
	std::string neighbors;
	std::vector<std::string> neighbors_flds;
	while (std::cin >> region >> neighbors)
	{
		neighbors_flds.clear();
		string::split(neighbors_flds, neighbors);
		for (unsigned i = 0; i < neighbors_flds.size(); i++)
			theBot->general.map.setNeighbors(region, atoi(neighbors_flds[i].c_str()));
		if (lineEnds())
			break;
	}
}

void Parser::parseWastelands()
{
	unsigned region;
	while (std::cin >> region)
	{
		theBot->general.map.setWasteland(region);
		if (lineEnds())
			break;
	}
}
