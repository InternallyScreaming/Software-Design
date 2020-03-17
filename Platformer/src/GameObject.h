//Was included from the OfGameObject version 2
#pragma once


class GameObject{
protected:	//make img protected so child classes can use it
	ofImage img;
public:
	int x;
	int y;
	//Added from the Assignment 03.docx
	bool jump;
	int y0;
	int t;

	GameObject();
	~GameObject();

	//virtual functions are expected to be modified by child class
	//any call will result in child class to be executed
	virtual void Draw();
	virtual ofImage* GetImage();
};

