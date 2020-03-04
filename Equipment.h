//Program name : Equipment.h
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Header file for Equipment Class.

#pragma once
#include <string>

class Equipment
{
private:
	//There are only 3 possible equipment types
	enum class equipmentType
	{
		HEAD = 0, BODY = 1, PANTS = 2
	};


	std::string name;
	int attackBonus;
	int healthBonus;
	equipmentType type;



public:
	//Default constructor generates a random equipment 
	Equipment();

	//This constructor sets equipment to no equipment
	Equipment(int zero);

	//Generates a random equipment with the specified type
	Equipment(equipmentType type);

	std::string getName();

	int getAttackBonus();

	int getHealthBonus();

	int getEquipmentType();

	std::string generateName();

	//Uses rand to generate a random equipment type
	equipmentType generateEquipmentType();

	//Generates a bonus for either attack or health (from 1 to 100)
	int generateBonusValue();

	std::string toString();

};

