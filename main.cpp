#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main() {

	list<int> house = { 1,2,3 };
	list<int>::iterator it;

	int Check = 0;
	int Mode = 0;

	while (true)
	{
		if (Check == 0)
		{
			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");

			if (house.size() != 0) {
				printf("3.要素の編集\n");
				printf("4.要素の削除\n");
			}

			printf("-----------\n");

			printf("操作を選択してください\n");

			scanf_s("%d", &Check);
		}
		else if (Check == 1)
		{
			printf("\n[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.順番を指定して要素を表示\n");
			printf("9.要作操作にもどる\n\n");

			printf("操作を選択してください\n");

			scanf_s("%d", &Mode);

			if (Mode == 1)
			{
				int a = 0;
				printf("\n要素一覧:{\n");
				for (auto itr = house.begin(); itr != house.end(); ++itr)
				{
					printf("%d:", a);

					a++;

					std::cout << *itr << "\n";
				}

				printf("}\n\n");

				printf("要素数:%d\n", (int)house.size());
			}
			else if (Mode == 2)
			{
				printf("順番を指定して要素を表示\n\n");

				printf("表示したい要素の順番を指定してください。\n");

				scanf_s("%d", &Mode);

				auto itr = house.begin();

				for (int i = 1; i < Mode; i++)
				{
					itr++;

					if (i = Mode - 1)
						printf("\n%d:", i);
				}

				std::cout << *itr << "\n";
			}
			else if (Mode == 9)
			{
				printf("\n");
				continue;
			}

			printf("\n-----\n");

			printf("1.要素の表示に戻る\n");
			printf("2.要素の操作に戻る\n");

			scanf_s("%d", &Check);

			if (Check == 2)
			{
				Check = 0;
			}
		}
		else if (Check == 2)
		{
			Check = 0;
			int bangou = -1;

			auto itr = house.begin();

			printf("[リスト要素の挿入]\n");
			printf("要素を追加する場所を指定してください。最後尾に追加する場合は999を入力してください\n");

			scanf_s("%d", &bangou);

			if (bangou == 999) {

				printf("追加する要素の値を入力してください\n");

				scanf_s("%d", &bangou);

				house.push_back(bangou);

				printf("要素%dが最後尾に挿入されました\n\n", bangou);
			}
			else if (bangou > house.size())
			{
				printf("要素数が多すぎます。\n");
			}
			else {
				printf("追加する要素の値を入力してください\n");

				scanf_s("%d", &Mode);

				for (int i = 1; i < bangou; i++)
				{
					itr++;
				}

				itr = house.insert(itr, Mode);

				printf("要素%dが%d番目に挿入されました\n\n", Mode, bangou);
			}
		}
		else if (Check == 3 && house.size() != 0)
		{
			Check = 0;
			it = house.begin();

			printf("[要素の編集]\n");
			printf("編集したい要素の番号を指定してください。\n");

			scanf_s("%d", &Mode);

			if (Mode > house.size())
			{
				printf("%d番目の要素が見つかりませんでした。\n\n", Mode);
			}
			else
			{
				for (int i = 0; i < Mode; i++)
				{
					it++;
				}

				int Chenge = 0;

				printf("%d番目の要素の変更する値を入力してください。\n", Mode);

				scanf_s("%d", &Chenge);

				replace(house.begin(), house.end(), *it, Chenge);

				printf("%d番目の要素の値が%dに変更されました。\n", Mode, Chenge);

				continue;

			}
		}
		else if (Check == 4 && house.size() != 0)
		{
			Check = 0;
			it = house.begin();

			printf("[要素の削除]\n");
			printf("削除したい要素の番号を指定してください。\n");

			scanf_s("%d", &Mode);

			if (Mode > house.size())
			{
				printf("%d番目の要素が見つかりませんでした。\n\n", Mode);
			}
			else
			{
				for (int i = 0; i < Mode; i++)
				{
					it++;
				}

				printf("%d番目の要素%dを削除しました。\n", Mode,*it);

				house.erase(it);

				continue;

			}
		}
	}

	system("pause");

	return 0;

}