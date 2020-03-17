//Was included from the OfGameObject version 2
//Nothing was removed or added in this file
#include "Main.h"

GameObject::GameObject(){
	x = y = 0;
}

GameObject::~GameObject(){}

void GameObject::Draw(){
	img.draw(x, y);
}

ofImage* GameObject::GetImage(){
	return &img;
}