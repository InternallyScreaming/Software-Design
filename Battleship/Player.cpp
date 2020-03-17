#include "ShipSub.h"

//destructor
//set the pointers of specific ships to NULL
//delete the pointer
Player::~Player(){
	AircraftCarrier = NULL;
	BattleShip = NULL;
	Sub = NULL;
	Cruise = NULL;
	Destroy = NULL;

	delete AircraftCarrier;
	delete BattleShip;
	delete Sub;
	delete Cruise;
	delete Destroy;
}

//constructor
Player::Player(string Name){

	//create instance for physics class for randomizing boat coordinates
	Physics detection;

	//set the name of the player
	m_name = Name;

	//sets the default of the enemy attacks value to 1
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m_enemyAttacks[i][j] = 1;
		}
	}

	//create new aircraft carrier
	//will only push the ship back into the fleet vector,
	//so long as the ship is not going over the edge and not overlapping another ship
	AircraftCarrier = new AirCraftCarrier(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 5);
	while (detection.boatToAllCollision(m_fleet, *AircraftCarrier) || detection.boatToEdgeCollision(*AircraftCarrier)){
		AircraftCarrier = new AirCraftCarrier(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 5);
	}
	m_fleet.push_back(AircraftCarrier);

	//create new battleship
	//will only push the ship back into the fleet vector,
	//so long as the ship is not going over the edge and not overlapping another ship
	BattleShip = new Battleship(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 4);
	while (detection.boatToAllCollision(m_fleet, *BattleShip) || detection.boatToEdgeCollision(*BattleShip)){
		BattleShip = new Battleship(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 4);
	}
	m_fleet.push_back(BattleShip);

	//create new submarine
	//will only push the ship back into the fleet vector,
	//so long as the ship is not going over the edge and not overlapping another ship
	Sub = new Submarine(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 3);
	while (detection.boatToAllCollision(m_fleet, *Sub) || detection.boatToEdgeCollision(*Sub)){
		Sub = new Submarine(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 3);
	}
	m_fleet.push_back(Sub);

	//create new cruiser
	//will only push the ship back into the fleet vector,
	//so long as the ship is not going over the edge and not overlapping another ship
	Cruise = new Cruiser(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 3);
	while (detection.boatToAllCollision(m_fleet, *Cruise) || detection.boatToEdgeCollision(*Cruise)){
		Cruise = new Cruiser(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 3);
	}
	m_fleet.push_back(Cruise);

	//create new destroyer
	//will only push the ship back into the fleet vector,
	//so long as the ship is not going over the edge and not overlapping another ship
	Destroy = new Destroyer(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 2);
	while (detection.boatToAllCollision(m_fleet, *Destroy) || detection.boatToEdgeCollision(*Destroy)){
		Destroy = new Destroyer(Vec2(randomizeCoordinates(), randomizeCoordinates()), randomizeOrientation(), 2);
	}
	m_fleet.push_back(Destroy);

	//destroy instance of the physics class
	detection.~Physics();
}
//randomizes between 1-4, randomizes the orientation of the boat
int Player::randomizeOrientation() {
	int num = rand() % 4 + 1;
	return num;
}

//randomizes between 1-10, randomzes one of the coordinates of the boats
int Player::randomizeCoordinates() {
	int num = rand() % 10;
	return num;
}

//gets the name of the ship
string Player::GetName() {
	return m_name; 
}

//Checks the player's choice history against their current choice
//returns true if the current choice they are trying to make has already been
//done by the player
bool Player::checkChoices(Player playerChoices, Vec2 currentChoice) {
	for(unsigned int i = 0; i < playerChoices.m_playerChoices.size(); i++) {
		if (playerChoices.m_playerChoices[i] == currentChoice) { return true; }
	}
	return false;
}

