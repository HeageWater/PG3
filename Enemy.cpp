#include "Enemy.h"

void(Enemy::* Enemy::spFuncTable[])() =
{
	&Enemy::Func1,
	&Enemy::Func2,
};

void Enemy::Update()
{
	static_cast<size_t>(nowPhase_);

	if (nowPhase_ >= 0 && nowPhase_ < 3)
		(this->*spFuncTable[nowPhase_])();
}

void Enemy::Func1()
{
	printf("近接モード\n");
}

void Enemy::Func2()
{
	printf("射撃モード\n");
}

void Enemy::Func3()
{
	printf("離脱モード\n");
}

