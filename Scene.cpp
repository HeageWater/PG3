#include "Scene.h"

Scene::Scene(const Scene& obj)
{
	//printf("%sをコピーします",obj.name);
}

Scene* Scene::GetInstance()
{
	static Scene instance;

	return &instance;
}

void Scene::Update()
{

}
