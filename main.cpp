#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <functional>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

#include "Scene.h"

int main() {

	Scene* scene = Scene::GetInstance();

	while (true) {

		scene->ChangeScene();

		printf("SceneNum: %d",scene->nowScene);
		//printf("SceneNum: %d",scene->nowScene);

		scene->nowScene++;

		printf("‚È‚É‚©“ü—Í‚µ‚ÄŽŸ‚Ö\n");

		int flag;

		flag = getchar();
	}

	system("pause");

	return 0;
}