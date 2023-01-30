#include "RectAngle.h"

RectAngle::RectAngle()
{
	width = 4;
	height = 3;
	area = 0;
}

RectAngle::RectAngle(int width, int height)
{
	this->width = width;
	this->height = height;
	area = 0;
}

void RectAngle::Size()
{
	area = width * height;
}

void RectAngle::Draw()
{
	printf("lŠpŒ`‚Ì–ÊÏ‚Í%d‚Å‚·B\n", area);
}
