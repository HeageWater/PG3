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
	
	cout << Enemy::EnemyCount << endl;

	delete enemy1;

	cout << Enemy::EnemyCount << endl;
	delete enemy2;
	delete enemy3;
	cout << Enemy::EnemyCount << endl;


	system("pause");

	return 0;
}