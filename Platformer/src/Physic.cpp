//Physics class
#include "Main.h"

///////////////////////////////////////////////////////////////////////
//Upon creating an instance of the physics class,
//load in the heightmap
//this is the same image as the background image, but 
//would remain the same if the shown background image
//was more detailed
Physic::Physic(){
	heightMap.load("images/Background.png");
}

///////////////////////////////////////////////////////////////////////
//public destructor
Physic::~Physic(){}

///////////////////////////////////////////////////////////////////////
//moves the player forward
//sets the player's x value to equal itself plus the player's speed
//sets the player's y value to equal the ground they are standing
void Physic::Forward(AnimatedObject* player) {
	player->x += PLAYER_SPEED;
	player->y = GetGround(player->x);
}

///////////////////////////////////////////////////////////////////////
//if the player's x value is greater or equal to 0
//move the player backwards
//sets the player's x value to equal itself minus the player's speed
//sets the player's y value to equal the ground they are standing
void Physic::Backwards(AnimatedObject* player) {
	if (player->x >= 0) {
		player->x -= PLAYER_SPEED;
		player->y = GetGround(player->x);
	}
}

//////////////////////////////////////////////////////////////////////
//gets the y value of the ground where the player is standing
int Physic::GetGround(int X) {
	//variable to hold the value of white
	ofColor White = ofColor::white;

	//loop through all the values of Y
	for (int y = 0; y < 800; y++) {
		//gets the pixel bytes of the all the y pixels in the x coordinate of the player
		//obtained from SBI color tracker assignment
		int index = (X + y * heightMap.getWidth()) * heightMap.getPixels().getBytesPerPixel();

		//assigns the r,g,b values of the pixel that is currently being scanned. 
		playerLevel.r = heightMap.getPixels()[index + 0];
		playerLevel.g = heightMap.getPixels()[index + 1];
		playerLevel.b = heightMap.getPixels()[index + 2];

		//once there is a white pixel detected	
		//return the y value of that white pixel
		if (playerLevel == White) {
			return y;
		}
	}
}

/////////////////////////////////////////////////////////////////////
//makes the player jump
//supplied from the assignment 03.docx
void Physic::Jump(AnimatedObject* player) {
	//if the player's jump is equal to true
	if (player->jump == true) {
		//moves the character verically
		player->y = player->y0 - JUMP_SPEED * player->t+ 0.5 * GRAVITY * player->t*player->t;
		//advance time
		player->t++;
		//moves the character slightly forward
		player->x += 2;

		//reached the ground?
		//get the y value of the ground at player's x position
		ground = GetGround(player->x);
		//if the player y value is greater than the ground's y value
		//set's player's y value to the ground
		//and the jump to false
		if (player->y > ground){
			player->y = ground;
			player->jump = false;
		}
	}
	//see if we have walked off a cliff and have to fall
	else {
		//if the player's y value is less than the ground
		//set the player's jump to true
		if (player->y < ground) {
			player->jump = true;
		}
	}

}