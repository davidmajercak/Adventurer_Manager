//Program name : Adventurer.h
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Header file for Adventurer Class.

#pragma once
#include <string>
#include "Equipment.h"

class Adventurer
{
private:
	std::string name;			
	int attack;
	int health;
	int equipmentAttackBonus;		//The bonus to attack from equipment
	int equipmentHealthBonus;		//The bonus to health from equipment
	Equipment equipment[3];			//Array of Equipment					
	std::string lastQuestName;		//The name of the last quest the Adventurer completed
	bool isOnQuest;


public:
	//Default constructor, creates a randomized(name, attack, health) new adventurer
	Adventurer();

	//Creating the first adventurer to have set stats of 50 health and 50 attack
	//all further adventurers have randomized stats
	Adventurer(std::string firstAdventurerString);
	
	//Returns the name of the adventurer
	std::string getName();

	//Returns the attack of the adventurer
	int getAttack();

	//Returns the health of the adventurer
	int getHealth();

	//Returns the bonus provided by the adventurer's equipment
	int getEquipmentAttackBonus();

	//Returns the bonus provided by the adventurer's equipment
	int getEquipmentHealthBonus();

	//Returns -1 if the adventurer does not yet have equipment in the same equipment slot the passed in equipment would go in
	//Returns 0, 1, or 2 based on the conflicting equipment type
	int hasEquipmentType(Equipment equipment);

	//Generates a random name for adventurer's
	std::string generateName();

	//Returns a string representation of adventurer
	std::string toString();

	//Sets the passed in equipment into the appropriate slot for the adventurer
	void setEquipment(Equipment newEquipment);

	//Updates the value of the attack bonus provided by equipment
	void calculateAttackBonus();

	//Updates the value of health bonus provided by equipment
	void calculateHealthBonus();
	
	bool getIsOnQuest();

	void setIsOnQuest(bool isOnQuest);

	//Returns the equipment in the passed in equipment slot
	Equipment* getEquipmentSlot(int slot);
};

