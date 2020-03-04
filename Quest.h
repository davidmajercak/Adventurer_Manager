//Program name : Quest.h
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Header file for Quest Class.

#pragma once
#include <string>
#include "Adventurer.h"
#include "Enemy.h"

class Quest
{
private:
	Enemy* enemy;
	Adventurer* adventurer;

public:
	//No default constructor since Quest needs an Enemy and an Adventurer
	Quest(Enemy* enemy, Adventurer* adventurer);

	Enemy getEnemy();

	Adventurer getAdventurer();

	bool getHasAdventurerWon();

	Adventurer* getAdventurerPtr();

	std::string getChanceToWin();
};

