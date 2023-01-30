#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

#include "Circle.h"
#include "RectAngle.h"

int main() {

	Circle* circle = new Circle();
	RectAngle* rectangle = new RectAngle();

	circle->Size();
	circle->Draw();

	rectangle->Size();
	rectangle->Draw();

	system("pause");

	return 0;
}