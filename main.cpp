#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

int main() {

	int a = 0;

	while (true) {

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");

		if (false) {
			printf("3.[�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
		}

		printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");

		printf("-----------\n");

		printf("�����I�����Ă�������\n");

		scanf_s("%d\n",&a);
	}

	system("pause");

	return 0;
}