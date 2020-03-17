#pragma once
#include "ShipSub.h"

Physics::~Physics(){}	//constuctor
Physics::Physics() {}	//destructor

//will only allow a player to input a value between 0-9
bool Physics::checkX(int input) {
	for (unsigned int i = 0; i < 10; i++) {
		if (input == i) { return false; }
	}
	return true;
}

//will only allow a player to input a value between a-j, lowercase or caps
bool Physics::checkY(char input) {
	for (unsigned int i = 65; i < 75; i++) {
		if (input == (char)i) { return false; }
	}
	for (unsigned int i = 97; i < 107; i++) {
		if (input == (char)i) { return false; }
	}
	return true;
}

//checks if two boats' section's coordinates equal one another
bool Physics::boatToBoatCollision(Ship * Ship1, Ship * Ship2, Vec2 &Coor) {
	for (int i = 0; i < Ship1->GetSize(); i++) {
		for (int j = 0; j < Ship2->GetSize(); j++) {
			if (Ship1->m_boatPos[i] == Ship2->m_boatPos[j]) {
				Coor = Ship1->m_boatPos[i];
				return true;
			}
		}
	}
	return false;
}

//checks if any two boats are overlapping one another
//does this by looping a new boat against all created boats 
//and checks by using the boatToBoatCollision
bool Physics::boatToAllCollision(vector<Ship*>& fleet, Ship & ship) {
	Vec2 collisionlocation;
	for (unsigned int i = 0; i < fleet.size(); i++) {
		if (boatToBoatCollision(fleet[i], &ship, collisionlocation)) {
			return true;
		}
	}
	return false;
}

//checks if any of the boat's sections is going over the edge
bool Physics::boatToEdgeCollision(Ship & Ship) { 
	for (int i = 0; i < Ship.GetSize(); i++) {
		if (Ship.m_boatPos[i].m_X < 0 || Ship.m_boatPos[i].m_Y < 0 || Ship.m_boatPos[i].m_X > 9 || Ship.m_boatPos[i].m_Y > 9) {
			return true;
		}
	}
	return false;
}

//checks if a boat was hit by an attack
//does this by looping the attack position against all positions on a singular boat
bool Physics::attackToBoatCollision(Ship & Ship, int X, int Y) { 
	int currentHealth = Ship.GetHealth();
	for (int i = 0; i < Ship.GetSize(); i++) {
		if (Ship.m_boatPos[i].m_X == X && Ship.m_boatPos[i].m_Y == Y) {
			currentHealth--;
			Ship.SetHealth(currentHealth);
			return true;
		}
	}
	return false;
}

//checks if any boats were hit by an attack
//does this by looping the attack position against all boat positions 
//and checks by using the attackToBoatCollision
bool Physics::attackToAllCollision(vector<Ship*>& fleet, int X, int Y) {
	for (int i = 0; i < fleet.size(); i++) {
		if (attackToBoatCollision(*fleet[i], X, Y)) { return true; }
	}
	return false;
}

//checks if a boat's health is 0
bool Physics::confirmBoatSink(Ship & Ship) {
	if (Ship.GetHealth() <= 0) { return true; }
	return false;
}

//checks if all boat's health is 0
//does this by calling confirmBoatSink in a loop and checking
//each boat's health in a fleet
bool Physics::confirmAllSink(vector<Ship*> & fleet) {
	for (int i = 0; i < fleet.size(); i++) {
		if (confirmBoatSink(*fleet[i]) == false) { return false; }
	}
	return true;
}