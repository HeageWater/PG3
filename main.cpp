#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

int main() {

	auto TimeCount = [](int i)
	{
		Sleep(i);
	};

	auto Check = [=](int random, int count)
		//std::function<int(int)>  Check = [=](int random, int count)
	{
		TimeCount(count);

		if (random % 2 == 1)
		{
			printf("����\n");
		}

		if (random % 2 == 0)
		{
			printf("�s����\n");
		}

		return 0;
	};

	void(*waittime)();

	srand(time(NULL));

	int random = rand() % 6 + 1;

	int answer = 0;

	int count = 3000;

	printf("����������P,����������Q����͂��Ă�������\n");

	scanf_s("%d", &answer);

	answer = Check(random, count);

	printf("%d\n", random % 2 + 1);

	system("pause");

	return 0;
}