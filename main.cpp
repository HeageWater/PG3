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

int Enemy::EnemyCount;

int main() {
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;

	int selectDeathEnemy;

	if (Enemy::EnemyCount != 0)
	{
		printf("enemy‚Í%d‘Ì¶‚«‚Ä‚Ü‚·\n", Enemy::EnemyCount);
	}

	printf("1~3‚Ì”š‚ğ‰Ÿ‚·‚ÆEnemy‚ªÁ‚¦‚Ü‚·B\n");

	scanf_s("%d", &selectDeathEnemy);

	if (selectDeathEnemy == 1)
		delete enemy1;

	if (selectDeathEnemy == 2)
		delete enemy2;

	if (selectDeathEnemy == 3)
		delete enemy3;

	printf("enemy‚Í%d‘Ì¶‚«‚Ä‚Ü‚·\n", Enemy::EnemyCount);

	system("pause");

	return 0;
}