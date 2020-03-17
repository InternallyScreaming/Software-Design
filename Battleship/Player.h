#pragma once
#include "Ship.h"

//Class for the players
class Player {
protected:
	string m_name;

	int randomizeOrientation();		//Randomizes the orientation of the player's boats
	int randomizeCoordinates();		//Randomizes the coordinates of the player's boats
public:
	int m_enemyAttacks[10][10];		//The enemy's attack coordinates against the player
	char m_playerBoard[10][10];		//The player's board
	vector<Ship*> m_fleet;			//The player's boats
	vector<Vec2> m_playerChoices;	//The player's choice history

	//One of each boat, this is needed for the sinking message
	Ship * AircraftCarrier;
	Ship * BattleShip;
	Ship * Sub;
	Ship * Cruise;
	Ship * Destroy;

	//constructors and destructors
	~Player();
	Player(string Name);

	string GetName();	//Gets the name of the player
	//Checks the player's choice history against their current choice
	//returns true if the current choice they are trying to make has already been
	//done by the player
	bool checkChoices(Player playerChoices, Vec2 currentChoice); 
};

