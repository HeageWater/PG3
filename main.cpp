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

	while (true)
	{

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");

		if (house.size() != 0) {
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
		}

		//printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");

		printf("-----------\n");

		printf("�����I�����Ă�������\n");

		scanf_s("%d", &Check);

		if (Check == 1)
		{
			printf("\n[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n");
			printf("9.�v�쑀��ɂ��ǂ�\n\n");

			printf("�����I�����Ă�������\n");

			scanf_s("%d", &Check);

			if (Check == 1)
			{
				int a = 0;
				printf("\n�v�f�ꗗ:{\n");
				for (auto itr = house.begin(); itr != house.end(); ++itr)
				{
					printf("%d:", a);

					a++;

					std::cout << *itr << "\n";
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

					if (i = Check - 1)
						printf("\n%d:", i);
				}

				std::cout << *itr << "\n";

			}
			else if (Check == 9)
			{
				printf("\n");
				continue;
			}
		}
		else if (Check == 2)
		{
			int bangou = -1;

			auto itr = house.begin();

			printf("[���X�g�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ��999����͂��Ă�������\n");

			scanf_s("%d", &bangou);

			if (bangou == 999) {
				//house.push_back((string)bangou);
			}
			else if (bangou > house.size())
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

				//itr = house.insert(itr, Check);

				printf("�v�f%d��%d�Ԗڂɑ}������܂���\n", Check, bangou);
			}
		}
		else if (Check == 3 && house.size() != 0)
		{
			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");

			scanf_s("%d", &Check);

			/*for (auto itr = house.begin(); itr != house.end(); ++itr)
			{
				it = itr;
				if (itr == Check)
				{
					int Chenge = 0;

					printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", Check);

					scanf_s("%d", &Chenge);

					replace(house.begin(),house.end(),Check, Chenge);

					printf("%d�Ԗڂ̗v�f�̒l��%d�ɕύX����܂����B\n", Check,Chenge);

					continue;
				}
			}*/

			printf("%d�Ԗڂ̗v�f��������܂���ł����B\n\n",Check);
		}
		else if (Check == 4 && house.size() != 0)
		{
			printf("[�v�f�̍폜]\n");
			printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");

			scanf_s("%d", &Check);

			/*for (auto itr = house.begin(); itr != house.end(); ++itr)
			{
				it = itr;
				if (itr == Check)
				{
					int Chenge = 0;

					printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", Check);

					scanf_s("%d", &Chenge);

					replace(house.begin(),house.end(),Check, Chenge);

					printf("%d�Ԗڂ̗v�f�̒l��%d�ɕύX����܂����B\n", Check,Chenge);

					continue;
				}
			}*/

			printf("%d�Ԗڂ̗v�f��������܂���ł����B\n\n", Check);
		}
	}

	system("pause");

	return 0;

}