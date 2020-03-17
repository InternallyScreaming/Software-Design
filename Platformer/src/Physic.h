//The physics class of the program
#pragma once
#include "Main.h"

class Physic{
public:
	Physic();	//constructor
	~Physic();	//destructor

	int ground;				//the y value that the player walks on
	ofImage heightMap;		//the height map/navigation map
	ofColor playerLevel;	//the color of the background that player character's
							//pivot is on

	void Forward(AnimatedObject* player);		//moves player forward
	void Backwards(AnimatedObject* player);		//moves player backward
	int GetGround(int X);						//calculates the color value that the player character is on, returns the y value of the walkable ground
	void Jump(AnimatedObject* player);			//makes player jump
};