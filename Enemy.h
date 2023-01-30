#pragma once

class Enemy {
protected:
public:
	static int EnemyCount;
	Enemy() { EnemyCount++; };
	~Enemy() { EnemyCount = 0; };
};
