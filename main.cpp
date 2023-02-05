#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

int main() {

	std::function<void(int)> TimeCount = [](int count)
	{
		Sleep(count);
	};

	auto Check = [=](int random, int count)
	{
		TimeCount(count);

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

	void(*waittime)();

	srand(time(NULL));

	int random = rand() % 6 + 1;

	int answer = 0;

	int count = 3000;

	printf("半だったら１,丁だったら２を入力してください\n");

	scanf_s("%d", &answer);

	answer = Check(random, count);

	system("pause");

	return 0;
}