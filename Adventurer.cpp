//Program name : Adventurer.cpp
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Implementation file for Equipment Class.

#include "Adventurer.h"
#include <iostream>


Adventurer::Adventurer()
{

	//Attack and health range from 10 - 100 (slightly more than Enemies)
	attack = rand() % 90 + 10;
	health = rand() % 90 + 10;
	isOnQuest = false;
	name = generateName();
	equipment[0] = 0;
	equipment[1] = 0;
	equipment[2] = 0;
	calculateAttackBonus();
	calculateHealthBonus();

}


Adventurer::Adventurer(std::string firstAdventurerString)
{
	//Attack and health range from 10 - 100 (slightly more than Enemies)
	attack = 50;
	health = 50;
	isOnQuest = false;
	name = generateName();
	equipment[0] = 0;
	equipment[1] = 0;
	equipment[2] = 0;
	calculateAttackBonus();
	calculateHealthBonus();
}

std::string Adventurer::getName()
{
	return name;
}

int Adventurer::getAttack()
{
	return attack;
}

int Adventurer::getHealth()
{
	return health;
}

int Adventurer::getEquipmentAttackBonus()
{
	return equipmentAttackBonus;
}

int Adventurer::getEquipmentHealthBonus()
{
	return equipmentHealthBonus;
}


//Returns -1 if the Adventurer does not already have equipment of the same type
//Returns 0, 1, or 2 if the Adventurer already has this type of equipment
//The value is the index of the clashing equipment in the Adventurer's Equipment Array
int Adventurer::hasEquipmentType(Equipment equipment)
{
	for (int i = 0; i < 3; i++)
		//If name is not "Nothing Equipped" user will be replacing equipment
		if (this->equipment[static_cast<int>(equipment.getEquipmentType())].getName().std::string::compare("Nothing Equipped") != 0)
			return i;

	return -1;
}


std::string Adventurer::generateName()
{
	std::string name = "";


	std::string nameArray[] = { "Theo", "Cleo", "Sir Knight", "Mr. Hero", "Duke Ellington", "Barack Obama", "Mr. President", "David Majercak", "Nick Cage", 
								"Bruce Lee", "Donkey Kong", "Mario", "Link", "Einstein", "Dude", "Generic Guy", "Iron Man", "Batman", "The Incredibly Hulk", "Harry Potter",
								"Jackie Chan", "Channie Jack, Sworn Enemy of Jackie Chan", "That Guy From That One Movie", "Zoey 101", "Professor Snape", "Bill Nye",
								"Steven Hawking", "Neil deGrasse Tyson", "Zoidberg", "Spongebob Squarepants", "Terry Crews", "Chuck Norris"};

	int random = rand() % (sizeof(nameArray) / sizeof(*nameArray));

	name += nameArray[random] + " : \"";
	
	if ((attack + health) < 50)
		name += "The Meek";
	else if ((attack + health) < 80)
		name += "The Mediocre";
	else if ((attack + health) < 110)
		name += "The Slightly Dependable";
	else if ((attack + health) < 150)
		name += "The Mighty";
	else if ((attack + health) < 180)
		name += "The Demi-God";
	else if ((attack + health) < 195)
		name += "The God";
	else
		name += "The Impeccable";

	name += "\"";
	return name;
}

std::string Adventurer::toString()
{
	std::string temp = "";
	temp += name + "::: Attack: " + std::to_string(attack) + " : Health: " + std::to_string(health) + "\n";

	if (equipment[0].getName().compare("Nothing Equipped") == 0 && equipment[1].getName().compare("Nothing Equipped") == 0 && equipment[2].getName().compare("Nothing Equipped") == 0)
		temp += "No Equipment. They wish you would buy them some...";
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (equipment[i].getName().compare("Nothing Equipped") != 0)
			{
				if (i == 0)
					temp += "Helmet: ";
				else if (i == 1)
					temp += "Body: ";
				else
					temp += "Pants: ";

				temp += equipment[i].toString();
			}
		}
		temp += "Total Stats:::::::::::::::::Total Attack = " + std::to_string(attack + equipmentAttackBonus) + " : Total Health = " + std::to_string(health + equipmentHealthBonus) + "\n";
	}
	return temp;
}

void Adventurer::setEquipment(Equipment newEquipment)
{
	equipment[newEquipment.getEquipmentType()] = newEquipment;

	calculateAttackBonus();
	calculateHealthBonus();
}

void Adventurer::calculateAttackBonus()
{
	equipmentAttackBonus = equipment[0].getAttackBonus() + equipment[1].getAttackBonus() + equipment[2].getAttackBonus();
}

void Adventurer::calculateHealthBonus()
{
	equipmentHealthBonus = equipment[0].getHealthBonus() + equipment[1].getHealthBonus() + equipment[2].getHealthBonus();
}

bool Adventurer::getIsOnQuest()
{
	return isOnQuest;
}

void Adventurer::setIsOnQuest(bool isOnQuest)
{
	this->isOnQuest = isOnQuest;
}

Equipment* Adventurer::getEquipmentSlot(int slot)
{
	return &equipment[slot];
}
