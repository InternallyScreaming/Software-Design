#pragma once

class ofApp : public ofBaseApp{

	public:
		ofImage bgImage;		//background image
		AnimatedObject player;	//player character

		Render render;			//image renderer
		Physic physics;			//physics engine
		bool keyDown[255];		//all keys 

		void setup();		
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);		
};
