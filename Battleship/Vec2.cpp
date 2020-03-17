#include "Vec2.h"

//Destructor
Vec2::~Vec2(){}

//sets x and y to 0, if no value is inputted
Vec2::Vec2(){
	m_X = 0;
	m_Y = 0;
}	

//sets x an y to inputted values upon the creation of an instance
Vec2::Vec2(int x, int y) {
	m_X = x;
	m_Y = y;
}	

//sets the X and Y values of a Vec2 to another Vec2 variable
Vec2 Vec2::operator=(Vec2 val) {
	m_X = val.m_X;
	m_Y = val.m_Y;
	return *this;
}

//compares the X and Y values of two Vec2 variables at the same time
bool Vec2::operator==(Vec2 val) {
	if (m_X == val.m_X && m_Y == val.m_Y) {
		return true;
	}
	return false;
}