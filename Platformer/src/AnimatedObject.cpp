//Was included from the OfGameObject version 2
//Nothing was removed or added in this file
#include "Main.h"

AnimatedObject::AnimatedObject(){
	numFrames = 0;
	currentFrame = -1; //no valid frame
}

AnimatedObject::~AnimatedObject(){}

//these functions allow access to private data
//Set functions allow (1) checking valid values, (2) doing other things when data changes
//they can return a value to show if set was successful
bool AnimatedObject::Advance(){
	bool result = false;

	if (numFrames > 0){
		currentFrame++;
		if (currentFrame >= numFrames)
			currentFrame = 0;
		result = true;
	}

	return result;
}
bool AnimatedObject::SetNumFrames(int n){
	bool result = false;

	if (n >= 0){
		numFrames = n;
		if (n > 0)
			currentFrame = 0;
		else
			currentFrame = -1;

		result = true;
	}
	return result;
}


//these functions are modified from the base version to manage animation
void AnimatedObject::Draw(){
	if (currentFrame >= 0)
		frames[currentFrame].draw(x, y);
	else
		img.draw(x, y);	//no frames, so use the single image from GameObject
}
ofImage* AnimatedObject::GetImage(){
	if (currentFrame >= 0)
		return &(frames[currentFrame]);
	else
		return &img;

}