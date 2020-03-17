#include "ShipSub.h"
//Destructor
Destroyer::~Destroyer(){}
//Default Constructor: sets name of the ship and its size
Destroyer::Destroyer(){
	m_name = "Destroyer";
	m_size = 2;
}
//Sinking Message Override: State what ship was sunk
void Destroyer::sinkMessage() { cout << "Destroyer has sunk"; }



