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
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");

			if (house.size() != 0) {
				printf("3.�v�f�̕ҏW\n");
				printf("4.�v�f�̍폜\n");
			}

			printf("-----------\n");

			printf("�����I�����Ă�������\n");

			scanf_s("%d", &Check);
		}
		else if (Check == 1)
		{
			printf("\n[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n");
			printf("9.�v�쑀��ɂ��ǂ�\n\n");

			printf("�����I�����Ă�������\n");

			scanf_s("%d", &Mode);

			if (Mode == 1)
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
			}
			else if (Mode == 2)
			{
				printf("���Ԃ��w�肵�ėv�f��\��\n\n");

				printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");

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

			printf("1.�v�f�̕\���ɖ߂�\n");
			printf("2.�v�f�̑���ɖ߂�\n");

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

			printf("[���X�g�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ��999����͂��Ă�������\n");

			scanf_s("%d", &bangou);

			if (bangou == 999) {

				printf("�ǉ�����v�f�̒l����͂��Ă�������\n");

				scanf_s("%d", &bangou);

				house.push_back(bangou);

				printf("�v�f%d���Ō���ɑ}������܂���\n\n", bangou);
			}
			else if (bangou > house.size())
			{
				printf("�v�f�����������܂��B\n");
			}
			else {
				printf("�ǉ�����v�f�̒l����͂��Ă�������\n");

				scanf_s("%d", &Mode);

				for (int i = 1; i < bangou; i++)
				{
					itr++;
				}

				itr = house.insert(itr, Mode);

				printf("�v�f%d��%d�Ԗڂɑ}������܂���\n\n", Mode, bangou);
			}
		}
		else if (Check == 3 && house.size() != 0)
		{
			Check = 0;
			it = house.begin();

			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");

			scanf_s("%d", &Mode);

			if (Mode > house.size())
			{
				printf("%d�Ԗڂ̗v�f��������܂���ł����B\n\n", Mode);
			}
			else
			{
				for (int i = 0; i < Mode; i++)
				{
					it++;
				}

				int Chenge = 0;

				printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", Mode);

				scanf_s("%d", &Chenge);

				replace(house.begin(), house.end(), *it, Chenge);

				printf("%d�Ԗڂ̗v�f�̒l��%d�ɕύX����܂����B\n", Mode, Chenge);

				continue;

			}
		}
		else if (Check == 4 && house.size() != 0)
		{
			Check = 0;
			it = house.begin();

			printf("[�v�f�̍폜]\n");
			printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");

			scanf_s("%d", &Mode);

			if (Mode > house.size())
			{
				printf("%d�Ԗڂ̗v�f��������܂���ł����B\n\n", Mode);
			}
			else
			{
				for (int i = 0; i < Mode; i++)
				{
					it++;
				}

				printf("%d�Ԗڂ̗v�f%d���폜���܂����B\n", Mode,*it);

				house.erase(it);

				continue;

			}
		}
	}

	system("pause");

	return 0;

}