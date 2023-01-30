#pragma once

#include "stdio.h"
#include "stdlib.h"

class IShape
{
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
};