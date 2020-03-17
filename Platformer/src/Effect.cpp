#include "Main.h"



Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::Apply(ofImage backgrnd, ofImage player)
{
	ofPixels pixels = img->getPixels();
	int w = img->getWidth();
	int h = img->getHeight();
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
		{
			ofColor c = pixels.getColor(i, j);
			c.r = c.b = 0;
			pixels.setColor(i, j, c);
		}
	img->setFromPixels(pixels);
}