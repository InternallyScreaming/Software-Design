#include "Ship.h"
//Submarine Child Class
class Submarine : public Ship{
public:
	~Submarine();	//Destructor
	Submarine();	//Default Constructor
	//Inherited Constructor
	Submarine(Vec2 initPos, int direction, int size) : Ship(initPos, direction, size) {}
	//Override of the Sinking Message from the Ship Base Class
	void sinkMessage()override;
};

