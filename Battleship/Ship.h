#pragma once
#include "ShipMain.h"
//Ship Base Class
class Ship{
protected:
	string m_name;	//name of the ship
	int m_size;		//size of the ship
	int m_health;	//health of the ship. =to size. Can be deducted
	int m_X;		//Ship's X position
	int m_Y;		//Ship's Y position

public:
	vector<Vec2> m_boatPos;	//position of all sections of a ship

	~Ship();										//destructor
	Ship();											//default constructor
	Ship(Vec2 initPos, int direction, int size);	//main constructor

	string GetName();				//get name of ship
	int GetSize();					//get size of ship
	int GetHealth();				//get health of ship
	void SetHealth(int health);		//set health of ship
	virtual void sinkMessage()=0;	//sinking message of ship, requires to be overrode by child class
};




