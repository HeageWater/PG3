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

	int sceneNo = 0;

	while (true) {

		sceneNo++;
		if (sceneNo == 4)sceneNo = 0;

		scene->ChangeScene(sceneNo);

		printf("SceneNum: %d\n",scene->GetnowScene());

		printf("ENTER‚ÅŽŸ‚Ö\n");

		int flag;

		flag = getchar();
	}

	system("pause");

	return 0;
}