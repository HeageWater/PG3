#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>

int main() {

	int a = 0;

	while (true) {

		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");

		if (false) {
			printf("3.[要素の編集\n");
			printf("4.要素の削除\n");
		}

		printf("5.要素の並び替え(オプション)\n");

		printf("-----------\n");

		printf("操作を選択してください\n");

		scanf_s("%d\n",&a);
	}

	system("pause");

	return 0;
}