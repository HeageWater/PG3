#include "Scene.h"

Scene::Scene(const Scene& obj)
{
	//printf("%s���R�s�[���܂�",obj.name);
}

Scene* Scene::GetInstance()
{
	static Scene instance;

	return &instance;
}

void Scene::Update()
{

}
