#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

std::function<int()> Answer = []()
{
	int answer = 0;

	printf("半だったら１,丁だったら２を入力してください\n");

	scanf_s("%d", &answer);

	return answer;
};

std::function<void(int, int)>  CheckAnswer = [](int random, int count)
{
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
	CheckAnswer(Answer(), 3);

	system("pause");

	return 0;
}