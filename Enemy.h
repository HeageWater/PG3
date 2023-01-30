#pragma once
#include "stdio.h"
#include "stdlib.h"

class Enemy {
protected:
public:
	static int EnemyCount;
	Enemy() { EnemyCount++; };
	~Enemy() { EnemyCount = 0; };

	void Update();

	//‹ßÚ
	void Func1();

	//ËŒ‚
	void Func2();

	//—£’E
	void Func3();

	static void (Enemy::*spFuncTable[])();

	int nowPhase_ = 0;
};
