#include "ShipSub.h"
//Destructor
Cruiser::~Cruiser(){}
//Default Constructor: sets name of the ship and its size
Cruiser::Cruiser(){
	m_name = "Cruiser";
	m_size = 3;
}
//Sinking Message Override: State what ship was sunk
void Cruiser::sinkMessage() { cout << "Cruiser has sunk"; }


