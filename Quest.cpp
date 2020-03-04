//Program name : Quest.cpp
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Implementation file for Quest Class.

#include "Quest.h"
#include <iostream> 

Quest::Quest(Enemy* enemy, Adventurer* adventurer)
{
	this->enemy = enemy;
	this->adventurer = adventurer;
}

Enemy Quest::getEnemy()
{
	return *enemy;
}

Adventurer Quest::getAdventurer()
{
	try
	{
		return *adventurer;
	}
	catch (std::bad_alloc)
	{
		std::cout << "Bad Alloc caught.... You should let David know what happened" << std::endl;
	}
}

//Returns true if the adventurer wins and false if the adventurer loses
bool Quest::getHasAdventurerWon()
{
	//Winner is calulated based on totalAttack * totalHealth
	if ((adventurer->getAttack() + adventurer->getEquipmentAttackBonus()) * (adventurer->getHealth() + adventurer->getEquipmentHealthBonus()) >
		enemy->getAttack() * enemy->getHealth())
	{
		//Small chance to lose anyway
		if (rand() % 100 > 90)
			return false;
		else
			return true;
	}
	else
	{
		//Small chance to win anyway
		if (rand() % 100 > 90)
			return true;
		else
			return false;
	}
}

Adventurer* Quest::getAdventurerPtr()
{
	return adventurer;
}

std::string Quest::getChanceToWin()
{
	std::string temp = "";

	if ((adventurer->getAttack() + adventurer->getEquipmentAttackBonus()) * (adventurer->getHealth() + adventurer->getEquipmentHealthBonus()) >
		enemy->getAttack()* enemy->getHealth())
	{
		temp = "GOOD : ";

	}
	else
		temp = "BAD : ";
	temp += adventurer->getName() + "'s total combat value : " + std::to_string((adventurer->getAttack() + adventurer->getEquipmentAttackBonus()) * (adventurer->getHealth() + adventurer->getEquipmentHealthBonus()));
	temp += " :::::: Enemy's total combat value : " + std::to_string(enemy->getAttack() * enemy->getHealth());
	return temp;
}

