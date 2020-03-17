#pragma once
//2D vector class, similar to ofVec2f for openFrameworks

class Vec2{
public:
	int m_X;	//X coordinate
	int m_Y;	//Y coordinate

	~Vec2();	//destructor
	Vec2();		//default constructor
	Vec2(int x, int y);	//constructor override

	Vec2 operator=(Vec2 val);	// = operator override
	bool operator==(Vec2 val);	//== operator override
};

