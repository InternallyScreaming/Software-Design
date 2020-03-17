// OfGameObject version 2 was used as a base
#include "Main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//resize the window
	ofSetWindowShape(1500, 800);

	//load in image
	bgImage.load("images/Background.png");
	
	//player's starting coordinates
	player.x = 110;
	player.y = 663;

	//NOTE: I made my own character sprite, but it is stationary.
	//Because the animate object class is heavily integrated into
	//the ofGameObject file, I just set the frames to one and load my image
	//into the single frame.
	//load in image into the animation array
	player.GetImage()->load("images/player.png");
	//set the number of frames for the animated character
	player.SetNumFrames(1);
	//load in the image into the frame
	player.frames[0].load("images/player.png");
	//set the anchor point to the bottom centre of the image
	player.frames[0].setAnchorPercent(.5, 1);
	
	// limits the keyboard inputs
	for (int i = 0; i < 255; i++) {
		keyDown[i] = false;
	}

	//sets the framerates of the program to 40 frames per second
	ofSetFrameRate(40);
}

//--------------------------------------------------------------
void ofApp::update(){
	//if the key press is the right arrow
	//move character forward
	if (keyDown[OF_KEY_RIGHT] == true) {
		physics.Forward(&player);
	}
	
	//if the key press is the left arrow
	//move character backwards
	if (keyDown[OF_KEY_LEFT] == true) {
		physics.Backwards(&player);
	}

	//if the key press is the spacebar & player jump is false
	//set jump to true
	//set the player's t value to 0
	//set the player's y0 value to the player's y value
	if (keyDown[OF_KEY_SPACE] == true && player.jump == false) {
		player.jump = true;
		player.t = 0;
		player.y0 = player.y;
	}

	//if the player's jump value is true
	//make the player jump
	if (player.jump == true) {
		physics.Jump(&player);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//draw background image
	bgImage.draw(0, 0);

	//draw player character
	render.Draw(&player);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//detects which key is pressed
	keyDown[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//detects when a key is released
	keyDown[key] = false;
}

