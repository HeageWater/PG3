#pragma once
#include "IShape.h"

class RectAngle : public IShape
{
public:
	RectAngle();
	RectAngle(int width, int height);
	void Size() override;
	void Draw() override;

	int width;
	int height;

	int area;
};