#include "Enemy.h"

void(Enemy::* Enemy::phaseTable[])() =
{
	&Enemy::NearAttack,
	&Enemy::Shoot,
	&Enemy::Escape,
};

void Enemy::Update()
{
	static_cast<size_t>(nowPhase_);

	if (nowPhase_ >= 0 && nowPhase_ < 3)
	{
		(this->*phaseTable[nowPhase_])();
	}
}

void Enemy::NearAttack()
{
	printf("近接モード\n");
}

void Enemy::Shoot()
{
	printf("射撃モード\n");
}

void Enemy::Escape()
{
	printf("離脱モード\n");
}

