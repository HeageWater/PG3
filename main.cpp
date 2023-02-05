#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

typedef int (*PFunc)();

int Answer()
{
	int answer = 0;

	printf("半だったら１,丁だったら２を入力してください\n");

	scanf_s("%d", &answer);

	return answer;
};

void CheckAnswer(PFunc p, int count)
{
	int random = p();

	srand(time(NULL));

	int result = rand() % 6 + 1;

	Sleep(count * 1000);

	if (result % 2 == random)
	{
		printf("正解\n");
	}
	else
	{
		printf("不正解\n");
	}
};

int main()
{
	PFunc p;

	p = Answer;

	CheckAnswer(p, 3);

	system("pause");

	return 0;
}