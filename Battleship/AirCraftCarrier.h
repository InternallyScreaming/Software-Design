#include "Ship.h"
//Aircraft Carrier Child Class
class AirCraftCarrier : public Ship{
public:
	~AirCraftCarrier();	//Destructor
	AirCraftCarrier();	//Default Constructor
	//Inherited Constructor
	AirCraftCarrier(Vec2 initPos, int direction, int size) : Ship(initPos, direction, size){}
	//Override of the Sinking Message from the Ship Base Class
	void sinkMessage()override;
};


