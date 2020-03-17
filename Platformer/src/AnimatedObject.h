//Was included from the OfGameObject version 2
//Nothing was removed or added in this file
#pragma once
#define MAX_FRAMES 10

class AnimatedObject : 	public GameObject{
private:  //these cannot be changed directly from outside this class
	int currentFrame;
	int numFrames;

	//task: add data and code to control frame rate for animation

public:	//available outside

	//for simplicity, we have this as public
	//task: try and make it private
	ofImage frames[MAX_FRAMES];

	AnimatedObject();
	~AnimatedObject();

	//modified functions
	void Draw();
	ofImage* GetImage();

	//new functions
	//return a result
	bool Advance();
	bool SetNumFrames(int n);
};

