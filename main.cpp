#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>
#include <list>
#include <iostream>
using namespace std;

int main() {

	std::list<int> house = { 21,52,43 };
	std::list<int>::iterator it;

	int Check = 0;

	while (true)
	{

		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");

		if (house.size() != 0) {
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
		}

		printf("5.要素の並び替え(オプション)\n");

		printf("-----------\n");

		printf("操作を選択してください\n");

		scanf_s("%d", &Check);

		if (Check == 1)
		{

			printf("\n[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.順番を指定して要素を表示\n\n");

			printf("操作を選択してください\n");

			scanf_s("%d", &Check);

			if (Check == 1)
			{

				printf("要素一覧:{\n");
				for (auto itr = house.begin(); itr != house.end(); ++itr)
				{
					//it = house[i];

					//printf("%d", itr);
					std::cout << *itr << "\n";

					//printf("%d:%d",i,house.[i]);
				}

				printf("}\n\n");

				printf("要素数:%d\n", (int)house.size());

				printf("\n-----\n");
			}
			else if (Check == 2)
			{
				printf("順番を指定して要素を表示\n\n");

				printf("表示したい要素の順番を指定してください。\n");

				scanf_s("%d", &Check);

				auto itr = house.begin();

				for (int i = 1; i < Check; i++)
				{
					itr++;
				}

				std::cout << *itr << "\n";

			}
		}
		else if (Check == 2)
		{
			for (auto itr = house.begin(); itr != house.end(); ++itr)
			{
				//it = house[i];

				std::cout << *itr << "\n";

				//printf("%d:%d",i,house.[i]);
			}
		}

	}

	system("pause");

	return 0;

}