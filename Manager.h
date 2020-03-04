//Program name : Manager.h
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Header file for Manager Class.

#pragma once
#include <vector>
#include "Adventurer.h"
#include "Quest.h"

class Manager
{
private:
	std::vector<Adventurer> adventurersList;
	std::string name;
	int gold;
	std::vector<Quest> questList;

public:
	Manager();

	Manager(std::string name);

	std::string getName();

	std::vector<Adventurer> getAdventurersList();

	Adventurer* getAdventurerPtrAt(int i);


	std::vector<Quest>& getQuestList();

	int getGold();

	void addGold(int gold);

	void subtractGold(int gold);

	void addQuest(Enemy* enemyPtr, Adventurer* adventurerPtr);

	void removeQuest(int i);

	Quest* getQuestListPtr();

	void recruitNewAdventurer();
};

