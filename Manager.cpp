//Program name : Manager.cpp
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Implementation file for Manager Class.


#include "Manager.h"

//Default Constructor gives default name and gives the Manager one adventurer
Manager::Manager()
{
	adventurersList.push_back(Adventurer("First Adventurer"));
	
	name = "The nameless Manager";
	gold = 50;
}

//Sets name to passed in name and gives Manager one adventurer
Manager::Manager(std::string name)
{
	adventurersList.push_back(Adventurer("First Adventurer"));
	this->name = name;


	//Edit this number to be able to test having large number of adventurers, items, etc
	gold = 50;
}

std::string Manager::getName()
{
	return name;
}

std::vector<Adventurer> Manager::getAdventurersList()
{
	return adventurersList;
}

Adventurer* Manager::getAdventurerPtrAt(int i)
{
	return &adventurersList[i];
}

std::vector<Quest>& Manager::getQuestList()
{
	return questList;
}

int Manager::getGold()
{
	return gold;
}

void Manager::addGold(int gold)
{
	this->gold += gold;
}

void Manager::subtractGold(int gold)
{
	this->gold -= gold;
}

void Manager::addQuest(Enemy* enemyPtr, Adventurer* adventurerPtr)
{
	questList.push_back(Quest(enemyPtr, adventurerPtr));
}

void Manager::removeQuest(int i)
{

	if (questList.size() == 1)
		questList.clear();
	else
	{
		std::swap(questList[i], questList.back());
		questList.pop_back();
	}

}

Quest* Manager::getQuestListPtr()
{
	return &questList[0];
}

void Manager::recruitNewAdventurer()
{
	adventurersList.push_back(Adventurer());
}
