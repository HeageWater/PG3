#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<string> station = {
	"oosaki","gotanda","meguro","ebisu","sibuya",
	"harajuku","yoyogi","sinjuku","sinookubo","takadanobaba",
	"meziro","ikebukuro","ootuka","sugamo","komagome",
	"tabata","nisinippori","nippori","oukoku","ueno",
	"okatimati","akihabara","kanda","tokyo","yuurakutyou",
	"sinbasi","hamamatutyou","tamati","takanawagw-towei","sinagawa" };

	list<string>::iterator it;

	int check = 0;

	while (true)
	{
		printf("�ǂ̔N��̎R�����\�����܂����B\n");
		printf("��������͂��Ă��������B\n\n");
		printf("1.1970�N\n");
		printf("2.2019�N\n");
		printf("3.2022�N\n\n");

		scanf_s("%d", &check);

		if (check == 1)
		{
			printf("1970�N\n");
			printf("\n");

			for (auto itr = station.begin(); itr != station.end(); ++itr)
			{
				if (*itr == "nisinippori")
				{
					itr = station.erase(itr);
				}

				if (*itr == "takanawagw-towei")
				{
					itr = station.erase(itr);
				}

				std::cout << *itr << "\n";
			}

			printf("\n");
		}
		else if (check == 2)
		{
			printf("2019�N\n");
			printf("\n");

			for (auto itr = station.begin(); itr != station.end(); ++itr)
			{
				if (*itr == "tabata")
				{
					std::cout << *itr << "\n";
					itr++;
					if (*itr != "nisinippori")
					{
						itr = station.insert(itr, "nisinippori");
					}
				}

				if (*itr == "takanawagw-towei")
				{
					itr = station.erase(itr);
				}

				std::cout << *itr << "\n";
			}

			printf("\n");
		}
		else if (check == 3)
		{
			printf("2022�N\n");
			printf("\n");

			for (auto itr = station.begin(); itr != station.end(); ++itr)
			{
				if (*itr == "tabata")
				{
					std::cout << *itr << "\n";
					itr++;
					if (*itr != "nisinippori")
					{
						itr = station.insert(itr, "nisinippori");
					}
				}

				if (*itr == "tamati")
				{
					std::cout << *itr << "\n";
					itr++;
					if (*itr != "takanawagw-towei")
					{
						itr = station.insert(itr, "takanawagw-towei");
					}
				}

				std::cout << *itr << "\n";
			}

			printf("\n");
		}
	}

	system("pause");

	return 0;

}