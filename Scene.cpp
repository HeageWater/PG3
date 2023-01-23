#include "Scene.h"

Scene::~Scene()
{
}

Scene::Scene()
{
	nowScene = 0;
}

Scene* Scene::GetInstance()
{
	static Scene instance;

	return &instance;
}

void Scene::ChangeScene(int nextScene)
{
	nowScene = nextScene;
}
