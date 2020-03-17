//Was included from the OfGameObject version 2
//Nothing was removed or added in this file
#include "Main.h"

Render::Render(){}
Render::~Render(){}

void Render::Draw(GameObject* obj){
	obj->GetImage()->draw(obj->x, obj->y);
}