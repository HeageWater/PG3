#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

std::function<int()> Answer = []()
{
	int answer = 0;

	printf("����������P,����������Q����͂��Ă�������\n");

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
		printf("����\n");
	}
	else
	{
		printf("�s����\n");
	}
};

int main() 
{
	CheckAnswer(Answer(), 3);

	system("pause");

	return 0;
}