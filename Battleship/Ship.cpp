#pragma once
#include "Ship.h"

//different orientations that a ship's last position is compared to the initial position
enum Axis {
	NORTH = 1,
	SOUTH,
	EAST,
	WEST
};

Ship::~Ship(){}	//destructor
Ship::Ship(){}	//default constructor

//Main constructor
Ship::Ship(Vec2 initPos, int direction, int size) {
	//push back the initial position of the boat
	m_boatPos.push_back(initPos);
	//set the size to the size of the boat
	m_size = size;
	//set the health to the size of the boat
	m_health = m_size;

	//push back the coordinates of the other positions on the boat
	//into an array
	for (int i = 1; i < size; i++) {
		switch (direction) {
		case NORTH:
			m_boatPos.push_back(Vec2((m_boatPos[i - 1].m_X), (m_boatPos[i - 1].m_Y - 1)));
			break;
		case SOUTH:
			m_boatPos.push_back(Vec2((m_boatPos[i - 1].m_X), (m_boatPos[i - 1].m_Y + 1)));
			break;
		case EAST:
			m_boatPos.push_back(Vec2((m_boatPos[i - 1].m_X + 1), (m_boatPos[i - 1].m_Y)));
			break;
		case WEST:
			m_boatPos.push_back(Vec2((m_boatPos[i - 1].m_X - 1), (m_boatPos[i - 1].m_Y)));
			break;
		}
	}
}

string Ship::GetName() { return m_name; }				//get name of ship
int Ship::GetSize() { return m_size;  }					//get size of ship
int Ship::GetHealth() { return m_health; }				//get health of ship
void Ship::SetHealth(int health) { m_health = health; }	//set health of ship