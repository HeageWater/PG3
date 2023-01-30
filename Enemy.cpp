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
	printf("�ߐڃ��[�h\n");
}

void Enemy::Func2()
{
	printf("�ˌ����[�h\n");
}

void Enemy::Func3()
{
	printf("���E���[�h\n");
}

