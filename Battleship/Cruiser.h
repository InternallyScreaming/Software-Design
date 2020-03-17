#include "Ship.h"
//Cruiser Child Class
class Cruiser : public Ship {
public:
	~Cruiser();	//Destructor
	Cruiser();	//Default Constructor
	//Inherited Constructor
	Cruiser(Vec2 initPos, int direction, int size) : Ship(initPos, direction, size) {}
	//Override of the Sinking Message from the Ship Base Class
	void sinkMessage()override;
};

