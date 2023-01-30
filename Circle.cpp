#include "Circle.h"

Circle::Circle()
{
	r = 3;
	area = 0;
}

Circle::Circle(float r)
{
	this->r = r;
	area = 0;
}

void Circle::Size()
{
	area = r * r * 3.141519;
}

void Circle::Draw()
{
	printf("‰~‚Ì–ÊÏ‚Í%f‚Å‚·B\n", area);
}