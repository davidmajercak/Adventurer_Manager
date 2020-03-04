//Program name : Enemy.cpp
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Implementation file for Enemy Class.

#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
	//Attack and health range from 10 - 90 (slightly less than Adventurers)
	attack = rand() % 80 + 10;
	health = rand() % 80 + 10;

	//Gold value is directly proportional to attack and health
	//Ranges from 5 - 45
	goldValue = ((attack + health) / 4);
}

int Enemy::getAttack()
{
	return attack;
}

int Enemy::getHealth()
{
	return health;
}

int Enemy::getGoldValue()
{
	return goldValue;
}

std::string Enemy::generateName()
{
	std::string name = "";

	if ((attack + health) < 50)
		name += "Mouse : ";
	else if ((attack + health) < 80)
		name += "Goblin : ";
	else if ((attack + health) < 110)
		name += "Ogre : ";
	else if ((attack + health) < 150)
		name += "Demon : ";
	else
		name += "Arch Demon : ";

	name += "\"";

	std::string nameArray[] = {"Chad", "Evil McEvilson", "Bruce", "The Killinator", "The Crushinator", "Killer", "Champ", "Monster McMonsterFace", "The Boogeyman", "The Abominable",
						"Destroyer of Adventurers", "Wolf", "Professor Chaos", "Embodiment of Evil", "Really Scary Monster Guy", "Fez", "Taylor Swift", "Jimmy Neutron", "Colonel Sanders",
						"The Grinch", "Larry the Lobster", "Bubble Bass", "Johnny", "Jack Nicholson", "The Joker", "Family Guy", "Celine Dion", "Cher", "Your Neighbor", "Elvis",
						"An Egg Salad Sandwich", "Johnny Bravo"};

	int random = rand() % (sizeof(nameArray) / sizeof(*nameArray));
	name += nameArray[random];
	name += "\"";
	return name;
}

std::string Enemy::toString()
{
	return generateName() + "::: Attack: " + std::to_string(attack) + " : Health: " + std::to_string(health) + " : Gold Value: " + std::to_string(goldValue);
}
