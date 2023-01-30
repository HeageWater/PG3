#pragma once
#include "stdio.h"
#include "stdlib.h"

class Enemy {
protected:
public:
	static int EnemyCount;
	Enemy() { };
	~Enemy() {  };

	void Update();

	//‹ßÚ
	void NearAttack();

	//ËŒ‚
	void Shoot();

	//—£’E
	void Escape();

	static void (Enemy::* phaseTable[])();
	void PlusNowPhase() { nowPhase_++; };
	int GetNowPhase() { return nowPhase_; };

private:
	int nowPhase_ = 0;
};
