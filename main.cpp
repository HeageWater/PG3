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

	while () {

		scene->Update();

	}

	system("pause");

	return 0;

}