#pragma once
#include "IShape.h"

class Circle : public IShape
{
public:
	Circle();
	Circle(float r);
	void Size() override;
	void Draw() override;

	float r;

	float area;
};