//Program name : Adventurer_Manager.cpp
//Author: David Majercak
//Date last updated: 12/22/2019
//Purpose: This is the main file for the Adventurer_Manager Program


#include <iostream>
#include "Adventurer.h"
#include "Enemy.h"
#include "Quest.h"
#include "Manager.h"
#include <time.h>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	srand(time(NULL));
	
	cout << "This program allows you to manage adventurers." << endl;
	cout << "You can manage their equipment and send them on quests." << endl;

	cout << "What is your name? : " << endl;
	string managerName;
	getline(cin, managerName);

	Manager manager = Manager(managerName);
	int choice;
	cout << "\nHey " << managerName << "!" << endl;
	cout << "You've managed adventurers before, right?" << endl;
	cout << "There's a lot of adventurers around here that really need someone to manage them." << endl;
	cout << "Oh look, here's another one of those hopeless almost heroes." << endl;
	cout << "Hey " << manager.getAdventurersList().at(0).getName() << ", get over here!" << endl;
	cout << "Let " << managerName << " boss you around for awhile.\n" << endl;


	int nextAdventurerHireCost = 50;
	bool keepPlaying = true;
	std::vector<Quest>::iterator it;

	//This is the main loop of the game
	while (keepPlaying)
	{

		//This for loop allows you to take an action for each Adventure that you have
		//You can either send them on a quest, purchase equipment, or hire a new Adventurer
		for (unsigned int i = 0; i < manager.getAdventurersList().size(); i++)
		{

			//No action if this adventurer is still on a quest
			if (manager.getAdventurersList().at(i).getIsOnQuest())
			{
				//Skip turn until done with quest
				continue;
			}

			cout << manager.getAdventurersList().at(i).getName() << "'s Turn"  << " (Adventurer #" << (i + 1) << ")" << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
			cout << "What would you like to do with " << manager.getAdventurersList().at(i).getName() << " ?" << endl;
			cout << "Enter [1] to send them on a quest.  Enter [2] to change equipment. Enter [3] to buy another adventurer. Enter [0] to quit." << endl;

			//This loop errors checks user input.  They must enter either 1 or 2
			while (!(cin >> choice) || choice > 3 || choice < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Enter [1] to send them on a quest.  Enter [2] to change equipment. Enter [3] to buy another adventurer. Enter [0] to quit." << endl;
			}
			//If User wants to send this adventurer on a quest
			if (choice == 1)
			{
				Enemy nextEnemy = Enemy();
				manager.addQuest(&nextEnemy, manager.getAdventurerPtrAt(i));

				manager.getAdventurerPtrAt(i)->setIsOnQuest(true);
			}
			//If user wants to buy equipment for the current Adventurer
			else if (choice == 2)
			{
				//Generating a new random equipment to sell
				Equipment tempEquipment = Equipment();

				cout << "A traveling merchant is selling: " << tempEquipment.toString() << endl;
				cout << "The merchant will sell for: " << (tempEquipment.getAttackBonus() + tempEquipment.getHealthBonus()) * 2 << endl;
				cout << "You have: " << manager.getGold() << endl;

				cout << "Enter [1] if you want to buy. Enter [2] if you would like to ignore the merchant." << endl;

				cout << "Equipment type to int value " << to_string(tempEquipment.getEquipmentType()) << endl;

				//Validating user input
				while (!(cin >> choice) || choice > 2 || choice < 1)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "Enter [1] if you want to buy. Enter [2] if you would like to ignore the merchant" << endl;
				}
				//If User chooses to buy the equipment and has enough gold
				if (choice == 1 && manager.getGold() > (tempEquipment.getAttackBonus() + tempEquipment.getHealthBonus()) * 2)
				{
					
					//If user already has equipment in that slot (confirm want to replace equipment)
					if (manager.getAdventurerPtrAt(i)->hasEquipmentType(tempEquipment) != -1)
					{
						cout << "You already have equipment in this equipment slot: " << manager.getAdventurerPtrAt(i)->
							getEquipmentSlot(manager.getAdventurerPtrAt(i)->hasEquipmentType(tempEquipment))->toString() << endl;
						cout << "Are you sure you want to replace that equipment?" << endl;
						cout << "Enter [1] if you want to replace your equipment. Enter [2] if you would like to keep your current equipment and continue." << endl;

						while (!(cin >> choice) || choice > 2 || choice < 1)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							cout << "Enter [1] if you want to replace your equipment. Enter [2] if you would like to keep your current equipment and continue." << endl;
						}
						//If user wants to keep current equipment
						//		Continues to next Adventurer
						if (choice == 2)
						{
							continue;
						}
						//Continue to replace equipment otherwise
					}

					
					manager.subtractGold(tempEquipment.getAttackBonus() + tempEquipment.getHealthBonus() * 2);

					manager.getAdventurerPtrAt(i)->setEquipment(tempEquipment);

					cout << "Here are " << manager.getAdventurersList().at(i).getName() << "'s new stats: \n" << endl;
					cout << manager.getAdventurersList().at(i).toString() << endl;


				}
				//If User chooses to buy equipment but does not have enough gold
				else if (choice == 1 && manager.getGold() < (tempEquipment.getAttackBonus() + tempEquipment.getHealthBonus()) * 2)
				{
					cout << "You don't have enough gold to buy that. Sorry!" << endl;
				}
				//If user does not want to buy that equipment
				else
				{
					cout << manager.getAdventurersList().at(i).getName() << " continues onward... " << endl;
				}

			}
			//If user wants to hire a new adventurer
			else if (choice == 3)
			{
				if (manager.getGold() >= static_cast<int>(nextAdventurerHireCost))
				{
					cout << "You head to the tavern and give " + to_string(nextAdventurerHireCost) + " gold to a stranger..." << endl;

					manager.subtractGold(nextAdventurerHireCost);

					//70% chance for the Adventurer to join you
					if (rand() % 10 >= 3)
					{
						manager.recruitNewAdventurer();
						cout << manager.getAdventurersList().back().getName() << " agrees to listen to you until you stop playing this game." << endl;
						//Increasing next hire cost each time user hires another Adventurer
						nextAdventurerHireCost = static_cast<int>(nextAdventurerHireCost * 1.5);
						cout << "All of your adventurers gathered to celebrate the new hire!" << endl;
						cout << "All of your adventurers now gain additional gold from enemies!" << endl;

						//The program was crashing when adding an adventurer when currently selecting an action for your current last adventurer
						//I discovered that this was because I was using pointers to the Adventurer's in quest list
						//However, resizing the vector was causing the vector to be moved in memory
						//This meant that my pointers were no longer valid in the second half of the major game loop
						//I like this solution since it fits thematically with the game and the increased gold that you earn
						//I would probably use a different data structure in the future, maybe a linked list?
						manager.getQuestList().clear();
					}
					else
					{
						cout << "You probably should have asked them to join you instead of just giving away your money..." << endl;
					}

				}
				else
				{
					cout << "You don't have enough gold to hire another adventurer." << endl;
					cout << "You need " << to_string(nextAdventurerHireCost) << " gold to hire your next adventurer." << endl;
					continue;
				}
			}
			//If user wants to quit
			else if (choice == 0)
			{
				cout << "Thanks for playing " << managerName << "!" << endl;
				keepPlaying = false;
				break;
			}
		}
		//Skipping second loop if user Quits
		if (!keepPlaying)
			break;

		//Using an iterator to iterator through questList
		it = manager.getQuestList().begin();
		while(it != manager.getQuestList().end())
		{
			//50% chance to return from quest
			if (rand() % 2 == 0)
			{
				cout << it->getAdventurer().getName() << " has returned from their quest!!!<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n" << endl;
				cout << "They tell you how it went..." << endl;
				cout << it->getAdventurer().toString();
				cout << "\n------" << endl;
				cout << "VERSUS     -----     " << it->getAdventurer().getName() << "'s chances of winning: " << it->getChanceToWin() << endl;
				cout << "------" << endl;
				cout << it->getEnemy().toString() << endl;

				if (it->getHasAdventurerWon())
				{
					cout << it->getAdventurer().getName() << "  won!" << endl;

					//Added a 33% multiplier to gold earned for each adventurer hired after the first, to add incentive to hire more adventurers
					manager.addGold(static_cast<int>(it->getEnemy().getGoldValue() + it->getEnemy().getGoldValue() * (manager.getAdventurersList().size() - 1) * 0.34));
					cout << "You gained " << static_cast<int>(it->getEnemy().getGoldValue() + it->getEnemy().getGoldValue() * (manager.getAdventurersList().size() - 1) * 0.34) << " gold!" << endl;
					cout << "Your total gold is now: " << manager.getGold() << endl;
				}
				else
				{
					cout << it->getAdventurer().getName() << "  lost the battle. Better luck next time!" << endl;
				}

				//Setting isOnQuest bool to false
				it->getAdventurerPtr()->setIsOnQuest(false);

				cout << it->getAdventurer().getName() << " is now ready for another quest.\n" << endl;

				it = manager.getQuestList().erase(it);
			}
			else
			{

				cout << it->getAdventurer().getName() << " is adventuring..." << endl;

				//This causes little pauses (1 second) to simulate adventuring
				//Also avoids flooding the screen with text so quickly
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
		
	}
}
