#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

typedef int (*PFunc)();

int Answer()
{
	int answer = 0;

	printf("”¼‚¾‚Á‚½‚ç‚P,’š‚¾‚Á‚½‚ç‚Q‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

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
		printf("³‰ğ\n");
	}
	else
	{
		printf("•s³‰ğ\n");
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