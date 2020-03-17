#include "ShipSub.h"

//Destructor
Submarine::~Submarine(){}
//Default Constructor: sets name of the ship and its size
Submarine::Submarine(){
	m_name = "Submarine";
	m_size = 3;
}
//Sinking Message Override: State what ship was sunk
void Submarine::sinkMessage() { cout << "Submarine has sunk"; }



