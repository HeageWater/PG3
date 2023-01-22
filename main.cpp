#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

int main() {

	std::function<int(int)> Check = [=](int random) {
		if (random % 2 == 1) {
			return 1;
		}

		if (random % 2 == 0) {
			return 2;
		}

		return 0; };

	auto TimeCount = [](int i) {
		Sleep(i);
	};

	void(*waittime)();

	srand(time(NULL));

	int random = rand() % 6 + 1;

	int ansewr = 0;;

	printf("”¼‚¾‚Á‚½‚ç‚P,’š‚¾‚Á‚½‚ç‚Q‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

	scanf_s("%d", &ansewr);

	TimeCount(3000);

	if (ansewr == Check(random)) {
		printf("³‰ğ\n");
	}
	else {
		printf("•s³‰ğ\n");
	}

	printf("%d\n", random);

	system("pause");

	return 0;
}