#include "Ship.h"
//Battleship Child Class
class Battleship : public Ship{
public:
	~Battleship();	//Destructor
	Battleship();	//Default Constructor
	//Inherited Constructor
	Battleship(Vec2 initPos, int direction, int size) : Ship(initPos, direction, size) {}
	//Override of the Sinking Message from the Ship Base Class
	void sinkMessage()override;
};

