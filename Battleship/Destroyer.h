#include "Ship.h"
//Destroyer Child Class
class Destroyer : public Ship{
public:
	~Destroyer();	//Destructor
	Destroyer();	//Default Constructor
	//Inherited Constructor
	Destroyer(Vec2 initPos, int direction, int size) : Ship(initPos, direction, size) {}
	//Override of the Sinking Message from the Ship Base Class
	void sinkMessage()override;
};

