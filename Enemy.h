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

	//�ߐ�
	void Func1();

	//�ˌ�
	void Func2();

	//���E
	void Func3();

	static void (Enemy::*spFuncTable[])();

	int nowPhase_ = 0;
};
