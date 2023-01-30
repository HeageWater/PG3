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

	while (true)
	{
		printf("Enter‚ÅŸ‚Ö\n");
		int flag;
		flag = getchar();

		enemy1->Update();
		enemy1->PlusNowPhase();

		if (enemy1->GetNowPhase() > 2)
		{
			printf("I—¹\n");
			break;
		}
	}


	system("pause");

	return 0;
}