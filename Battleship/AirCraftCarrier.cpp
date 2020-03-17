#include "ShipSub.h"
//Destructor
AirCraftCarrier::~AirCraftCarrier(){}
//Default Constructor: sets name of the ship and its size
AirCraftCarrier::AirCraftCarrier(){
	m_name = "Aircraft Carrier";
	m_size = 5;
}
//Sinking Message Override: State what ship was sunk
void AirCraftCarrier::sinkMessage(){ cout << "Aircraft Carrier has sunk"; }


