//Program name : Equipment.cpp
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Implementation file for Equipment Class.

#include "Equipment.h"

//Creates equipment of random type with 50% chance to give bonus attack and 50% chance to give bonus health
Equipment::Equipment()
{
	type = generateEquipmentType();

	if (rand() % 2 == 0)
	{
		attackBonus = generateBonusValue();
		healthBonus = 0;
	}
	else
	{
		healthBonus = generateBonusValue();
		attackBonus = 0;
	}

	name = generateName();
	
}

Equipment::Equipment(int zero)
{
	attackBonus = 0;
	healthBonus = 0;
	name = "Nothing Equipped";
	type = Equipment::equipmentType::BODY;
}

Equipment::Equipment(equipmentType type)
{
	this->type = type;

	if (rand() % 2 == 0)
	{
		attackBonus = generateBonusValue();
		healthBonus = 0;
	}
	else
	{
		healthBonus = generateBonusValue();
		attackBonus = 0;
	}

	name = generateName();

}

std::string Equipment::getName()
{
	return name;
}

int Equipment::getAttackBonus()
{
	return attackBonus;
}

int Equipment::getHealthBonus()
{
	return healthBonus;
}

int Equipment::getEquipmentType()
{
	if (type == Equipment::equipmentType::HEAD)
		return 0;
	else if (type == Equipment::equipmentType::BODY)
		return 1;
	else
		return 2;
}

std::string Equipment::generateName()
{
	std::string name = "";

	if (static_cast<int>(type) == 0)
		name += "Helm of ";
	else if (static_cast<int>(type) == 1)
		name += "Armor of ";
	else
		name += "Pants of ";

	int greaterStat;

	if (attackBonus > 0)
		greaterStat = attackBonus;
	else
		greaterStat = healthBonus;

	if (greaterStat < 10)
		name += "hardly any ";
	else if (greaterStat < 20)
		name += "a little ";
	else if (greaterStat < 30)
		name += "minor ";
	else if (greaterStat < 40)
		name += "some ";
	else if (greaterStat < 50)
		name += "moderate ";
	else if (greaterStat < 60)
		name += "above average ";
	else if (greaterStat < 70)
		name += "considerable ";
	else if (greaterStat < 80)
		name += "major ";
	else if (greaterStat < 90)
		name += "incredible ";
	else if (greaterStat < 99)
		name += "extreme ";
	else
		name += "paramount ";

	if (attackBonus > 0)
		name += "attack";
	else
		name += "health";

	return name;
}

//Generates a random type for the equipment
Equipment::equipmentType Equipment::generateEquipmentType()
{
	int random = rand() % 3;

	if (random == 0)
		return Equipment::equipmentType::HEAD;
	else if (random == 1)
		return Equipment::equipmentType::BODY;
	else
		Equipment::equipmentType::PANTS;
}

//Generates a random bonus value for attack or health from 1 to 100
int Equipment::generateBonusValue()
{
	return rand() % 99 + 1;
}

std::string Equipment::toString()
{
	if (name.compare("Nothing Equipped") == 0)
		return name;
	else 
		return name + " \n\tAttack Bonus : " + std::to_string(attackBonus) + " : Health Bonus : " + std::to_string(healthBonus) + "\n";
}
