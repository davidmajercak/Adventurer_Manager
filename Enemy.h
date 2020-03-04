//Program name : Enemy.h
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: The Header file for Enemy Class.

#pragma once
#include <string>

class Enemy
{
private:
	int attack;
	int health;
	int goldValue;

public:
	//Default constructor, creates a randomized(name, attack, health) new Enemy
	Enemy();

	int getAttack();

	int getHealth();

	int getGoldValue();

	//Generates a name using a random number and a bank of names
	std::string generateName();

	std::string toString();
};

