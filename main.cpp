#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

int main() {

	std::function<int(int)> Check = [&](int random)
	{
		if (random % 2 == 1)
		{
			printf("正解\n");
		}

		if (random % 2 == 0)
		{
			printf("不正解\n");
		}

		return 0;
	};

	auto TimeCount = [](int i)
	{
		Sleep(i);
	};

	void(*waittime)();

	srand(time(NULL));

	int random = rand() % 6 + 1;

	int ansewr = 0;;

	printf("半だったら１,丁だったら２を入力してください\n");

	scanf_s("%d", &ansewr);

	TimeCount(3000);

	ansewr == Check(random);

	system("pause");

	return 0;
}