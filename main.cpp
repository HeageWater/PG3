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

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");

		if (house.size() != 0) {
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
		}

		printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");

		printf("-----------\n");

		printf("�����I�����Ă�������\n");

		scanf_s("%d", &Check);

		if (Check == 1)
		{

			printf("\n[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n\n");

			printf("�����I�����Ă�������\n");

			scanf_s("%d", &Check);

			if (Check == 1)
			{
				printf("�v�f�ꗗ:{\n");
				for (auto itr = house.begin(); itr != house.end(); ++itr)
				{
					//it = house[i];

					//printf("%d", itr);
					std::cout << *itr << "\n";

					//printf("%d:%d",i,house.[i]);
				}

				printf("}\n\n");

				printf("�v�f��:%d\n", (int)house.size());

				printf("\n-----\n");
			}
			else if (Check == 2)
			{
				printf("���Ԃ��w�肵�ėv�f��\��\n\n");

				printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");

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
			int bangou = -1;

			auto itr = house.begin();

			printf("[���X�g�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł�������\n");

			scanf_s("%d", &bangou);

			/*if (!isdigit(bangou)) {
				bangou = house.size();
			}*/

			if (bangou> house.size())
			{
				printf("�v�f�����������܂��B\n");
			}
			else {
				printf("�ǉ�����v�f�̒l����͂��Ă�������\n");

				scanf_s("%d", &Check);


				for (int i = 1; i < bangou; i++)
				{
					itr++;
				}

				itr = house.insert(itr, Check);

				printf("�v�f%d��%d�Ԗڂɑ}������܂���\n", Check, bangou);
			}
		}
		else if (Check == 3)
		{
			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");

		}
	}

	system("pause");

	return 0;

}