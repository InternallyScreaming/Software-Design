#include "ShipSub.h"
//Destructor
Battleship::~Battleship(){}
//Default Constructor: sets name of the ship and its size
Battleship::Battleship(){
	m_name = "Battleship";
	m_size = 4;
}
//Sinking Message Override: State what ship was sunk
void Battleship::sinkMessage() { cout << "Battleship has sunk"; }



