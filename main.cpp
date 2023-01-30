#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

#include "Enemy.h"

int main() {

	Enemy* enemy1 = new Enemy;

	int phase_ = 0;
	static_cast<size_t>(phase_);

	while (true)
	{
		//printf("");

		enemy1->Update();
		enemy1->nowPhase_++;


	}


	system("pause");

	return 0;
}