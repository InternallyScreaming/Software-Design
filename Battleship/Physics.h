#pragma once
#include "Ship.h"

class Physics{
public:
	~Physics();	//constuctor
	Physics();	//destructor

	bool checkX(int input); //checks for a valid x coordinate input
	bool checkY(char input);//checks for a valid y coordinate input

	//checks if a boat is overlapping another boat
	//only called by boatToAllCollision
	bool boatToBoatCollision(Ship * Ship1, Ship * Ship2, Vec2 &Coor);

	//checks if a boat is overlapping with all boats
	//calls boatToBoatCollision
	bool boatToAllCollision(vector<Ship*>& fleet, Ship & ship);

	//Checks if a boat is going over the edge
	bool boatToEdgeCollision(Ship & Ship);

	//checks if a boat was hit by an attack
	//calls attackToAllCollision
	bool attackToBoatCollision(Ship & Ship, int X, int Y);

	//checks if any boats were hit by an attack
	//calls attackToBoatCollision
	bool attackToAllCollision(vector<Ship*>& fleet, int X, int Y);

	//checks if a boat was sunk
	//called independently and by confirmAllSink
	bool confirmBoatSink(Ship & Ship);

	//checks if all boats were sunk
	//calls confirmBoatSink
	bool confirmAllSink(vector<Ship*> & fleet);
};

