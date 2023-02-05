#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

typedef int (*PFunc)();

int Answer()
{
	int answer = 0;

	printf("����������P,����������Q����͂��Ă�������\n");

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
		printf("����\n");
	}
	else
	{
		printf("�s����\n");
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